/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:07:38 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:30:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_pos(int x, int y, t_cub *cub)
{
	if (x < 0 || y < 0 || x >= cub->map->width || y >= cub->map->height)
		return (FALSE);
	if (is_valid_charset(cub->map->grid[y][x], "0NSEW") == TRUE)
		return (TRUE);
	return (FALSE);
}
