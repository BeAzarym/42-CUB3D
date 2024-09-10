/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:21 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/10 10:19:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx/minilinux/mlx.h"
# include "../minilibx/minimac/mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"
# include "math.h"

/*
# include <X11/X.h>
# include <X11/keysym.h>
*/

# define ERR_MALLOC_FAILLED "Error\nMalloc failled\n"
# define ERR_OPEN_FAILLED "Error\nFailled to open the map\n"
# define ERR_NEW_LINE_IN_MAP "Error\nNew line in map\n"
# define ERR_INVALID_CHARSET_IN_MAP "Error\nInvalid character in map\n"
# define ERR_MISSING_MAP "Error\nMissing map\n"
# define ERR_MISSING_DATA "Error\nMissing data\n"
# define ERR_MULTIPLE_PLAYER "Error\nMultiple players in map\n"
# define ERR_MISSING_PLAYER "Error\nPlayer is missing\n"
# define ERR_INVALID_COUNT_ARG "Error\nInvalid count of argument\n"
# define ERR_INVALID_MAP_EXTENSION "Error\nInvalid map extension\n"
# define ERR_ACCESS_MAP "Error\nCan't access to the map file\n"
# define ERR_INVALID_FILE_EXTENSION "Error\nInvalid file extension\n"
# define ERR_BAD_IDENTIFIER "Error\nBad identifier for assets or color\n"
# define ERR_ASSETS_CORRUPTED "Error\nAssets refference corrupted\n"
# define ERR_FAIL_TO_FILL_ASSETS "Error\nFailled to fill assets\n"
# define ERR_FAIL_TO_FILL_COLORS "Error\nFailled to fill colors\n"
# define ERR_ACCESS_NORTH "Error\nCan't access to north assests file\n"
# define ERR_ACCESS_SOUTH "Error\nCan't access to north assests file\n"
# define ERR_ACCESS_EAST "Error\nCan't access to north assests file\n"
# define ERR_ACCESS_WEST "Error\nCan't access to north assests file\n"
# define ERR_DUPLICATE_NORTH "Error\nDuplicated NORTH path\n"
# define ERR_DUPLICATE_SOUTH "Error\nDuplicated SOUTH path\n"
# define ERR_DUPLICATE_EAST "Error\nDuplicated EAST path\n"
# define ERR_DUPLICATE_WEST "Error\nDuplicated WEST path\n"
# define ERR_DUPLICATE_FLOOR "Error\nDuplicated floor\n"
# define ERR_DUPLICATE_CEILING "Error\nDuplicated ceiling\n"
# define ERR_INVALID_COLOR_FORMAT "Error\nInvalid color format\n"
# define ERR_INVALID_COLOR_PARAM "Error\nInvalid color parameter\n"
# define ERR_FAIL_TO_LOAD_NORTH "Error\nFail to load north img\n"
# define ERR_FAIL_TO_LOAD_SOUTH "Error\nFail to load south img\n"
# define ERR_FAIL_TO_LOAD_EAST "Error\nFail to load east img\n"
# define ERR_FAIL_TO_LOAD_WEST "Error\nFail to load west img\n"
# define ERR_MAP_ISNT_CLOSED "Error\nMap is not closed\n"
# define ERR_FAIL_TO_CREATE_IMG "Error\nFail to create new mlx img\n"
# define ERR_FAIL_TO_INIT_MLX "Error\nFail to init mlx\n"
# define ERR_FAIL_TO_CREATE_WINDOW "Error\nFail to create new mlx window\n"

# define TRUE 1
# define FALSE 0
# define FAIL 1
# define SUCCESS 0
# define PI 3.14
# define XPM_SIZE 64
# define FOV 60

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define XBLU 0x90007EFF
# define XWHIT 0x90FFFFFF
# define XPINK 0x90ECC8E5

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

# ifndef MAPWIDTH
#  define MAPWIDTH 640
# endif

# ifndef MAPHEIGHT
#  define MAPHEIGHT 360
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 0.05
# endif

# ifndef ROT
#  define ROT 0.03
# endif

# ifdef __linux__
#  define ESC 65307
#  define W 119
#  define Z 122
#  define Q 113
#  define A 97
#  define S 115
#  define D 100
#  define M 109
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define UP 65362
#  define DOWN 65364
# elif __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define Z 6
#  define Q 12
#  define M 46
#  define UP 126
#  define DOWN 125
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
# endif

enum e_char
{
	SPACE = 32,
	FLOOR = 48,
	WALL = 49,
	NORTH = 78,
	SOUTH = 83,
	WEST = 87,
	EAST = 69
};

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		*xpm_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_data
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		floor;
	int		ceiling;
}	t_data;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			blocksize;
	int			offset;
	int			offset2;
}	t_map;

typedef struct s_raycasting
{
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		start;
	int		end;
	int		texture_num;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
}	t_raycast;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*raycast;
	t_img	*map;
}	t_mlx;

typedef struct s_keys
{
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			map;
	int			big_map;
}	t_keys;

typedef struct s_cub
{
	t_mlx		*mlx;
	t_data		*data;
	t_raycast	*ray;
	t_img		*img;
	t_keys		*key;
	t_map		*map;
	int			infile_fd;
}	t_cub;

/*
 *	RAYCASTING
*/

void	raycast(t_cub *cub);
void	move_player(t_cub *cub);
void	turn_player(t_cub *cub, t_raycast *ray);
void	draw_texture(t_cub *cub, int x);
void	decide_wall(t_cub *cub);
void	draw_map(t_cub *cub);
void	move_x_axe(t_cub *cub, int x);
void	move_y_axe(t_cub *cub, int x);
void	set_background(t_cub *cub);
void	compute_dda(t_cub *cub);
void	compute_wall_dist(t_cub *cub);

/*
 *	DEBUG
*/

void	debug_file_input(t_cub *cub);
void	debug_raycast(t_cub *cub);
int		detect_key_code(int keycode, t_mlx *mlx);

/*
 *	HOOKS
*/

int		key_press(int key_code, t_cub *cub);
int		key_release(int key_code, t_cub *cub);
int		ft_red_cross(t_cub *cub, int code);

/*
 *	PARSING
*/

int		extension_parser(char *path, char *extension);
int		arg_parser(int argc, char **argv);
t_cub	*struct_initialization(t_cub *cub, char *path);
t_keys	*init_keys(t_keys *keys);
t_map	*init_map(t_map *map);
int		parser(t_cub *cub);
void	clean_exit(t_cub *cub, int return_value);
int		parse_data_file(t_data *data, char *input);
int		fill_assests(t_data *data, char **buffer);
int		parse_colors(t_data *data, char **buffer);
int		parse_map(t_cub *cub);
int		parse_player(t_cub *cub);

/*
 *	UTILS
 */

int		ft_access(char *src);
void	ft_array_clear(char **array);
void	ft_array_print(char **array);
int		ft_arraylen(char **arr);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
void	ft_put_pixel_on_img(t_img *img, int x, int y, int color);
size_t	ft_strlen(const char *s);
int		ft_error(char *err, int return_value);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**array_add_back(char **arr, char *str);
int		is_valid_charset(char c, char *charset);
int		is_only_digit(char *s);
int		ft_isdigit(int c);
int		is_valid_pos(int x, int y, t_cub *cub);
void	ft_put_line(t_img *img, int p0[2], int p1[2], int color);
#endif