/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:27:36 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 12:42:27 by bschor           ###   ########.fr       */
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

void	move_x_axe(t_cub *cub, int x)
{
	int	new_x;
	int	new_y;

	new_x = (int)(cub->ray->p_x - (MOVE_SPEED * x) * cub->ray->dir_x) ;
	new_y = (int)(cub->ray->p_y - (MOVE_SPEED * x) * cub->ray->dir_y);
	if (is_valid_pos(new_x + 0.02, new_y + 0.02, cub) == TRUE
		&& (is_valid_pos(new_x + 0.02, cub->ray->p_y, cub) == TRUE
			|| is_valid_pos(cub->ray->p_x, new_y + 0.02, cub) == TRUE))
	{
		cub->ray->p_x -= (MOVE_SPEED * x) * cub->ray->dir_x;
		cub->ray->p_y -= (MOVE_SPEED * x) * cub->ray->dir_y;
	}
}

void	move_y_axe(t_cub *cub, int x)
{
	int	new_x;
	int	new_y;

	new_x = (int)(cub->ray->p_x - (MOVE_SPEED * x) * cub->ray->dir_y);
	new_y = (int)(cub->ray->p_y + (MOVE_SPEED * x) * cub->ray->dir_x);
	if (is_valid_pos(new_x + 0.02, new_y + 0.02, cub) == TRUE
		&& (is_valid_pos(new_x + 0.02, cub->ray->p_y, cub) == TRUE
			|| is_valid_pos(cub->ray->p_x, new_y + 0.02, cub) == TRUE))
	{
		cub->ray->p_x -= (MOVE_SPEED * x) * cub->ray->dir_y;
		cub->ray->p_y += (MOVE_SPEED * x) * cub->ray->dir_x;
	}
}
