# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:15:33 by mcarnere          #+#    #+#              #
#    Updated: 2024/03/19 20:08:40 by mcarnere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BONUS_NAME = .bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_itoa.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BONUS = 

BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	ar -rcs $(CFLAGS) -o $(NAME) $(OBJ)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ) $(BONUS_OBJ)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	ar -rcs $(BONUS_NAME) $(OBJ) $(BONUS_OBJ)

clean :
	-rm -f $(OBJ) 

fclean:	clean
	-rm -f $(NAME) 

re: fclean all

.PHONY:	all bonus clean fclean re