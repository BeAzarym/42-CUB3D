/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:16 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/06 19:28:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_array_clear(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
