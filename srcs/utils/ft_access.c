/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:30:47 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/06 20:21:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_access(char *src)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (SUCCESS);
	}
	return (FAIL);
}
