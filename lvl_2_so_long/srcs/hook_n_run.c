/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_n_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:46:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 16:43:45 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	check_tile(t_game *game)
{
	if (game->map.map[game->map.player_x][game->map.player_y] == COLLECTIBLE)
	{
		game->map.map[game->map.player_x][game->map.player_y] = OPEN_SPACE;
		game->tile_map[game->map.player_x][game->map.player_y].img
			= game->tiles.floor;
		game->map.collectibles--;
		return ;
	}
	if (game->map.map[game->map.player_x][game->map.player_y] == EXIT
		&& game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		exit(EXIT_SUCCESS);
	}
}

void	move_player(t_game *game, bool horizontal, int length)
{
	if (horizontal == true)
	{
		if (game->map.map[game->map.player_x]
			[game->map.player_y + length] == WALL)
			return ;
		game->map.player_y += length;
	}
	else
	{
		if (game->map.map[game->map.player_x + length]
			[game->map.player_y] == WALL)
			return ;
		game->map.player_x += length;
	}
	check_tile(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_tilemap(game);
}

int	on_press(int key, t_game *game)
{
	game->moves++;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == W || key == UP)
		move_player(game, false, -1);
	else if (key == A || key == LEFT)
		move_player(game, true, -1);
	else if (key == S || key == DOWN)
		move_player(game, false, 1);
	else if (key == D || key == RIGHT)
		move_player(game, true, 1);
	ft_printf("moves = %d\n", game->moves);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1, on_press, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, close_game, NULL);
	mlx_loop(game->mlx_ptr);
}
