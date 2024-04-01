/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:49:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 15:48:32 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game_data *init_struct(t_game_data *ptr)
{
	ptr = malloc(sizeof(t_game_data));
	if (!ptr)
		return (NULL);
	ptr->map = NULL;
	ptr->NO_path = NULL;
	ptr->SO_path = NULL;
	ptr->WE_path = NULL;
	ptr->EA_path = NULL;
	ptr->ceiling_color = NULL;
	ptr->floor_color = NULL;
	return (ptr);
}

void print_struct(t_game_data *ptr)
{
	if (!ptr)
		return;
	ft_printf("[DEBUG]\n");
	ft_printf("[DEBUG] MAP:\n");
	ft_array_print(ptr->map);
	ft_printf("[DEBUG] NO_PATH : [%s]\n", ptr->NO_path);
	ft_printf("[DEBUG] SO_PATH : [%s]\n", ptr->SO_path);
	ft_printf("[DEBUG] WE_PATH : [%s]\n", ptr->WE_path);
	ft_printf("[DEBUG] EA_PATH : [%s]\n", ptr->EA_path);
	ft_printf("[DEBUG] CEILING COLOR : [%s]\n", ptr->ceiling_color);
	ft_printf("[DEBUG] FLOOR COLOR : [%s]\n", ptr->floor_color);
}
