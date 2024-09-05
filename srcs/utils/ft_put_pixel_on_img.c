/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:49 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 13:46:25 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixel_on_img(t_img *img, int x, int y, int color)
{
	int	*dst;

	if (x < 0 || y < 0 || x > HALFWIDTH - 1 || y > HEIGHT - 1)
		return ;
	dst = (int *)(img->addr + (y * img->size_line + x * (img->bpp / 8)));
	*dst = color;
}
