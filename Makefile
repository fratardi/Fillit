# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 19:01:54 by dkhatri           #+#    #+#              #
#    Updated: 2019/01/08 16:08:59 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = main.c

FLAGS = 

SRCDIR = ./src/

FUNCTIONS = addtochain.c buffconvert.c parse_file.c \
			ft_display.c ft_intarrop.c ft_solve.c

SRCO = $(addprefix $(SRCDIR), $(FUNCTIONS:.c=.o)) \
		$(MAIN:.c=.o)

DEPS = ./includes/fillit.h

%.o: %.c $(DEPS)
	gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	gcc -o $(NAME) $(SRCO) -L libft/ -lft

clean:
	make -C libft clean
	/bin/rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
