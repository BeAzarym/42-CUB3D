/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:50:41 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:40:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	fill_north_assets(t_data *data, char **buffer);
static int	fill_south_assets(t_data *data, char **buffer);
static int	fill_east_assets(t_data *data, char **buffer);
static int	fill_west_assets(t_data *data, char **buffer);

int	fill_assests(t_data *data, char **buffer)
{
	if (extension_parser(buffer[1], ".xpm") != SUCCESS)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_INVALID_FILE_EXTENSION, FAIL));
	}
	if (!ft_strncmp(buffer[0], "NO", ft_strlen(buffer[0])))
		return (fill_north_assets(data, buffer));
	if (!ft_strncmp(buffer[0], "SO", ft_strlen(buffer[0])))
		return (fill_south_assets(data, buffer));
	if (!ft_strncmp(buffer[0], "EA", ft_strlen(buffer[0])))
		return (fill_east_assets(data, buffer));
	if (!ft_strncmp(buffer[0], "WE", ft_strlen(buffer[0])))
		return (fill_west_assets(data, buffer));
	ft_array_clear(buffer);
	return (ft_error(ERR_FAIL_TO_FILL_ASSETS, FAIL));
}

static int	fill_north_assets(t_data *data, char **buffer)
{
	if (data->no_path)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_DUPLICATE_NORTH, FAIL));
	}
	if (ft_access(buffer[1]) == SUCCESS)
	{
		data->no_path = ft_strdup(buffer[1]);
		if (!data->no_path)
		{
			ft_array_clear(buffer);
			return (ft_error(ERR_MALLOC_FAILLED, FAIL));
		}
		ft_array_clear(buffer);
		return (SUCCESS);
	}
	ft_array_clear(buffer);
	return (ft_error(ERR_ACCESS_NORTH, FAIL));
}

static int	fill_south_assets(t_data *data, char **buffer)
{
	if (data->so_path)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_DUPLICATE_SOUTH, FAIL));
	}
	if (ft_access(buffer[1]) == SUCCESS)
	{
		data->so_path = ft_strdup(buffer[1]);
		if (!data->so_path)
		{
			ft_array_clear(buffer);
			return (ft_error(ERR_MALLOC_FAILLED, FAIL));
		}
		ft_array_clear(buffer);
		return (SUCCESS);
	}
	ft_array_clear(buffer);
	return (ft_error(ERR_ACCESS_SOUTH, FAIL));
}

static int	fill_east_assets(t_data *data, char **buffer)
{
	if (data->ea_path)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_DUPLICATE_EAST, FAIL));
	}
	if (ft_access(buffer[1]) == SUCCESS)
	{
		data->ea_path = ft_strdup(buffer[1]);
		if (!data->ea_path)
		{
			ft_array_clear(buffer);
			return (ft_error(ERR_MALLOC_FAILLED, FAIL));
		}
		ft_array_clear(buffer);
		return (SUCCESS);
	}
	ft_array_clear(buffer);
	return (ft_error(ERR_ACCESS_EAST, FAIL));
}

static int	fill_west_assets(t_data *data, char **buffer)
{
	if (data->we_path)
	{
		ft_array_clear(buffer);
		return (ft_error(ERR_DUPLICATE_WEST, FAIL));
	}
	if (ft_access(buffer[1]) == SUCCESS)
	{
		data->we_path = ft_strdup(buffer[1]);
		if (!data->we_path)
		{
			ft_array_clear(buffer);
			return (ft_error(ERR_MALLOC_FAILLED, FAIL));
		}
		ft_array_clear(buffer);
		return (SUCCESS);
	}
	ft_array_clear(buffer);
	return (ft_error(ERR_ACCESS_WEST, FAIL));
}
