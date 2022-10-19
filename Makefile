# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:32:12 by tkhemniw          #+#    #+#              #
#    Updated: 2022/10/19 20:59:36 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
SVR_NAME	= server
CNT_NAME	= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f

SRCS_DIR	= ./srcs
INCS_DIR	= ./includes
PRINTF_DIR	= ./libs/ft_printf

INCLUDES	= -I $(INCS_DIR) \
			  -I $(PRINTF_DIR)/includes

LIBS		= -L $(PRINTF_DIR) -lftprintf

SVR_SRCS	= $(SRCS_DIR)/server.c \
			  $(UTILS_SRCS)
CNT_SRCS	= $(SRCS_DIR)/client.c \
			  $(UTILS_SRCS)
UTILS_SRCS	= $(SRCS_DIR)/utils.c

SVR_OBJS 	= $(SVR_SRCS:%.c=%.o)
CNT_OBJS 	= $(CNT_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): server client


libs:
	make -C $(PRINTF_DIR)

server: $(SVR_OBJS) libs
	$(CC) $(CFLAGS) $(SVR_OBJS) $(LIBS) -o $(SVR_NAME)

client: $(CNT_OBJS) libs
	$(CC) $(CFLAGS) $(CNT_OBJS) $(LIBS) -o $(CNT_NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -c

clean:
	make clean -C $(PRINTF_DIR)
	$(RM) -r $(SVR_OBJS) $(CNT_OBJS)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	$(RM) $(SVR_NAME)
	$(RM) $(CNT_NAME)
re: fclean all

bonus: all

rebonus: fclean bonus

test: re
	valgrind -q --leak-check=full --track-origins=yes ./$(CNT_NAME) $(pid) "$(text)"

norm:
	clear && norminette
normh:
	clear &&norminette -R CheckHeader 
normf:
	clear && norminette -R CheckForbiddenSourceHeader
	
.PHONY: all clean fclean re libs server client