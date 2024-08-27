/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:06:47 by lolemmen          #+#    #+#             */
/*   Updated: 2024/08/07 00:00:20 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixel_on_img(t_mlx *mlx, int x, int y, int color)
{
	int		bits;
	int		length;
	int		endian;
	char	*dst;

	mlx->address = mlx_get_data_addr(mlx->img, &bits, &length, &endian);
	dst = mlx->address + (y * length + x * (bits / 8));
	*(unsigned int *)dst = color;
}
