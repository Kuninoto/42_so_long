/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:18:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 22:34:06 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		handle_error("Couldn't allocate memory");
	map->map = NULL;
	map->rows = 0;
	map->columns = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	map->player_coords.x = 0;
	map->player_coords.y = 0;
	map->exit_ok = false;
	map->c_oks = 0;
	return (map);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error("Couldn't initialize mlx");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->columns * 64, game->map->rows * 64, "so_long");
	if (!game->win_ptr)
		handle_error("Couldn't open game window");
	

	mlx_key_hook(game->win_ptr, on_press, NULL);
	mlx_hook(game->win_ptr, 17, 1L << 17, close_win_x, NULL);
	mlx_loop(game->mlx_ptr);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(game));
	if (!game)
		handle_error("Failed to allocate memory");
	game->map = init_map();
	game->player_moves = 0;
	return (game);
}
