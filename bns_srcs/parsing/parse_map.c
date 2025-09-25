/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:10:20 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:40:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ensure_is_closed(t_cub *cub);
static int	is_close(int x, int y, t_cub *cub);
static int	compute_map_width(char **grid);

int	parse_map(t_cub *cub)
{
	cub->map->height = ft_arraylen(cub->map->grid);
	cub->map->width = compute_map_width(cub->map->grid);
	if (parse_player(cub) == FAIL)
		return (FAIL);
	if (cub->ray->p_x == -1 || cub->ray->p_y == -1)
		return (ft_error(ERR_MISSING_PLAYER, FAIL));
	if (ensure_is_closed(cub) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	ensure_is_closed(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map->grid[y])
	{
		x = 0;
		while (cub->map->grid[y][x])
		{
			if (is_valid_charset(cub->map->grid[y][x], "0NSEW"))
				if (is_close(x, y, cub) == FALSE)
					return (ft_error(ERR_MAP_ISNT_CLOSED, FAIL));
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

static int	is_close(int x, int y, t_cub *cub)
{
	char	up;
	char	down;
	char	right;
	char	left;

	if (y - 1 < 0 || y + 1 >= cub->map->height)
		return (FALSE);
	if (x - 1 < 0 || x + 1 >= cub->map->width)
		return (FALSE);
	up = cub->map->grid[y - 1][x];
	down = cub->map->grid[y + 1][x];
	right = cub->map->grid[y][x + 1];
	left = cub->map->grid[y][x - 1];
	if (up != '1' && !is_valid_charset(up, "0NSWE"))
		return (FALSE);
	if (down != '1' && !is_valid_charset(down, "0NSWE"))
		return (FALSE);
	if (right != '1' && !is_valid_charset(right, "0NSWE"))
		return (FALSE);
	if (left != '1' && !is_valid_charset(left, "0NSWE"))
		return (FALSE);
	return (TRUE);
}

static int	compute_map_width(char **grid)
{
	int	y;
	int	width;

	y = 0;
	width = 0;
	while (grid[y])
	{
		if ((int)ft_strlen(grid[y]) > width)
			width = (ft_strlen(grid[y]));
		y++;
	}
	return (width);
}
