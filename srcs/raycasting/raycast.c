/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:44:18 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 12:31:46 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_background(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < HALFWIDTH)
		{
			if (i < HEIGHT / 2)
				ft_put_pixel_on_img(cub->mlx->raycast, j, i, cub->data->ceiling);
			else
				ft_put_pixel_on_img(cub->mlx->raycast, j, i, cub->data->floor);
			j++;
		}
		i++;
	}
}

void	raycast(t_cub *cub)
{
	int x = 0;

	set_background(cub);
	while (x < HALFWIDTH)
	{	
		cub->ray->camera_x = 2 * x / (double)HALFWIDTH - 1;
		// printf("%lf + %lf * %lf\n", cub->ray->dir_x, cub->ray->plan_x, cub->ray->camera_x);
		cub->ray->ray_x = cub->ray->dir_x + cub->ray->plan_x * cub->ray->camera_x;
		cub->ray->ray_y = cub->ray->dir_y + cub->ray->plan_y * cub->ray->camera_x;
		cub->ray->map_x = (int)(cub->ray->p_x);
		cub->ray->map_y = (int)(cub->ray->p_y);
		if (cub->ray->ray_x == 0)
			cub->ray->delta_x = 1e30;
		else
			cub->ray->delta_x = fabs(1 / cub->ray->ray_x);
		if (cub->ray->ray_y == 0)
			cub->ray->delta_y = 1e30;
		else
			cub->ray->delta_y = fabs(1 / cub->ray->ray_y);
		cub->ray->hit = 0;

		if (cub->ray->ray_x < 0)
		{
			cub->ray->step_x = -1;
			cub->ray->side_dist_x = (cub->ray->p_x - cub->ray->map_x) * cub->ray->delta_x;
		}
		else
		{
			cub->ray->step_x = 1;
			cub->ray->side_dist_x = (cub->ray->map_x + 1 - cub->ray->p_x) * cub->ray->delta_x;
		}

		if (cub->ray->ray_y < 0)
		{
			cub->ray->step_y = -1;
			cub->ray->side_dist_y = (cub->ray->p_y - cub->ray->map_y) * cub->ray->delta_y;
		}
		else
		{
			cub->ray->step_y = 1;
			cub->ray->side_dist_y = (cub->ray->map_y + 1 - cub->ray->p_y) * cub->ray->delta_y;
		}

		while (cub->ray->hit == 0)
		{
			if (cub->ray->side_dist_x < cub->ray->side_dist_y)
			{
				cub->ray->side_dist_x += cub->ray->delta_x;
				cub->ray->map_x += cub->ray->step_x;
				cub->ray->side = 0;
			}
			else
			{
				cub->ray->side_dist_y += cub->ray->delta_y;
				cub->ray->map_y += cub->ray->step_y;
				cub->ray->side = 1;
			}
			if (cub->map[cub->ray->map_y][cub->ray->map_x] == WALL)
				cub->ray->hit = 1;
		}
		if (cub->ray->side == 0)
			cub->ray->wall_dist = cub->ray->side_dist_x - cub->ray->delta_x;
		else
			cub->ray->wall_dist = cub->ray->side_dist_y - cub->ray->delta_y;

		cub->ray->line_height = (int)(HEIGHT / cub->ray->wall_dist);

		cub->ray->start = (HEIGHT - cub->ray->line_height) / 2;
		if (cub->ray->start < 0)
			cub->ray->start = 0;
		cub->ray->end = cub->ray->line_height + cub->ray->start;
		if (cub->ray->end >= HEIGHT)
		 	cub->ray->end = HEIGHT - 1;

		decide_wall(cub);
		draw_texture(cub, x);
		
		x++;
	}
}


