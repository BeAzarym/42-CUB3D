/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:59:51 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 18:55:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(t_game_data *ptr, char *error_code)
{
	if (!ptr)
		return ;
	ft_array_clear(ptr->map);
	free(ptr->no_path);
	free(ptr->so_path);
	free(ptr->we_path);
	free(ptr->ea_path);
	free(ptr->ceiling_color);
	free(ptr->floor_color);
	free(ptr);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_code, 2);
	exit(EXIT_FAILURE);
}
