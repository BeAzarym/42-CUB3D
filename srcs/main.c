/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:54:23 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/28 17:10:37 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	render(t_cub *cub)
{
	raycast(cub);
	move_player(cub);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = NULL;
	if (arg_parser(argc, argv) != SUCCESS)
		return (FAIL);
	cub = struct_initialization(cub, argv[1]);
	if (!cub)
		return (FAIL);
	if (parser(cub) != SUCCESS)
		clean_exit(cub, FAIL);
	cub->mlx->mlx = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_loop_hook(cub->mlx->mlx, render, cub);
	cub->img->ptr = mlx_new_image(cub->mlx->mlx, WIDTH, HEIGHT);
	cub->img->addr = mlx_get_data_addr(cub->img->ptr, &cub->img->bpp, &cub->img->size_line, &cub->img->endian);
	mlx_hook(cub->mlx->win, 2, (1L<<0), key_press, cub);
	mlx_hook(cub->mlx->win, 3, (1L<<1), key_release, cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_red_cross, cub);
	mlx_loop(cub->mlx->mlx);
	clean_exit(cub, SUCCESS);
	return (0);
}
