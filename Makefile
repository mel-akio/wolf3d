.PHONY = all, clean, fclean, re

NAME = wolf3d

#		COMIPLATION

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit

#		PATH

LIBFT = libft/libft.a
INCLUDE = includes/wold3d.h

SRCS = \
				src/main.c \
				src/ft_mlx.c \
				src/ft_mlx2.c \
				src/make_map.c \
				src/distance.c \
				src/collision.c \
				src/init.c \
				src/ray_step.c \
				src/display.c \
				src/secure.c

OBJS = $(SRCS:.c=.o)

#		RULES

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) libft/libft.a minilibx_macos/libmlx.a $(FRAMEWORK) -o $(NAME)

./%.o:./%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(LIBFT):
	make -C libft

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
