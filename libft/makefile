# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarnere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:15:33 by mcarnere          #+#    #+#              #
#    Updated: 2024/03/14 12:15:35 by mcarnere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FIXME: cambiar para la librería
SRC	= main.c sort_utils.c dictionary_data_read.c dictionary_read.c \
	int_utils.c map_data.c print_numbers.c str_utils.c translator.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all : $(NAME) 

$(NAME) : $(OBJ)
	ar -rcs $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	-rm -f $(OBJ) 

fclean:	clean
	-rm -f $(NAME) 

re: fclean all

.PHONY:	all clean fclean re