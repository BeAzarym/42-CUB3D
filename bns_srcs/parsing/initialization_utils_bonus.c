/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:24:53 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/06 15:38:06 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_keys	*init_keys(t_keys *keys)
{
	keys = malloc(sizeof(t_keys));
	if (!keys)
		return (NULL);
	keys->forward = FALSE;
	keys->back = FALSE;
	keys->right = FALSE;
	keys->left = FALSE;
	keys->rotate_right = FALSE;
	keys->rotate_left = FALSE;
	keys->big_map = FALSE;
	keys->map = FALSE;
	return (keys);
}

t_map	*init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->blocksize = 0;
	map->offset = 0;
	return (map);
}
