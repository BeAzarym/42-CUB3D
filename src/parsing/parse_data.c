/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:37:38 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/09 14:00:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_assets(char *input);
static int	is_color(char *input);

int	parse_data_file(t_data *data, char *input)
{
	char	**buffer;

	buffer = ft_split(input, " \n");
	if (!buffer)
		return (FAIL);
	if (ft_arraylen(buffer) != 2)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_ASSETS_CORRUPTED, FAIL));
	}
	if (is_assets(buffer[0]) == TRUE)
		return (fill_assests(data, buffer));
	else if (is_color(buffer[0]) == TRUE)
		return (parse_colors(data, buffer));
	ft_array_clear(buffer);
	return (ft_error(ERR_BAD_IDENTIFIER, FAIL));
}

static int	is_assets(char *input)
{
	if (ft_strncmp(input, "NO", ft_strlen(input)) == 0)
		return (TRUE);
	if (ft_strncmp(input, "SO", ft_strlen(input)) == 0)
		return (TRUE);
	if (ft_strncmp(input, "EA", ft_strlen(input)) == 0)
		return (TRUE);
	if (ft_strncmp(input, "WE", ft_strlen(input)) == 0)
		return (TRUE);
	return (FALSE);
}

static int	is_color(char *input)
{
	if (ft_strncmp(input, "F", ft_strlen(input)) == 0)
		return (TRUE);
	if (ft_strncmp(input, "C", ft_strlen(input)) == 0)
		return (TRUE);
	return (FALSE);
}
