# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 15:25:27 by jfelty            #+#    #+#              #
#    Updated: 2019/11/25 19:22:38 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#name of resultant compiled library

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I. -c
#flags to compile with header in local directory

SRC =		ascii/ft_isalpha.c \
			ascii/ft_isdigit.c \
			ascii/ft_isalnum.c \
			ascii/ft_isascii.c \
			ascii/ft_isprint.c \
			ascii/ft_toupper.c \
			ascii/ft_tolower.c \
			ascii/ft_isspace.c \
			string/ft_strlen.c \
			string/ft_strdup.c \
			string/ft_strcpy.c \
			string/ft_strncpy.c \
			string/ft_strcat.c \
			string/ft_strncat.c \
			string/ft_strchr.c \
			string/ft_strrchr.c \
			string/ft_strstr.c \
			string/ft_strnstr.c \
			string/ft_strcmp.c \
			string/ft_strncmp.c \
			string/ft_strlcat.c \
			string/ft_strnew.c \
			string/ft_strdel.c \
			string/ft_strclr.c \
			string/ft_striter.c \
			string/ft_striteri.c \
			string/ft_strmap.c \
			string/ft_strequ.c \
			string/ft_strnequ.c \
			string/ft_strsub.c \
			string/ft_strjoin.c \
			string/ft_strtrim.c \
			string/ft_strsplit.c \
			string/ft_get_next_line.c \
			string/ft_strnchr.c \
			string/ft_replacechr.c \
			string/ft_fillstrnew.c \
			string/ft_strrev.c \
			string/ft_push_to_str_front.c \
			string/ft_wordcount.c \
			conversion/ft_atoi.c \
			conversion/ft_itoa.c \
			conversion/ft_atoi_base.c \
			conversion/ft_itoa_base.c \
			conversion/ft_lltoa_base.c \
			conversion/ft_ulltoa_base.c \
			memory/ft_memset.c \
			memory/ft_bzero.c \
			memory/ft_memcpy.c \
			memory/ft_memccpy.c \
			memory/ft_memmove.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memalloc.c \
			memory/ft_memdel.c \
			print/ft_putchar.c \
			print/ft_putstr.c \
			print/ft_putendl.c \
			print/ft_putnbr.c \
			print/ft_putchar_fd.c \
			print/ft_putstr_fd.c \
			print/ft_putendl_fd.c \
			print/ft_putnbr_fd.c \
			numbers/ft_numlen.c \
			numbers/ft_getnxtnbr.c \
			numbers/ft_power.c \
			numbers/ft_makepos.c \
			numbers/ft_isneg.c \
			numbers/ft_largest_int.c \
			numbers/ft_dblpower.c \
			ft_printf/ft_printf.c \
			ft_printf/populate.c \
			ft_printf/dispatch.c \
			ft_printf/print.c \
			ft_printf/format_help.c \
			ft_printf/format_help2.c \
			ft_printf/format_cspf.c \
			ft_printf/format_diouxx.c
#all source files

OBJ = $(SRC:.c=.o)
#the .object varients of the SRC files

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "┬┴┬┴┤ ͜ʖ ͡°) ├┬┴┬┴"
#ar updates and rc replaces library file if any changes have been made
#@ suppresses command line outputs

clean:
	@rm -f $(OBJ)
#cleans object files in directory

fclean: clean
	@rm -f $(NAME)
	@echo "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ ✧ﾟ･: *ヽ(◕ヮ◕ヽ)"
#empties library as well

re: fclean all

.PHONY: clean fclean all re