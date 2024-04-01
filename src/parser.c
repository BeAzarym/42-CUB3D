/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:47:27 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 17:59:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int is_valid_char(int c);

void parse_argment(char **arg, t_game_data *ptr)
{
	int fd;
	char *line;

	fd = open(arg[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(ptr, ERR_OPEN));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (is_texture_path(line) || is_color(line))
			set_data(line, ptr);
		if (is_map(line))
			fill_map(line, ptr);
		if (!is_texture_path(line) && !is_color(line) && !is_map(line) && (ft_strcmp(line, "\n") != 0))
		{
			free(line);
			ft_error(ptr, ERR_CONFIG);
		}
		free(line);
	};
	close(fd);
}

int is_map(char *line)
{
	if (!line)
		return (0);
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (is_valid_char(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int is_valid_char(int c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
int is_texture_path(char *key)
{
	char **buffer;

	buffer = ft_split(key, ' ');
	if (!buffer)
		return (0);
	if (ft_strcmp(buffer[0], "NO") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	if (ft_strcmp(buffer[0], "SO") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	if (ft_strcmp(buffer[0], "WE") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	if (ft_strcmp(buffer[0], "EA") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	ft_array_clear(buffer);
	return (0);
}

int is_color(char *key)
{
	char **buffer;

	buffer = ft_split(key, ' ');
	if (!buffer)
		return (0);

	if (ft_strcmp(buffer[0], "F") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	if (ft_strcmp(buffer[0], "C") == 0)
	{
		ft_array_clear(buffer);
		return (1);
	}
	ft_array_clear(buffer);
	return (0);
}
