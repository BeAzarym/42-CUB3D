/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:19:32 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 17:50:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void set_ceiling_color(char **buffer, t_game_data *ptr);
static void set_floor_color(char **buffer, t_game_data *ptr);

void fill_color(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	if (ft_strcmp(buffer[0], "F") == 0)
	{
		set_floor_color(buffer, ptr);
		return;
	}
	if (ft_strcmp(buffer[0], "C") == 0)
	{
		set_ceiling_color(buffer, ptr);
		return;
	}
}

static void set_ceiling_color(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	ptr->ceiling_color = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->ceiling_color)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] Ceiling color has set with this color code: %s \n", ptr->ceiling_color);
}

static void set_floor_color(char **buffer, t_game_data *ptr)
{
	if (!buffer || !ptr)
		return;
	ptr->floor_color = ft_substr(buffer[1], 0, (ft_strlen(buffer[1]) - 1));
	if (!ptr->floor_color)
	{
		ft_array_clear(buffer);
		ft_error(ptr, ERR_MALLOC);
	}
	ft_printf("[SETTINGS] Floor color has set with this color code: %s \n", ptr->floor_color);
}