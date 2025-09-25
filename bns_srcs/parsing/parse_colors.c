/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:39:57 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/09 14:20:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_color_value(char **buffer);
static int	parse_floor(t_data *data, char **color_id);
static int	parse_ceiling(t_data *data, char **color_id);
static int	fill_color(int color, char **buffer);

int	parse_colors(t_data *data, char **buffer)
{
	if (!ft_strncmp(buffer[0], "F", ft_strlen(buffer[0])))
	{
		if (parse_floor(data, buffer) == SUCCESS)
		{
			ft_array_clear(buffer);
			return (SUCCESS);
		}
	}
	if (!ft_strncmp(buffer[0], "C", ft_strlen(buffer[0])))
	{
		if (parse_ceiling(data, buffer) == SUCCESS)
		{
			ft_array_clear(buffer);
			return (SUCCESS);
		}
	}
	ft_array_clear(buffer);
	return (FAIL);
}

static int	fill_color(int color, char **buffer)
{
	color |= (ft_atoi(buffer[0]) << 16);
	color |= (ft_atoi(buffer[1]) << 8);
	color |= ft_atoi(buffer[2]);
	return (color);
}

static int	check_color_value(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (is_only_digit(buffer[i]) == FALSE)
			return (FAIL);
		if (ft_atoi(buffer[i]) < 0 || ft_atoi(buffer[i]) > 255)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	parse_floor(t_data *data, char **color_id)
{
	char	**buffer;

	if (data->floor != 0)
		return (ft_error(ERR_DUPLICATE_FLOOR, FAIL));
	buffer = ft_split(color_id[1], ",");
	if (!buffer)
		return (ft_error(ERR_MALLOC_FAILLED, FAIL));
	if (ft_arraylen(buffer) != 3)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_INVALID_COLOR_FORMAT, FAIL));
	}
	if (check_color_value(buffer) == FAIL)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_INVALID_COLOR_PARAM, FAIL));
	}
	data->floor = fill_color(data->floor, buffer);
	ft_array_clear(buffer);
	return (SUCCESS);
}

static int	parse_ceiling(t_data *data, char **color_id)
{
	char	**buffer;

	if (data->ceiling != 0)
		return (ft_error(ERR_DUPLICATE_CEILING, FAIL));
	buffer = ft_split(color_id[1], ",");
	if (!buffer)
		return (ft_error(ERR_MALLOC_FAILLED, FAIL));
	if (ft_arraylen(buffer) != 3)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_INVALID_COLOR_FORMAT, FAIL));
	}
	if (check_color_value(buffer) == FAIL)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_INVALID_COLOR_PARAM, FAIL));
	}
	data->ceiling = fill_color(data->ceiling, buffer);
	ft_array_clear(buffer);
	return (SUCCESS);
}
