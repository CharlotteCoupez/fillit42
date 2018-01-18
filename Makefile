# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuber <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 15:08:15 by dhuber            #+#    #+#              #
#    Updated: 2017/12/07 07:17:16 by dhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c ft_get_file.c ft_checking_file.c ft_split_tetri.c ft_get_point.c \
	   ft_new_point.c ft_get_square.c can_fit.c create_map.c
LIB = Libft/
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	make re -C $(LIB)
	gcc $(FLAGS) -c $(SRCS) 
	gcc $(FLAGS) -o $(NAME) $(OBJS) Libft/libft.a

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
