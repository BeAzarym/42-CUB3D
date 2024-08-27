/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:17:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/09 11:20:30 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_charset(char c, char *charset)
{
	if (!charset)
		return (-1);
	while (*charset)
	{
		if (c == *charset)
			return (TRUE);
		charset++;
	}
	return (FALSE);
}

int	is_only_digit(char *s)
{
	int	i;

	if (!s)
		return (FALSE);
	i = 0;
	while (s[i])
	{
		if ((ft_isdigit(s[i]) == FALSE) && (s[i] != '+' && s[i] != '-'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
