/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_n_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:46:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 18:01:32 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.x]
		[game->map.player_pos.y] == COLLECTIBLE)
	{
		game->map.map[game->map.player_pos.x]
		[game->map.player_pos.y] = OPEN_SPACE;
		game->tile_map[game->map.player_pos.x]
		[game->map.player_pos.y].img = game->tiles.floor;
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_pos.x][game->map.player_pos.y] == EXIT
		&& game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		quit_game(game);
	}
}

void	move_player(t_game *game, bool horizontal, int length)
{
	if (horizontal == true)
	{
		if (game->map.map[game->map.player_pos.x]
			[game->map.player_pos.y + length] == WALL)
			return ;
		game->map.player_pos.y += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.x + length]
			[game->map.player_pos.y] == WALL)
			return ;
		game->map.player_pos.x += length;
	}
	check_tile(game);
	game->moves += 1;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_tilemap(game);
}

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		move_player(game, false, -1);
	else if (key == A || key == LEFT)
		move_player(game, true, -1);
	else if (key == S || key == DOWN)
		move_player(game, false, 1);
	else if (key == D || key == RIGHT)
		move_player(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1, on_press, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, quit_game, game);
	mlx_loop(game->mlx_ptr);
}
