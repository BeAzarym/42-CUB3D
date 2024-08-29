/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:49 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/29 11:19:38 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixel_on_img(t_img *img, int x, int y, int color)
{
	// int		bits;
	// int		length;
	// int		endian;
	char	*dst;

	// mlx->address = mlx_get_data_addr(mlx->img, &bits, &length, &endian);
	if (x < 0 || y < 0 || x > WIDTH - 1 || y > HIGHT - 1)
		return ;
	printf("%p: (%d, %d)\n", img->addr, x, y);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
