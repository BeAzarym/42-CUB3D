/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:15:42 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/29 13:48:07 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_raycast	*init_raycast(t_raycast *ray);
static t_mlx		*init_mlx(t_mlx *mlx);
static t_img		*init_img(t_img *img);
static t_data		*init_data(t_data *data);

t_cub	*struct_initialization(t_cub *cub, char *path)
{
	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		ft_error(ERR_MALLOC_FAILLED, FAIL);
		return (NULL);
	}
	cub->map = NULL;
	cub->infile_fd = open(path, O_RDONLY);
	if (cub->infile_fd == -1)
	{
		free(cub);
		ft_error(ERR_OPEN_FAILLED, FAIL);
		return (NULL);
	}
	cub->ray = init_raycast(cub->ray);
	cub->mlx = init_mlx(cub->mlx);
	cub->data = init_data(cub->data);
	cub->img = init_img(cub->img);
	cub->key = init_keys(cub->key);
	if (!cub->ray || !cub->mlx || !cub->data || !cub->img || !cub->key)
	{
		ft_error(ERR_MALLOC_FAILLED, FAIL);
		clean_exit(cub, FAIL);
	}
	return (cub);
}

static t_raycast	*init_raycast(t_raycast *ray)
{
	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (NULL);
	ray->p_x = -1;
	ray->p_y = -1;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plan_x = 0.0;
	ray->plan_y = 0.0;
	ray->camera_x = 0;
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->delta_x = 0.0;
	ray->delta_y = 0.0;
	ray->wall_dist = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	return (ray);
}

static t_mlx	*init_mlx(t_mlx *mlx)
{
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img_ptr = NULL;
	mlx->img_addr = 0;
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	return (mlx);
}

static t_img	*init_img(t_img *img)
{
	img = ft_calloc(sizeof(t_img), 4);
	if (!img)
		return (NULL);
	return (img);
}

static t_data	*init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
	data->floor = 0;
	data->ceiling = 0;
	return (data);
}
