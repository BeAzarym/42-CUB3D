/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:56:11 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 17:23:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_data(char *arg, t_game_data *ptr)
{
	if (!arg)
		return;
	char **buffer;

	if (ft_strcmp(arg, "\n") == 0)
		return;
	buffer = ft_split(arg, ' ');
	if (!buffer)
		return (ft_error(ptr, ERR_MALLOC));
	if (is_texture_path(buffer[0]))
		fill_path(buffer, ptr);
	if (is_color(buffer[0]))
		fill_color(buffer, ptr);
	ft_array_clear(buffer);
}

// int is_map(char *map)
// {

// }