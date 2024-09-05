/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:54:13 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 12:29:07 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



void	draw_texture(t_cub *cub, int x)
{
	int	y;
	int	color;

	y = cub->ray->start;

	if (cub->ray->side == 0)
		cub->ray->wall_x = cub->ray->p_y + cub->ray->wall_dist * cub->ray->ray_y;
	else
		cub->ray->wall_x = cub->ray->p_x + cub->ray->wall_dist * cub->ray->ray_x;
	cub->ray->wall_x -= floor(cub->ray->wall_x); // check si c utile la fonction

	cub->ray->tex_x = (int)(cub->ray->wall_x * (double)cub->img[cub->ray->texture_num].width);
	if (cub->ray->side == 0 && cub->ray->ray_x > 0)
		cub->ray->tex_x = cub->img[cub->ray->texture_num].width - cub->ray->tex_x - 1;
	else if (cub->ray->side == 1 && cub->ray->ray_y < 0)
		cub->ray->tex_x = cub->img[cub->ray->texture_num].width - cub->ray->tex_x - 1;

	cub->ray->step = 1.0 * cub->img[cub->ray->texture_num].height / cub->ray->line_height;
	cub->ray->tex_pos = (cub->ray->start - HEIGHT / 2 + cub->ray->line_height / 2) * cub->ray->step;
	while (y < cub->ray->end)
	{
		cub->ray->tex_y = (int)cub->ray->tex_pos & (cub->img[cub->ray->texture_num].height - 1);
		cub->ray->tex_pos += cub->ray->step;
		color = (cub->img[cub->ray->texture_num].xpm_addr[(cub->ray->tex_y * cub->img[cub->ray->texture_num].width) + (cub->ray->tex_x)]);
		ft_put_pixel_on_img(cub->mlx->raycast, x, y, color);
		y++;
	}
	
	int	p0[2];
	int	p1[2];
	int	blocksize;
	int	offset[2];

	if (cub->map_height > cub->map_width)
		blocksize = HEIGHT / cub->map_height;
	else
		blocksize = HALFWIDTH / cub->map_width;
	offset[0] = (HALFWIDTH - blocksize * (cub->map_width - 1)) / 2;
	offset[1] = (HEIGHT - blocksize * (cub->map_height)) / 2;
	p0[0] = blocksize * (cub->ray->p_x) + offset[0];
	p0[1] = blocksize * (cub->ray->p_y) + offset[1];
	if (cub->ray->side == 0)
	{
		p1[0] = blocksize * (cub->ray->p_x + cub->ray->wall_dist * cub->ray->ray_x) + offset[0];
		p1[1] = blocksize * (cub->ray->p_y + cub->ray->wall_dist * cub->ray->ray_y) + offset[1];
	}
	else
	{
		p1[0] = blocksize * (cub->ray->p_x + cub->ray->wall_dist * cub->ray->ray_x) + offset[0];
		p1[1] =  blocksize * (cub->ray->p_y + cub->ray->wall_dist * cub->ray->ray_y) + offset[1];
	}
	ft_put_line(cub->mlx->map, p0, p1, 0x90FF0000);
	
}

void	decide_wall(t_cub *cub)
{
	if (cub->ray->side == 0)
	{
		if (cub->ray->ray_x > 0)
			cub->ray->texture_num = NO;
		else
			cub->ray->texture_num = SO;
	}
	else
	{
		if (cub->ray->ray_y > 0)
			cub->ray->texture_num = EA;
		else
			cub->ray->texture_num = WE;
	}
}