/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:54:19 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/09 10:51:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	arg_parser(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(ERR_INVALID_COUNT_ARG, FAIL));
	if (extension_parser(argv[1], ".cub") != SUCCESS)
		return (ft_error(ERR_INVALID_MAP_EXTENSION, FAIL));
	if (ft_access(argv[1]) != SUCCESS)
		return (ft_error(ERR_ACCESS_MAP, FAIL));
	return (SUCCESS);
}
