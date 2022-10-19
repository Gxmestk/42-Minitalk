# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 23:33:05 by tkhemniw          #+#    #+#              #
#    Updated: 2022/09/10 14:14:31 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#$(shell find . -name '*.c')
SRCS :=  		ft_memset_last.c 	\
				ft_strchr.c 		\
				ft_sort_max_three.c \
				ft_isdigit.c 		\
				ft_strupper.c		\
				ft_strlen.c 		\
				ft_strlcpy.c 		\

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) 
fclean: clean	
	rm -f $(NAME)
re: fclean all