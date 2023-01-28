/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:33 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		panic(NULL, INVALID_NBR_ARGS);
	if (*argv[1] == '\0')
		panic(NULL, NULL_MAP);
}

int	main(int argc, char **argv)
{
	t_game	game;

	args_check(argc, argv);
	game = init_game();
	get_map(argv[1], &game);
	map_check(&game);
	init_mlx(&game);
	get_tilemap(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
