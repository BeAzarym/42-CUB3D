/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_struct_initialization.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:24:53 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/27 16:32:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_keys	*init_keys(t_keys *keys)
{
	keys = malloc(sizeof(t_keys *));
	if (!keys)
		return (NULL);
	keys->forward = FALSE;
	keys->back = FALSE;
	keys->right = FALSE;
	keys->left = FALSE;
	keys->rotate_right = FALSE;
	keys->rotate_left = FALSE;
	return (keys);
}
