/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:35:45 by cchabeau          #+#    #+#             */
/*   Updated: 2024/04/01 18:18:36 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_map(char *line, t_game_data *ptr)
{
	char	*new_line;

	if (!line || !ptr)
		return ;
	new_line = ft_substr(line, 0, (ft_strlen(line) - 1));
	ptr->map = array_add_back(ptr->map, new_line);
	free(new_line);
	if (!ptr->map)
		ft_error(ptr, ERR_MALLOC);
}
