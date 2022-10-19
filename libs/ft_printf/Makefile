# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 23:14:19 by tkhemniw          #+#    #+#              #
#    Updated: 2022/10/19 21:16:46 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= ./srcs
SRCS		= $(SRC_DIR)/ft_printf.c 						\
			  $(SRC_DIR)/check_format.c 					\
			  $(SRC_DIR)/check_flag.c 						\
			  $(SRC_DIR)/check_length_modifier.c 			\
			  $(SRC_DIR)/check_conversion_specifier.c 		\
			  $(SRC_DIR)/check_min_width.c 					\
			  $(SRC_DIR)/check_precision.c 					\
			  $(SRC_DIR)/print_u.c 							\
			  $(SRC_DIR)/print_s.c 							\
			  $(SRC_DIR)/print_p.c 							\
			  $(SRC_DIR)/print_d.c 							\
			  $(SRC_DIR)/print_c.c 							\
			  $(SRC_DIR)/print_x.c 							\
			  $(SRC_DIR)/print_by_format.c 					\
			  $(SRC_DIR)/add_int_prefix.c 					\
			  $(SRC_DIR)/add_int_content.c 					\
			  $(SRC_DIR)/print_wdt.c 						\
			  $(SRC_DIR)/reset_format.c 					\
			  $(SRC_DIR)/zero_abs_itoa.c 					\
			  $(SRC_DIR)/add_hex_content.c 					\
			  $(SRC_DIR)/add_hex_prefix.c 					\
			  $(SRC_DIR)/zero_abs_htoa.c 					\
			  $(SRC_DIR)/add_addr_prefix.c					\
			  $(SRC_DIR)/add_addr_content.c					\
			  $(SRC_DIR)/zero_abs_ptoa.c 					\
			  $(SRC_DIR)/add_char_content.c 				\
			  $(SRC_DIR)/add_str_content.c 					\

OBJS 		= $(SRCS:.c=.o)

RM			= /bin/rm -f

all:		$(NAME)

$(NAME): $(OBJS) $(LIBFT)
			ar -rc $(NAME) $(OBJS)

.c.o: 		
			gcc -Wall -Wextra -Werror -I $(INCS_DIR) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

bonus:		all

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re rebonu