/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:54:23 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/27 15:11:30 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	render(t_cub *cub)
{

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
	mlx_loop_hook(cub->mlx->mlx, render, cub);
	mlx_key_hook(cub->mlx->win, 2, (1L<<0), cub);
	mlx_key_hook(cub->mlx->win, 3, (1L<<1), cub);
	mlx_loop(cub->mlx->mlx);
	clean_exit(cub, SUCCESS);
}
