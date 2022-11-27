/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:18:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 03:22:28 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map.map = NULL;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->map.player_x = 0;
	game->map.player_y = 0;
	game->map.exit_ok = false;
	game->map.c_oks = 0;
	game->tiles.coin = NULL;
	game->tiles.enemy = NULL;
	game->tiles.exit = NULL;
	game->tiles.floor = NULL;
	game->tiles.player = NULL;
	game->tiles.wall = NULL;
	game->moves = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error("Couldn't initialize mlx");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * TILE_SIZE, 
		game->map.rows * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		handle_error("Couldn't open game window");
}