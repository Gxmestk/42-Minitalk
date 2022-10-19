/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:32:06 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/19 20:31:28 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_bitcount;
static volatile sig_atomic_t	g_response;

static void	send_byte(int spid, int c)
{
	int	bc;

	bc = 0;
	while (bc < 8)
	{	
		if ((c >> bc) & 1)
			kill(spid, SIGUSR2);
		else
			kill(spid, SIGUSR1);
		if (errno == EINVAL)
		{
			ft_printf("An invalid signal was specified.\n");
			exit(1);
		}
		bc++;
		while (g_response != 1)
			;
		g_response = 0;
	}
}

static void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signo;
	if (signo == SIGUSR1)
		g_bitcount++;
	g_response = 1;
}

static int	error(pid_t spid)
{
	kill(spid, 0);
	if (spid == 0 || kill(spid, 0) == -1)
	{
		if (errno == EPERM)
		{
			ft_printf("Error: The calling process does");
			ft_printf(" not have permission to send the signal to");
			ft_printf(" any of the target processes.\n");
		}
		else if (errno == ESRCH)
		{
			ft_printf("Error: The target process or process");
			ft_printf(" group does not exist.\n");
		}
		else
			ft_printf("Error: Invalid process ID.\n");
		return (1);
	}
	return (0);
}

static int	sigaction_setup(struct sigaction *act, pid_t *spid, char *argv1)
{
	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = &handler;
	sigemptyset(&act->sa_mask);
	if (sigaction(SIGUSR1, act, NULL) == -1
		|| sigaction(SIGUSR2, act, NULL) == -1)
	{
		ft_printf("Error setting the signal disposition in Client\n");
		return (1);
	}
	*spid = ft_atoi(argv1);
	if (error(*spid))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				spid;
	int					i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("2 arguments must be passed: PID and message\n");
		return (0);
	}
	if (sigaction_setup(&act, &spid, argv[1]))
		return (0);
	ft_printf("Client PID is: %d\n", getpid());
	ft_printf("Server PID is: %d\n", spid);
	while (argv[2][i] != '\0')
		send_byte(spid, argv[2][i++]);
	send_byte(spid, argv[2][i++]);
	if (g_bitcount > 0)
		ft_printf("Successfully receive the inforamtion.\n");
	return (0);
}
