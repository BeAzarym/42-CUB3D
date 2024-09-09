/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:49 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:51:40 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixel_on_img(t_img *img, int x, int y, int color)
{
	int	*dst;

	if (x < 0 || y < 0 || x > WIDTH - 1 || y > HEIGHT - 1)
		return ;
	dst = (int *)(img->addr + (y * img->size_line + x * (img->bpp / 8)));
	*dst = color;
}
