/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:08:50 by bschor            #+#    #+#             */
/*   Updated: 2024/08/27 15:20:23 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		clean_exit(cub, SUCCESS);
	if (keycode == LEFT_ARROW)
		cub->key->rotate_left = 1;
	if (keycode ==  RIGHT_ARROW)
		cub->key->rotate_right = 1;
	if (keycode == A)
		cub->key->left = 1;
	if (keycode == W)
		cub->key->forward = 1;
	if (keycode == S)
		cub->key->back = 1;
	if (keycode == D)
		cub->key->right = 1;
	return (0);
}


int	key_release(int keycode, t_cub *cub)
{
	if (keycode == LEFT_ARROW)
		cub->key->rotate_left = 0;
	if (keycode ==  RIGHT_ARROW)
		cub->key->rotate_right = 0;
	if (keycode == A)
		cub->key->left = 0;
	if (keycode == W)
		cub->key->forward = 0;
	if (keycode == S)
		scub->key->back = 0;
	if (keycode == D)
		cub->key->right = 0;
	return (0);
}