# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 19:04:47 by ddovzhik          #+#    #+#              #
#    Updated: 2016/12/03 19:04:49 by ddovzhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft.a

NAME = libftprintf.a
FLAGS = -Wextra -Wall -Werror
LIBOBJ = ./libft/*.o
OBJECTS =							\
			./ft_printf.o			\
			./modif.o				\
			./check_ch.o			\
			./for_printf.o			\
			./for_wchar.o			\
			./specif_cspn.o			\
			./specif_diuoxb.o		\
			./toa_base.o

all : $(NAME) 
$(NAME) : libft.a $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBOBJ)
	ranlib $(NAME)
libft.a:
	make -C ./libft
%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I .
clean :
	make clean -C ./libft
	rm -f $(OBJECTS)
	rm -f *.c~
fclean : clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
re : fclean all