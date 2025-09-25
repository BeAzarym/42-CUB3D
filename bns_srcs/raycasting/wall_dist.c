/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:52:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:01:44 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	compute_wall_dist(t_cub *cub)
{
	if (cub->ray->ray_x < 0)
	{
		cub->ray->step_x = -1;
		cub->ray->side_dist_x = (cub->ray->p_x - cub->ray->map_x)
			* cub->ray->delta_x;
	}
	else
	{
		cub->ray->step_x = 1;
		cub->ray->side_dist_x = (cub->ray->map_x + 1 - cub->ray->p_x)
			* cub->ray->delta_x;
	}
	if (cub->ray->ray_y < 0)
	{
		cub->ray->step_y = -1;
		cub->ray->side_dist_y = (cub->ray->p_y - cub->ray->map_y)
			* cub->ray->delta_y;
	}
	else
	{
		cub->ray->step_y = 1;
		cub->ray->side_dist_y = (cub->ray->map_y + 1 - cub->ray->p_y)
			* cub->ray->delta_y;
	}
}
