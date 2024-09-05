/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:26 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:38:29 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	compute_dda(t_cub *cub)
{
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
		if (cub->map->grid[cub->ray->map_y][cub->ray->map_x] == WALL)
			cub->ray->hit = 1;
	}
}
