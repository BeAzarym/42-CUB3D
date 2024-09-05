/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:49 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 12:53:40 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_square(t_img *img, int startx, int starty, int size, int color)
{
	int	i;
	int j;

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

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;
	int	blocksize;
	int	offset[2];

	if (cub->map_height > cub->map_width)
		blocksize = HEIGHT / cub->map_height;
	else
		blocksize = HALFWIDTH / cub->map_width;
	offset[0] = (HALFWIDTH - blocksize * (cub->map_width - 1)) / 2;
	offset[1] = (HEIGHT - blocksize * (cub->map_height)) / 2;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WINWIDTH)
		{
			ft_put_pixel_on_img(cub->mlx->map, j, i, 0xFF000000);
			j++;
		}
		i++;
	}

	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width - 1)
		{
			if (cub->map[i][j] == WALL)
				ft_put_square(cub->mlx->map, blocksize * j + offset[0], blocksize * i + offset[1], blocksize - 2, 0x90007EFF);
			else if (cub->map[i][j] == FLOOR)
				ft_put_square(cub->mlx->map, blocksize * j + offset[0], blocksize * i + offset[1], blocksize - 2, 0x90FFFFFF);
			else if (cub->map[i][j] == SOUTH || cub->map[i][j] == NORTH || cub->map[i][j] == EAST || cub->map[i][j] == WEST)
				ft_put_square(cub->mlx->map, blocksize * j + offset[0], blocksize * i + offset[1], blocksize - 2, 0x90ECC8E5);
			j++;
		}
		i++;
	}
	ft_put_square(cub->mlx->map, cub->ray->p_x * blocksize + offset[0] - blocksize / 4, cub->ray->p_y * blocksize + offset[1]  - blocksize / 4, blocksize / 2, 0x90FF00FF);
	
}