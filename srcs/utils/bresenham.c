/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:34:10 by bschor            #+#    #+#             */
/*   Updated: 2024/09/05 10:43:20 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ALL
// Here, the bresenham algorithm is used and its formla is adapted to 
// suit any of the 8 octants (imagin it with orthogonal rotations)

static void	ft_write_line_pos(t_img *img, int p0[2], int p1[2], int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	p = 2 * dy - dx;
	x = p0[0];
	y = p0[1];
	while (x <= p1[0])
	{
		ft_put_pixel_on_img(img, x, y, color);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}

static void	ft_write_line_neg(t_img *img, int p0[2], int p1[2], int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	p = 2 * dy - dx;
	x = p0[0];
	y = p0[1];
	while (x <= p1[0])
	{
		ft_put_pixel_on_img(img, x, y, color);
		x++;
		if (p > 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy + 2 * dx;
			y--;
		}
	}
}

static void	ft_write_line_neg_steep(t_img *img, int p0[2],
	int p1[2], int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	x = p0[0];
	y = p0[1];
	p = 2 * dx - dy;
	while (y <= p1[1])
	{
		ft_put_pixel_on_img(img, x, y, color);
		y++;
		if (p > 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx + 2 * dy;
			x--;
		}
	}
}

static void	ft_write_line_pos_steep(t_img *img, int p0[2],
	int p1[2], int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	x = p0[0];
	y = p0[1];
	p = 2 * dx - dy;
	while (y <= p1[1])
	{
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			x++;
		}
		ft_put_pixel_on_img(img, x, y, color);
		y++;
	}
}

// FT_PUT_LINE
// Here i check whats the orientation and steep of the line received
// I send the coordinates to the right function accordingly
// There are 2 components in each condition, the first one checks the
// orientation (comparing the coordinates)
// and the second one checks the steep (ratio between the deltas)

void	ft_put_line(t_img *img, int p0[2], int p1[2], int color)
{
	if (p1[0] >= p0[0] && p1[1] > p0[1] && (p1[1] - p0[1]) > (p1[0] - p0[0]))
		ft_write_line_pos_steep(img, p0, p1, color);
	else if (p0[0] >= p1[0] && p0[1] > p1[1]
		&& (p0[1] - p1[1]) > (p0[0] - p1[0]))
		ft_write_line_pos_steep(img, p1, p0, color);
	else if (p1[0] >= p0[0] && p0[1] > p1[1]
		&& (p0[1] - p1[1]) > (p1[0] - p0[0]))
		ft_write_line_neg_steep(img, p1, p0, color);
	else if (p0[0] >= p1[0] && p1[1] > p0[1]
		&& (p1[1] - p0[1]) > (p0[0] - p1[0]))
		ft_write_line_neg_steep(img, p0, p1, color);
	else if (p1[0] > p0[0] && p1[1] >= p0[1])
		ft_write_line_pos(img, p0, p1, color);
	else if (p0[0] > p1[0] && p0[1] >= p1[1])
		ft_write_line_pos(img, p1, p0, color);
	else if (p1[0] > p0[0] && p0[1] >= p1[1])
		ft_write_line_neg(img, p0, p1, color);
	else if (p0[0] > p1[0] && p1[1] >= p0[1])
		ft_write_line_neg(img, p1, p0, color);
	else if (p0[0] == p1[0] && p0[1] == p1[1])
		ft_put_pixel_on_img(img, p0[0], p0[1], color);
}
