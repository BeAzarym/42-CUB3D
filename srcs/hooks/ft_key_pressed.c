/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:55:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/20 14:44:50 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_pressed(int key_code, t_cub *cub)
{
	if (key_code == ESC)
		clean_exit(cub, SUCCESS);
	if (key_code == W || key_code == Z)
		cub->forward_key = TRUE;
	if (key_code == S)
		cub->back_key = TRUE;
	if (key_code == A || key_code == Q)
		cub->left_key = TRUE;
	if (key_code == D)
		cub->right_key = TRUE;
	if (key_code == LEFT_ARROW)
		cub->rotate_left_key = TRUE;
	if (key_code == RIGHT_ARROW)
		cub->rotate_right_key = TRUE;
	return (0);
}

int	key_relase(int key_code, t_cub *cub)
{
	if (key_code == W || key_code == Z)
		cub->forward_key = FALSE;
	if (key_code == S)
		cub->back_key = FALSE;
	if (key_code == A || key_code == Q)
		cub->left_key = FALSE;
	if (key_code == D)
		cub->right_key = FALSE;
	if (key_code == LEFT_ARROW)
		cub->rotate_left_key = FALSE;
	if (key_code == RIGHT_ARROW)
		cub->rotate_right_key = FALSE;
	return (0);
}
