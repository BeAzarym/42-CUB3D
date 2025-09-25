/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:49 by bschor            #+#    #+#             */
/*   Updated: 2024/09/09 21:16:03 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ft_put_square(t_img *img, int start[2], int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel_on_img(img, start[0] + i, start[1] + j, color);
			j++;
		}
		i++;
	}
}

void	set_map(t_cub *cub)
{
	if (cub->key->big_map == FALSE)
	{
		if (cub->map->height > cub->map->width)
			cub->map->blocksize = MAPHEIGHT / cub->map->height;
		else
			cub->map->blocksize = MAPWIDTH / cub->map->width;
		if (WIDTH < HEIGHT)
			cub->map->offset = HEIGHT / 25;
		else
			cub->map->offset = WIDTH / 25;
		cub->map->offset2 = cub->map->offset;
	}
	else
	{
		if (cub->map->height > cub->map->width)
			cub->map->blocksize = HEIGHT / cub->map->height;
		else
			cub->map->blocksize = WIDTH / cub->map->width;
		cub->map->offset2 = (HEIGHT - cub->map->blocksize
				* cub->map->height) / 2;
		cub->map->offset = (WIDTH - cub->map->blocksize
				* (cub->map->width - 1)) / 2;
	}
}

static void	set_invisible(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_put_pixel_on_img(cub->mlx->map, j, i, 0xFF000000);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(map->grid[i]))
		{
			if (map->grid[i][j] == WALL)
				ft_put_square(img, (int [2]){map->blocksize * j + map->offset,
					map->blocksize * i + map->offset2}, map->blocksize, XBLU);
			else if (map->grid[i][j] == FLOOR)
				ft_put_square(img, (int [2]){map->blocksize * j + map->offset,
					map->blocksize * i + map->offset2}, map->blocksize, XWHIT);
			else if (map->grid[i][j] == SOUTH
					|| map->grid[i][j] == NORTH
					|| map->grid[i][j] == EAST
					|| map->grid[i][j] == WEST)
				ft_put_square(img, (int [2]){map->blocksize * j + map->offset,
					map->blocksize * i + map->offset2}, map->blocksize, XPINK);
			j++;
		}
		i++;
	}
}

void	draw_map(t_cub *cub)
{
	set_map(cub);
	set_invisible(cub);
	draw_grid(cub->mlx->map, cub->map);
	ft_put_square(cub->mlx->map, (int [2]){cub->ray->p_x
		* cub->map->blocksize + cub->map->offset - cub->map->blocksize
		/ 4, cub->ray->p_y * cub->map->blocksize + cub->map->offset2
		- cub->map->blocksize / 4}, cub->map->blocksize / 2, 0x90FF00FF);
}
