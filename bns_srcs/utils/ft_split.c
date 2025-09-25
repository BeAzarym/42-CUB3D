/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:54:20 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/07 16:05:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	ft_count_word(char const *s, char *c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && is_valid_charset(*s, c))
			s++;
		if (*s)
			count++;
		while (*s && !is_valid_charset(*s, c))
			s++;
	}
	return (count);
}

static void	*free_all_tab(char **strs, int size)
{
	while (--size >= 0)
		free(strs[size]);
	free(strs);
	return (NULL);
}

static char	*ft_extract_word(const char *s, char *c)
{
	char		*word;
	const char	*save;
	size_t		i;

	save = s;
	i = 0;
	while (*s && !is_valid_charset(*s, c))
	{
		i++;
		s++;
	}
	word = ft_substr(save, 0, i);
	return (word);
}

char	**ft_split(char const *s, char *c)
{
	char	**strs;
	char	**save;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char const *) * (ft_count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	save = strs;
	while (*s)
	{
		while (*s && is_valid_charset(*s, c))
			s++;
		if (!*s)
			break ;
		*strs = ft_extract_word(s, c);
		if (!*strs)
			return (free_all_tab(save, (strs - save) + 1));
		strs++;
		while (*s && !is_valid_charset(*s, c))
			s++;
	}
	*strs = NULL;
	return (save);
}
