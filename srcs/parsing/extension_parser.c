/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:08:45 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/06 20:58:00 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	extension_parser(char *path, char *extension)
{
	char	*str;

	if (!path || !path[0] || !extension || !extension[0])
		return (FAIL);
	if (ft_strlen(path) == ft_strlen(extension))
		return (FAIL);
	str = ft_strrchr(path, '/');
	if (str)
	{
		if (ft_strlen(++str) <= ft_strlen(extension))
			return (FAIL);
	}
	str = ft_strrchr(path, '.');
	return (ft_strncmp(str, extension, ft_strlen(extension)));
}