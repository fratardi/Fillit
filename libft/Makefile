# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fratardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 17:27:11 by fratardi          #+#    #+#              #
#    Updated: 2019/01/03 15:25:03 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC =	ft_itoa.c ft_strnlen.c ft_strndup.c ft_swap.c ft_lstmap.c \
		ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		ft_lstnew.c ft_memset.c ft_putstr_fd.c ft_print_table.c \
		ft_isspace.c ft_strequ.c ft_strncat.c ft_strsplit.c ft_atoi.c \
		ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strstr.c \
		ft_bzero.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
		ft_strncmp.c ft_strsub.c ft_isalnum.c ft_memchr.c ft_putendl.c \
		ft_strclr.c ft_strjoin.c ft_strncpy.c ft_strtrim.c ft_isalpha.c \
		ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnequ.c \
		ft_tolower.c ft_isascii.c ft_memcpy.c ft_putnbr.c ft_strcpy.c \
		ft_strlen.c ft_strnew.c ft_toupper.c ft_isdigit.c ft_memdel.c \
		ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strnstr.c ft_isprint.c\
		ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c ft_strrchr.c

OBJ = $(SRC:.c=.o)

DEPS = libft.h

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
all : $(NAME)
%.o : %.c $(DEPS)
	gcc $(FLAGS) -o $@ -c $<
opti : all	
	ranlib $(NAME)
optic : opti clean

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : 	fclean all
