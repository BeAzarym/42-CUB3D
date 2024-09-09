/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:11 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:22:42 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_dir(t_cub *cub, int x, int y);

int	parse_player(t_cub *cub)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (cub->map->grid[y])
	{
		x = 0;
		while (cub->map->grid[y][x])
		{
			if (is_valid_charset(cub->map->grid[y][x], "NSEW") == TRUE)
			{
				if (cub->ray->p_x != -1 || cub->ray->p_y != -1)
					return (ft_error(ERR_MULTIPLE_PLAYER, FAIL));
				cub->ray->p_x = (float)x + 0.5;
				cub->ray->p_y = (float)y + 0.5;
				fill_dir(cub, x, y);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

static void	fill_dir(t_cub *cub, int x, int y)
{
	if (cub->map->grid[y][x] == 'N')
	{
		cub->ray->dir_y = -1;
		cub->ray->dir_x = 0;
		cub->ray->plan_x = 0.66;
	}
	else if (cub->map->grid[y][x] == 'S')
	{
		cub->ray->dir_y = 1;
		cub->ray->dir_x = 0;
		cub->ray->plan_x = -0.66;
	}
	else if (cub->map->grid[y][x] == 'E')
	{
		cub->ray->dir_y = 0;
		cub->ray->dir_x = 1;
		cub->ray->plan_y = 0.66;
	}
	else
	{
		cub->ray->dir_y = 0;
		cub->ray->dir_x = -1;
		cub->ray->plan_y = -0.66;
	}
}
