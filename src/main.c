/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:32:01 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 17:56:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void exit_sucess(t_game_data *ptr);

int main(int argc, char **argv)
{
	if (argc != 2)
		return (42);

	t_game_data *data;

	data = NULL;

	data = init_struct(data);
	if (!data)
		return (19);
	parse_argment(argv, data);
	print_struct(data);
	exit_sucess(data);
}

static void exit_sucess(t_game_data *ptr)
{
	ft_array_clear(ptr->map);
	free(ptr->NO_path);
	free(ptr->SO_path);
	free(ptr->WE_path);
	free(ptr->EA_path);
	free(ptr->ceiling_color);
	free(ptr->floor_color);
	free(ptr);
	exit(EXIT_SUCCESS);
}
