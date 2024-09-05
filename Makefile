.SILENT:

NAME = cub3d

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 -ffast-math -fsanitize=address -g

SRCS_DIR = srcs
INC_DIR = includes

OS = $(shell uname)
ifeq ($(OS), Linux)
	OSDIR := minilibx/minilinux
	LINKS := -lX11 -lXext
else
	OSDIR := minilibx/minimac
	LINKS := -framework OpenGL -framework AppKit
endif
MLX_DIR = $(OSDIR)

INC = cub3d.h

SRC = main.c \
		hooks/handle_keys.c \
		parsing/arg_parser.c \
		parsing/extension_parser.c \
		parsing/structure_initialization.c \
		parsing/keys_struct_initialization.c \
		parsing/parser.c \
		parsing/parse_data.c \
		parsing/parse_colors.c \
		parsing/parse_map.c \
		parsing/parse_player.c \
		parsing/fill_assets.c \
		utils/ft_access.c \
		utils/ft_array_clear.c \
		utils/ft_array_add_back.c \
		utils/ft_array_print.c \
		utils/ft_arraylen.c \
		utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_error.c \
		utils/ft_calloc.c \
		utils/ft_memset.c \
		utils/ft_putstr_fd.c \
		utils/ft_split.c \
		utils/ft_strchr.c \
		utils/ft_strrchr.c \
		utils/ft_strdup.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		utils/get_next_line.c \
		utils/ft_substr.c \
		utils/ft_put_pixel_on_img.c \
		utils/ft_strncmp.c \
		utils/is_valid_charset.c \
		utils/ft_isdigit.c \
		utils/is_valid_pos.c \
		utils/bresenham.c \
		debug/debug_file_input.c \
		debug/key_detector.c \
		raycasting/raycast.c \
		raycasting/handle_player.c \
		raycasting/draw_texture.c \
		raycasting/map.c \


SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS = $(addsuffix .o, $(basename $(SRCS)))

INCS_DIR = $(addsuffix /, $(INC_DIR))
INCS = $(addprefix -I , $(INCS_DIR))

MLX_INC = -I $(MLX_DIR)
MLX_LIB = $(addprefix $(MLX_DIR)/,libmlx.a)
MLX_LINK = -L $(MLX_DIR) -l mlx $(LINKS)

all : $(NAME) $(MLXLIB)

$(NAME) : mlx $(OBJS)
	$(CC) $(OBJS) $(MLX_LINK) -lm -o $(NAME) $(CFLAGS)

mlx :
	@make -C $(MLX_DIR)

clean :
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean

re : fclean all

fclean : clean
	$(RM) $(NAME)

%.o: $(SRCS_DIR)/%.c
	$(CC) -c -o $@ $< $(MLX_INC) $(INCS) $(CFLAGS)

.PHONY: NAME re all fclean clean