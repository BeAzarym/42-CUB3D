/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:54:23 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/27 13:59:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = NULL;
	if (arg_parser(argc, argv) != SUCCESS)
		return (FAIL);
	cub = struct_initialization(cub, argv[1]);
	if (!cub)
		return (FAIL);
	if (parser(cub) != SUCCESS)
		clean_exit(cub, FAIL);
	// start to render
	clean_exit(cub, SUCCESS);
}
