/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:36:57 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/20 16:15:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;
	long int		tmp;

	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str++ == 45)
			return (-1);
	}
	if (*str == '\0')
		return (-1);
	while (*str >= 48 && *str <= 57)
	{
		tmp = result;
		result = (result * 10) + (*str++ - 48);
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (-1);
	}
	return ((int)result * sign);
}
