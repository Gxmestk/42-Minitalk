/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:32:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/19 20:26:49 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_response;

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	byte;
	static int	i;

	(void)context;
	if (signum == SIGUSR2)
		byte |= (1 << i);
	i++;
	if (i == 8)
	{
		if (byte == 0)
			write(1, &"\n", 1);
		else
			write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
	g_response = 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf("Error setting the signal disposition in Server\n");
		return (0);
	}
	ft_printf("Server started successfully\n");
	ft_printf("Server PID is: %i\nWaiting for client . . . \n", getpid());
	while (1)
	{
		while (g_response != 1)
			;
		g_response = 0;
	}
	return (0);
}
