/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:10:20 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/22 12:21:27 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ensure_is_closed(t_cub *cub);
static int	is_close(int x, int y, t_cub *cub);
static int	compute_map_width(char **map);

int	parse_map(t_cub *cub)
{
	cub->map_height = ft_arraylen(cub->map);
	cub->map_width = compute_map_width(cub->map);
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
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (is_valid_charset(cub->map[y][x], "0NSEW"))
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

	if (y - 1 < 0 || y + 1 >= cub->map_height)
		return (FALSE);
	if (x - 1 < 0 || x + 1 >= cub->map_width)
		return (FALSE);
	up = cub->map[y - 1][x];
	down = cub->map[y + 1][x];
	right = cub->map[y][x + 1];
	left = cub->map[y][x - 1];
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

static int	compute_map_width(char **map)
{
	int	y;
	int	width;

	y = 0;
	width = 0;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) > width)
			width = (ft_strlen(map[y]));
		y++;
	}
	return (width);
}
