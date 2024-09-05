/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:27:36 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 14:17:18 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_player(t_cub *cub, t_raycast *ray)
{
	double	tmp_dirx;
	double	tmp_planx;

	if (cub->key->rotate_left == TRUE)
	{
		tmp_dirx = cub->ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-ROT) - ray->dir_y * sin(-ROT);
		ray->dir_y = tmp_dirx * sin(-ROT) + ray->dir_y * cos(-ROT);
		tmp_planx = ray->plan_x;
		ray->plan_x = ray->plan_x * cos(-ROT) - ray->plan_y * sin(-ROT);
		ray->plan_y = tmp_planx * sin(-ROT) + ray->plan_y * cos(-ROT);
	}
	if (cub->key->rotate_right == TRUE)
	{
		tmp_dirx = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(ROT) - ray->dir_y * sin(ROT);
		ray->dir_y = tmp_dirx * sin(ROT) + ray->dir_y * cos(ROT);
		tmp_planx = ray->plan_x;
		ray->plan_x = ray->plan_x * cos(ROT) - ray->plan_y * sin(ROT);
		ray->plan_y = tmp_planx * sin(ROT) + ray->plan_y * cos(ROT);
	}
}

void	move_x_axe(t_cub *cub, int x)
{
	int	new_x;
	int	new_y;

	new_x = (int)(cub->ray->p_x - (MOVE_SPEED * x) * cub->ray->dir_x);
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
