# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 13:40:08 by mel-akio     #+#   ##    ##    #+#        #
#    Updated: 2018/01/19 17:10:33 by mel-akio    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
.PHONY: all clean fclean re

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
NAME = libft.a
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./
FILES =\
	   ft_atoi.c\
	   ft_putchar.c\
	   ft_strlen.c\
	   ft_bzero.c\
	   ft_putchar_fd.c\
	   ft_strmap.c\
	   ft_count_letter.c\
	   ft_putendl.c\
	   ft_strmapi.c\
	   ft_count_word.c\
	   ft_putendl_fd.c\
	   ft_strncat.c\
	   ft_ignoreblank.c\
	   ft_putnbr.c\
	   ft_strncpy.c\
	   ft_isalnum.c\
	   ft_putnbr_fd.c\
	   ft_strndup.c\
	   ft_isalpha.c\
	   ft_putstr.c\
	   ft_strnequ.c\
	   ft_isascii.c\
	   ft_putstr_fd.c\
	   ft_strnew.c\
	   ft_isdigit.c\
	   ft_strcat.c\
	   ft_strnstr.c\
	   ft_isprint.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_itoa.c\
	   ft_strclr.c\
	   ft_strsplit.c\
	   ft_memalloc.c\
	   ft_strcpy.c\
	   ft_strstr.c\
	   ft_memchr.c\
	   ft_strdel.c\
	   ft_strsub.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_strdup.c\
	   ft_strtrim.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_strequ.c\
	   ft_tolower.c\
	   ft_memdel.c\
	   ft_striter.c\
	   ft_toupper.c\
	   ft_memmove.c\
	   ft_striteri.c\
	   ft_memset.c\
	   ft_strjoin.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_strlcat.c\
	   ft_strcat.c\
	   ft_strmapi.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_swap.c\
	   ft_strjoin_free.c\
	   ft_strsub_free.c\
	   get_next_line.c\

	OBJ = $(addprefix $(PATH_OBJ), $(FILES:.c=.o))
	SRC = $(addprefix $(PATH_SRC), $(FILES))
	INC = $(addprefix $(PATH_INC), libft.h)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
