/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:32:55 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 18:52:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# define SET_NORTH "[SETTINGS] NO_PATH has set with this current path:"
# define SET_SOUTH "[SETTINGS] SO_PATH has set with this current path:"
# define SET_WEST "[SETTINGS] WE_PATH has set with this current path:"
# define SET_EAST "[SETTINGS] EA_PATH has set with this current path:"
# define SET_CEILING "[SETTINGS] Ceiling color has set with this color code:"
# define SET_FLOOR "[SETTINGS] Floor color has set with this color code:"

# define ERR_OPEN "[ERROR] fail to open file\n"
# define ERR_EMPTY_FILE "[ERROR] file is empty\n"
# define ERR_EXTENSION "[ERROR] Wrong Extension file\n"
# define ERR_MALLOC "[ERROR] malloc failled\n"
# define ERR_CONFIG "[ERROR] Corrupted Config File\n"

typedef struct	s_game_data
{
	char	**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*ceiling_color;
	char	*floor_color;
}	t_game_data;

t_game_data	*init_struct(t_game_data *ptr);
void		parse_argment(char **arg, t_game_data *ptr);
void		ft_error(t_game_data *ptr, char *error_code);
void		print_struct(t_game_data *ptr);
void		set_data(char *arg, t_game_data *ptr);
int			is_texture_path(char *key);
void		fill_path(char **buffer, t_game_data *ptr);
int			is_color(char *key);
void		fill_color(char **buffer, t_game_data *ptr);
int			is_map(char *line);
void		fill_map(char *line, t_game_data *ptr);

#endif