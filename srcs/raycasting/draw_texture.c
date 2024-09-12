/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:54:13 by bschor            #+#    #+#             */
/*   Updated: 2024/09/12 13:26:29 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_texture_values(t_cub *cub)
{
	if (cub->ray->side == 0)
		cub->ray->wall_x = cub->ray->p_y + cub->ray->wall_dist
			* cub->ray->ray_y;
	else
		cub->ray->wall_x = cub->ray->p_x + cub->ray->wall_dist
			* cub->ray->ray_x;
	cub->ray->wall_x -= (int)(cub->ray->wall_x);
	cub->ray->tex_x = (int)(cub->ray->wall_x
			* (double)cub->img[cub->ray->texture_num].width);
	if (cub->ray->side == 0 && cub->ray->ray_x > 0)
		cub->ray->tex_x = cub->img[cub->ray->texture_num].width
			- cub->ray->tex_x - 1;
	else if (cub->ray->side == 1 && cub->ray->ray_y < 0)
		cub->ray->tex_x = cub->img[cub->ray->texture_num].width
			- cub->ray->tex_x - 1;
	cub->ray->step = 1.0 * cub->img[cub->ray->texture_num].height
		/ cub->ray->line_height;
	cub->ray->tex_pos = (cub->ray->start - HEIGHT / 2
			+ cub->ray->line_height / 2) * cub->ray->step;
}

void	draw_texture(t_cub *cub, int x)
{
	int	y;
	int	color;

	y = cub->ray->start;
	init_texture_values(cub);
	while (y < cub->ray->end)
	{
		cub->ray->tex_y = (int)cub->ray->tex_pos
			& (cub->img[cub->ray->texture_num].height - 1);
		cub->ray->tex_pos += cub->ray->step;
		color = (cub->img[cub->ray->texture_num].xpm_addr[(cub->ray->tex_y
					* cub->img[cub->ray->texture_num].width)
				+ (cub->ray->tex_x)]);
		ft_put_pixel_on_img(cub->mlx->raycast, x, y, color);
		y++;
	}
}

void	decide_wall(t_cub *cub)
{
	if (cub->ray->side == 1)
	{
		if (cub->ray->ray_y > 0)
			cub->ray->texture_num = NO;
		else
			cub->ray->texture_num = SO;
	}
	else
	{
		if (cub->ray->ray_x > 0)
			cub->ray->texture_num = EA;
		else
			cub->ray->texture_num = WE;
	}
}
