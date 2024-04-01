/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:52:48 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 17:48:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void set_NO_path(char **buffer, t_game_data *ptr);
static void set_SO_path(char **buffer, t_game_data *ptr);
static void set_WE_path(char **buffer, t_game_data *ptr);
static void set_EA_path(char **buffer, t_game_data *ptr);

void fill_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	if (ft_strcmp(buffer[0], "NO") == 0)
	{
		set_NO_path(buffer, ptr);
		return;
	}
	if (ft_strcmp(buffer[0], "SO") == 0)
	{
		set_SO_path(buffer, ptr);
		return;
	}
	if (ft_strcmp(buffer[0], "WE") == 0)
	{
		set_WE_path(buffer, ptr);
		return;
	}
	if (ft_strcmp(buffer[0], "EA") == 0)
	{
		set_EA_path(buffer, ptr);
		return;
	}
}

static void set_NO_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;

	ptr->NO_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->NO_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] NO_PATH has set with this current path: %s \n", ptr->NO_path);
}

static void set_SO_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	ptr->SO_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->SO_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] SO_PATH has set with this current path: %s \n", ptr->SO_path);
}

static void set_WE_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	ptr->WE_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->WE_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] WE_PATH has set with this current path: %s \n", ptr->WE_path);
}

static void set_EA_path(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	ptr->EA_path = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->EA_path)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] EA_PATH has set with this current path: %s \n", ptr->EA_path);
}
