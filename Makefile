NAME	=	cub3D

SRC =	main.c \
		parser.c \
		struct.c \
		error.c \
		set_data.c \
		fill_path.c \
		fill_color.c \
		fill_map.c \


SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

SRC_DIR = src
INC_DIR = includes

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = @rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft/
	$(CC) $(CLFAGS) -Ilibft -I $(INC_DIR) -o $(NAME) $(OBJS) -Llibft -lft

clean:
	$(RM) $(OBJS)
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all re clean fclean