/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschor <bschor@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:55:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/06 15:37:29 by bschor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	key_press(int key_code, t_cub *cub)
{
	if (key_code == ESC)
		clean_exit(cub, SUCCESS);
	if (key_code == W || key_code == Z)
		cub->key->forward = TRUE;
	if (key_code == S)
		cub->key->back = TRUE;
	if (key_code == A || key_code == Q)
		cub->key->left = TRUE;
	if (key_code == D)
		cub->key->right = TRUE;
	if (key_code == LEFT_ARROW)
		cub->key->rotate_left = TRUE;
	if (key_code == RIGHT_ARROW)
		cub->key->rotate_right = TRUE;
	if (key_code == UP)
		cub->key->map = TRUE;
	if (key_code == DOWN)
		cub->key->map = FALSE;
	if (key_code == M)
		cub->key->big_map = TRUE;
	return (0);
}

int	key_release(int key_code, t_cub *cub)
{
	if (key_code == W || key_code == Z)
		cub->key->forward = FALSE;
	if (key_code == S)
		cub->key->back = FALSE;
	if (key_code == A || key_code == Q)
		cub->key->left = FALSE;
	if (key_code == D)
		cub->key->right = FALSE;
	if (key_code == LEFT_ARROW)
		cub->key->rotate_left = FALSE;
	if (key_code == RIGHT_ARROW)
		cub->key->rotate_right = FALSE;
	if (key_code == M)
		cub->key->big_map = FALSE;
	return (0);
}

int	ft_red_cross(t_cub *cub, int code)
{
	clean_exit(cub, code);
	return (SUCCESS);
}
