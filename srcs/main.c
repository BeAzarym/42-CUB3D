/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:54:23 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/29 13:56:32 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	render(t_cub *cub)
{
	cub->mlx->img_ptr = mlx_new_image(cub->mlx->mlx, WIDTH, HEIGHT);
	cub->mlx->img_addr = mlx_get_data_addr(cub->mlx->img_ptr, &cub->mlx->bpp, &cub->mlx->size_line, &cub->mlx->endian);
	raycast(cub);
	move_player(cub);
	turn_player(cub);
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->win, cub->mlx->img_ptr, 0, 0);
	mlx_destroy_image(cub->mlx->mlx, cub->mlx->img_ptr);
	cub->mlx->img_ptr = NULL;
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
	mlx_hook(cub->mlx->win, 2, (1L<<0), key_press, cub);
	mlx_hook(cub->mlx->win, 3, (1L<<1), key_release, cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_red_cross, cub);
	mlx_loop(cub->mlx->mlx);
	clean_exit(cub, SUCCESS);
	return (0);
}
