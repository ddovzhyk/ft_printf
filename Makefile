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

NAME = libftprintf.a
FLAGS = -Wextra -Wall -Werror
INCLUDES = -I .
OBJECTS = 							\
			./ft_printf.o			\
			./modif.o				\
			./check_ch.o			\
			./for_printf.o			\
			./for_wchar.o			\
			./specif_cspn.o			\
			./specif_diuoxb.o		\
			./toa_base.o			\
									\
			./libft/ft_memset.o		\
			./libft/ft_bzero.o		\
			./libft/ft_memcpy.o		\
			./libft/ft_memcmp.o		\
			./libft/ft_strlen.o		\
			./libft/ft_strdup.o		\
			./libft/ft_strcpy.o		\
			./libft/ft_strcat.o		\
			./libft/ft_strcmp.o		\
			./libft/ft_isdigit.o	\
			./libft/ft_tolower.o	\
									\
			./libft/ft_memalloc.o	\
			./libft/ft_memdel.o		\
			./libft/ft_strnew.o		\
			./libft/ft_strdel.o		\
			./libft/ft_strsub.o		\
			./libft/ft_strjoin.o	\
			./libft/ft_putchar.o	\
			./libft/ft_putstr.o		\
			./libft/ft_putchar_fd.o	\
			./libft/ft_putstr_fd.o	\

all : $(NAME)
$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
%.o : %.c
	gcc $(FLAGS) -o $@ -c $< $(INCLUDES)
clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all