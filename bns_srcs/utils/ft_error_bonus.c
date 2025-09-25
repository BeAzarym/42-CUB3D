/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:38:35 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/10 09:51:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	free_mlx_struct(t_mlx *mlx)
{
	if (mlx->map)
	{
		if (mlx->map->ptr)
			mlx_destroy_image(mlx->mlx, mlx->map->ptr);
		free(mlx->map);
	}
	if (mlx->raycast)
	{
		if (mlx->raycast->ptr)
			mlx_destroy_image(mlx->mlx, mlx->raycast->ptr);
		free(mlx->raycast);
	}
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
}

static void	free_img_struct(t_mlx *mlx, t_img *img)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (img[i].ptr)
			mlx_destroy_image(mlx->mlx, img[i].ptr);
		i++;
	}
	free(img);
}

static void	free_file_data_struct(t_data *data)
{
	if (data)
	{
		free(data->no_path);
		free(data->so_path);
		free(data->ea_path);
		free(data->we_path);
		free(data);
	}
}

int	ft_error(char *err, int return_value)
{
	ft_putstr_fd(err, 2);
	return (return_value);
}

void	clean_exit(t_cub *cub, int return_value)
{
	if (cub)
	{
		if (cub->ray)
			free(cub->ray);
		if (cub->data)
			free_file_data_struct(cub->data);
		if (cub->img)
			free_img_struct(cub->mlx, cub->img);
		if (cub->mlx)
			free_mlx_struct(cub->mlx);
		if (cub->map)
		{
			ft_array_clear(cub->map->grid);
			free(cub->map);
		}
		free(cub->key);
		close(cub->infile_fd);
		free(cub);
	}
	exit(return_value);
}
