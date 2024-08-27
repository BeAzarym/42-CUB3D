/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:38:35 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/20 20:29:44 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_mlx_struct(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
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
		if (img[i].img_ptr)
			mlx_destroy_image(mlx->mlx, img[i].img_ptr);
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
			ft_array_clear(cub->map);
		close(cub->infile_fd);
		free(cub);
	}
	exit(return_value);
}