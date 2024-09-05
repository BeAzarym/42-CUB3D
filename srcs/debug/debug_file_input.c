/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_file_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:25:40 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include "../../includes/cub3d.h"

void	debug_file_input(t_cub *cub)
{
	printf("	 [ASSETS]\n");
	printf("[NO] >> %s <<\n", cub->data->no_path);
	printf("[SO] >> %s <<\n", cub->data->so_path);
	printf("[EA] >> %s <<\n", cub->data->ea_path);
	printf("[WE] >> %s <<\n", cub->data->we_path);
	printf("[C]  >> %d <<\n", cub->data->ceiling);
	printf("[F]  >> %d <<\n", cub->data->floor);
	printf("	 [MAP]\n");
	ft_array_print(cub->map->grid);
	printf("	 [PLAYER]\n");
	printf("[X]  >>%f  <<\n", cub->ray->p_x);
	printf("[y]  >>%f  <<\n", cub->ray->p_y);
}

void	debug_raycast(t_cub *cub)
{
	printf("[p_X]	>> %f\n", cub->ray->p_x);
	printf("[p_Y]	>> %f\n", cub->ray->p_y);
	printf("[dir_X]	>> %f\n", cub->ray->dir_x);
	printf("[dir_y]	>> %f\n", cub->ray->dir_y);
	printf("[plan_x]>> %f\n", cub->ray->plan_x);
	printf("[plan_y]>> %f\n", cub->ray->plan_y);
	printf("[Cam_x]	>> %f\n", cub->ray->camera_x);
	printf("[ray_x]	>> %f\n", cub->ray->ray_x);
	printf("[ray_y]	>> %f\n", cub->ray->ray_y);
	printf("[map_x]	>> %d\n", cub->ray->map_x);
	printf("[map_y]	>> %d\n", cub->ray->map_y);
	printf("[side_X]>> %f\n", cub->ray->side_dist_x);
	printf("[side_Y]>> %f\n", cub->ray->side_dist_y);
	printf("[delt_X]>> %f\n", cub->ray->delta_x);
	printf("[delt_Y]>> %f\n", cub->ray->delta_y);
	printf("[wall_d]>> %f\n", cub->ray->wall_dist);
	printf("[step_x]>> %d\n", cub->ray->step_x);
	printf("[step_y]>> %d\n", cub->ray->step_y);
	printf("[hit]	>> %d\n", cub->ray->hit);
	printf("[side]	>> %d\n\n\n", cub->ray->side);
}
