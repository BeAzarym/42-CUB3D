/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:47:01 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/05 14:24:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_map(char *input);
static int	have_file_data_path(t_data *data);
static int	fill_struct(t_cub *cub, char *input, int in_map);
static int	fill_map(t_cub *cub, char *input);

int	parser(t_cub *cub)
{
	char	*input;
	int		in_map;

	in_map = FALSE;
	while (TRUE)
	{
		input = get_next_line(cub->infile_fd);
		if (!input || input[0] == '\0')
			break ;
		if (fill_struct(cub, input, in_map) == FAIL)
		{
			free(input);
			return (FAIL);
		}
		free(input);
		if (cub->map->grid)
			in_map = TRUE;
	}
	if (!cub->map->grid)
		return (ft_error(ERR_MISSING_MAP, FAIL));
	if (parse_map(cub) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	is_map(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_valid_charset(input[i], " 10NSWE\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	have_file_data_path(t_data *data)
{
	if (data->no_path == NULL || data->so_path == NULL
		|| data->we_path == NULL || data->ea_path == NULL)
		return (FALSE);
	if (data->floor == 0 || data->ceiling == 0)
		return (FALSE);
	return (TRUE);
}

static int	fill_struct(t_cub *cub, char *input, int in_map)
{
	if (input[0] == '\n' && in_map == TRUE)
		return (ft_error(ERR_NEW_LINE_IN_MAP, FAIL));
	if (input[0] != '\n')
	{
		if (have_file_data_path(cub->data) == FALSE && is_map(input) == TRUE)
			return (ft_error(ERR_MISSING_DATA, FAIL));
		if (have_file_data_path(cub->data) == FALSE)
			return (parse_data_file(cub->data, input));
		if (have_file_data_path(cub->data) == TRUE)
			return (fill_map(cub, input));
	}
	return (SUCCESS);
}

static int	fill_map(t_cub *cub, char *input)
{
	if (is_map(input) == FALSE)
		return (ft_error(ERR_INVALID_CHARSET_IN_MAP, FAIL));
	cub->map->grid = array_add_back(cub->map->grid, input);
	return (SUCCESS);
}
