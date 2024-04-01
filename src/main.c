/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:32:01 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 18:40:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	exit_sucess(t_game_data *ptr);
static int	is_valid_extension(char *path);

int	main(int argc, char **argv)
{
	t_game_data	*data;

	if (argc != 2)
		return (42);
	data = NULL;
	data = init_struct(data);
	if (!data)
		return (19);
	if (is_valid_extension(argv[1]) != 0)
		ft_error(data, ERR_EXTENSION);
	parse_argment(argv, data);
	print_struct(data);
	exit_sucess(data);
}

static void	exit_sucess(t_game_data *ptr)
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

static int	is_valid_extension(char *path)
{
	int	i;

	i = (ft_strlen(path) - 4);
	return (ft_strcmp(&path[i], ".cub"));
}
