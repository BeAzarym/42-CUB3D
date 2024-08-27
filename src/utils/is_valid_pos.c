/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:07:38 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/20 14:49:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_pos(int x, int y, t_cub *cub)
{
	if (x < 0 || y < 0 || x >= cub->map_width || y >= cub->map_height)
		return (FALSE);
	if (is_valid_charset(cub->map[y][x], "0NSEW") == TRUE)
		return (TRUE);
	return (FALSE);
}
