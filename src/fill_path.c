/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:52:48 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 18:49:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_north_path(char **buffer, t_game_data *ptr);
static void	set_south_path(char **buffer, t_game_data *ptr);
static void	set_west_path(char **buffer, t_game_data *ptr);
static void	set_east_path(char **buffer, t_game_data *ptr);

void	fill_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return ;
	if (ft_strcmp(buffer[0], "NO") == 0)
		set_north_path(buffer, ptr);
	else if (ft_strcmp(buffer[0], "SO") == 0)
		set_south_path(buffer, ptr);
	else if (ft_strcmp(buffer[0], "WE") == 0)
		set_west_path(buffer, ptr);
	else if (ft_strcmp(buffer[0], "EA") == 0)
		set_east_path(buffer, ptr);
}

static void	set_north_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return ;
	ptr->no_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->no_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("%s %s \n", SET_NORTH, ptr->no_path);
}

static void	set_south_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return ;
	ptr->so_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->so_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("%s %s \n", SET_SOUTH, ptr->so_path);
}

static void	set_west_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return ;
	ptr->we_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->we_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("%s %s \n", SET_WEST, ptr->we_path);
}

static void	set_east_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return ;
	ptr->ea_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->ea_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("%s %s \n", SET_EAST, ptr->ea_path);
}
