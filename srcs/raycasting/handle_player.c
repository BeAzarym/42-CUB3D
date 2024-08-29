/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:27:36 by bschor            #+#    #+#             */
/*   Updated: 2024/08/29 14:43:27 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_player(t_cub *cub)
{
	double	tmp_dirx;
	double	tmp_planx;

	if (cub->key->rotate_left == TRUE)
	{
		tmp_dirx = cub->ray->dir_x;
		cub->ray->dir_x = cub->ray->dir_x * cos(- ROT_SPEED) - cub->ray->dir_y * sin(- ROT_SPEED);
		cub->ray->dir_y = tmp_dirx * sin(- ROT_SPEED) + cub->ray->dir_y * cos(- ROT_SPEED);
		tmp_planx = cub->ray->plan_x;
		cub->ray->plan_x = cub->ray->plan_x * cos(- ROT_SPEED) - cub->ray->plan_y * sin(- ROT_SPEED);
		cub->ray->plan_y = tmp_planx * sin(- ROT_SPEED) + cub->ray->plan_y * cos(- ROT_SPEED);
	}
	if (cub->key->rotate_right == TRUE)
	{
		tmp_dirx = cub->ray->dir_x; 
		cub->ray->dir_x = cub->ray->dir_x * cos(ROT_SPEED) - cub->ray->dir_y * sin(ROT_SPEED);
		cub->ray->dir_y = tmp_dirx * sin(ROT_SPEED) + cub->ray->dir_y * cos(ROT_SPEED);
		tmp_planx = cub->ray->plan_x;
		cub->ray->plan_x = cub->ray->plan_x * cos(ROT_SPEED) - cub->ray->plan_y * sin(ROT_SPEED);
		cub->ray->plan_y = tmp_planx * sin(ROT_SPEED) + cub->ray->plan_y * cos(ROT_SPEED);
	}
}

void	move_player(t_cub *cub)
{
	if (cub->key->forward == TRUE)
	{
		if (cub->map[(int)cub->ray->p_y][(int)(cub->ray->p_x + cub->ray->dir_x * MOVE_SPEED)] != '1')
			cub->ray->p_x += cub->ray->dir_x * MOVE_SPEED;
		if (cub->map[(int)(cub->ray->p_y + cub->ray->dir_y * MOVE_SPEED)][(int)(cub->ray->p_x)] == FLOOR)
			cub->ray->p_y += cub->ray->dir_y * MOVE_SPEED;
	}
	if (cub->key->back == TRUE)
	{
		if (cub->map[(int)cub->ray->p_y][(int)(cub->ray->p_x - cub->ray->dir_x * MOVE_SPEED)] == FLOOR)
			cub->ray->p_x -= cub->ray->dir_x * MOVE_SPEED;
		if (cub->map[(int)(cub->ray->p_y - cub->ray->dir_y * MOVE_SPEED)][(int)(cub->ray->p_x)] == FLOOR)
			cub->ray->p_y -= cub->ray->dir_y * MOVE_SPEED;
	}
}