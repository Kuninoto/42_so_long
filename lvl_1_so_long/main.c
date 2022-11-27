/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 14:21:20 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		handle_error("Invalid number of arguments");
	if (*argv[1] == '\0')
		handle_error("NULL map argument");
}

int	main(int argc, char **argv)
{
	t_game	game;

	args_check(argc, argv);
	init_game(&game);
	get_map(argv[1], &game);
	map_check(&game);
	init_mlx(&game);
	get_tilemap(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
