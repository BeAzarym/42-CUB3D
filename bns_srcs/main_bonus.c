/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:54:23 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/09 21:13:49 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	handle_move(t_cub *cub)
{
	if (cub->key->forward)
		move_x_axe(cub, -1);
	if (cub->key->back)
		move_x_axe(cub, 1);
	if (cub->key->right)
		move_y_axe(cub, 1);
	if (cub->key->left)
		move_y_axe(cub, -1);
	turn_player(cub, cub->ray);
}

static int	init_game(t_cub *cub, t_mlx *mlx)
{
	cub->mlx->raycast->ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!cub->mlx->raycast->ptr)
		return (ft_error(ERR_FAIL_TO_CREATE_IMG, FAIL));
	cub->mlx->raycast->addr = mlx_get_data_addr(mlx->raycast->ptr,
			&mlx->raycast->bpp, &mlx->raycast->size_line,
			&mlx->raycast->endian);
	cub->mlx->map->ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!cub->mlx->map->ptr)
		return (ft_error(ERR_FAIL_TO_CREATE_IMG, FAIL));
	cub->mlx->map->addr = mlx_get_data_addr(mlx->map->ptr,
			&mlx->map->bpp, &mlx->map->size_line, &mlx->map->endian);
	return (SUCCESS);
}

int	render(t_cub *cub)
{
	if (init_game(cub, cub->mlx) != SUCCESS)
		clean_exit(cub, FAIL);
	set_background(cub);
	handle_move(cub);
	draw_map(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->win,
		cub->mlx->raycast->ptr, 0, 0);
	mlx_destroy_image(cub->mlx->mlx, cub->mlx->raycast->ptr);
	if (cub->key->map == TRUE)
		mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->win,
			cub->mlx->map->ptr, 0, 0);
	mlx_destroy_image(cub->mlx->mlx, cub->mlx->map->ptr);
	cub->mlx->raycast->ptr = NULL;
	cub->mlx->map->ptr = NULL;
	return (0);
}

void	init_textures(t_cub *cub)
{
	cub->img[NO].ptr = mlx_xpm_file_to_image(cub->mlx->mlx, cub->data->no_path,
			&cub->img[NO].width, &cub->img[NO].height);
	cub->img[NO].xpm_addr = (int *)mlx_get_data_addr(cub->img[NO].ptr,
			&cub->img[NO].bpp, &cub->img[NO].size_line, &cub->img[NO].endian);
	cub->img[SO].ptr = mlx_xpm_file_to_image(cub->mlx->mlx, cub->data->so_path,
			&cub->img[SO].width, &cub->img[SO].height);
	cub->img[SO].xpm_addr = (int *)mlx_get_data_addr(cub->img[SO].ptr,
			&cub->img[SO].bpp, &cub->img[SO].size_line, &cub->img[SO].endian);
	cub->img[EA].ptr = mlx_xpm_file_to_image(cub->mlx->mlx, cub->data->ea_path,
			&cub->img[EA].width, &cub->img[EA].height);
	cub->img[EA].xpm_addr = (int *)mlx_get_data_addr(cub->img[EA].ptr,
			&cub->img[EA].bpp, &cub->img[EA].size_line, &cub->img[EA].endian);
	cub->img[WE].ptr = mlx_xpm_file_to_image(cub->mlx->mlx, cub->data->we_path,
			&cub->img[WE].width, &cub->img[WE].height);
	cub->img[WE].xpm_addr = (int *)mlx_get_data_addr(cub->img[WE].ptr,
			&cub->img[WE].bpp, &cub->img[WE].size_line, &cub->img[WE].endian);
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
	if (!cub->mlx->mlx)
		clean_exit(cub, ft_error(ERR_FAIL_TO_INIT_MLX, FAIL));
	cub->mlx->win = mlx_new_window(cub->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->mlx->win)
		clean_exit(cub, ft_error(ERR_FAIL_TO_CREATE_WINDOW, FAIL));
	init_textures(cub);
	mlx_hook(cub->mlx->win, 2, (1L << 0), key_press, cub);
	mlx_hook(cub->mlx->win, 3, (1L << 1), key_release, cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_red_cross, cub);
	mlx_loop_hook(cub->mlx->mlx, render, cub);
	mlx_loop(cub->mlx->mlx);
	clean_exit(cub, SUCCESS);
	return (0);
}
