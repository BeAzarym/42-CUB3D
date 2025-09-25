/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:06:41 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/06 19:29:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*gnl_strjoin(char *s1, char *s2, int *check_newline)
{
	char	*str;
	int		len_str;
	int		len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_str = len_s1 + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (*s1)
		*str++ = *s1++;
	free (s1 - len_s1);
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	if (len_str > 0 && *(str - 1) == '\n')
		*check_newline = 0;
	return (str - len_str);
}

static char	*gnl_strdup(char *str, int *check_newline)
{
	char	*dup;
	int		i;
	int		len;

	i = -1;
	len = -1;
	while (str[++len])
	{
		if (str[len] == '\n')
		{
			len++;
			break ;
		}
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = str[i];
	dup[i] = '\0';
	if (len > 0 && dup[i - 1] == '\n')
		*check_newline = i - 1;
	return (dup);
}

static int	check_endline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*get_line(char *line, char *buffer, int *check_newline, int fd)
{
	int		line_size;
	int		read_check;
	char	read_buffer[BUFFER_SIZE + 1];

	while (*check_newline == -1)
	{
		ft_bzero(read_buffer, (BUFFER_SIZE + 1));
		read_check = read(fd, read_buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			ft_bzero(buffer, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_size = check_endline(read_buffer);
		ft_strlcpy(buffer, &read_buffer[line_size], (BUFFER_SIZE + 1));
		ft_strlcpy(read_buffer, read_buffer, line_size + 1);
		line = gnl_strjoin(line, read_buffer, check_newline);
		if (read_check == 0)
		{
			ft_bzero(buffer, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			check_newline;

	if ((fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	check_newline = -1;
	line = gnl_strdup(buffer[fd], &check_newline);
	if (!line)
		return (NULL);
	ft_strlcpy(buffer[fd], &buffer[fd][check_newline + 1], BUFFER_SIZE + 1);
	line = get_line(line, buffer[fd], &check_newline, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
