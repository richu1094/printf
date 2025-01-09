# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 16:19:14 by rcenteno          #+#    #+#              #
#    Updated: 2025/01/09 16:30:56 by rcenteno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_print_char.c\
      	  ft_print_hex.c ft_print_int.c\
      	  ft_print_ptr.c ft_print_str.c\
      	  ft_print_unsigned.c ft_strlen.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

FLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all:  $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all