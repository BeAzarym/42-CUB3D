/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:49 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 15:29:55 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_square(t_img *img, int startx, int starty, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel_on_img(img, startx + i, starty + j, color);
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
		cub->map->offset2 = (HEIGHT - cub->map->blocksize * cub->map->height) / 2;
		cub->map->offset = (WIDTH - cub->map->blocksize * (cub->map->width - 1)) / 2;
	}
}

void	draw_map(t_cub *cub)
{
	int i;
	int j;
	
	set_map(cub);
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

	i = 0;
	while (i < cub->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(cub->map->grid[i]))
		{
			if (cub->map->grid[i][j] == WALL)
				ft_put_square(cub->mlx->map, cub->map->blocksize * j + cub->map->offset, cub->map->blocksize
						* i + cub->map->offset2, cub->map->blocksize, 0x90007EFF);
			else if (cub->map->grid[i][j] == FLOOR)
				ft_put_square(cub->mlx->map, cub->map->blocksize * j + cub->map->offset, cub->map->blocksize
						* i + cub->map->offset2, cub->map->blocksize, 0x90FFFFFF);
			else if (cub->map->grid[i][j] == SOUTH || cub->map->grid[i][j] == NORTH
					|| cub->map->grid[i][j] == EAST || cub->map->grid[i][j] == WEST)
				ft_put_square(cub->mlx->map, cub->map->blocksize * j + cub->map->offset, cub->map->blocksize
						* i + cub->map->offset2, cub->map->blocksize, 0x90ECC8E5);
			j++;
		}
		i++;
	}
	ft_put_square(cub->mlx->map, cub->ray->p_x * cub->map->blocksize + cub->map->offset - cub->map->blocksize
			/ 4, cub->ray->p_y * cub->map->blocksize + cub->map->offset2 - cub->map->blocksize / 4, cub->map->blocksize
			/ 2, 0x90FF00FF);
}
