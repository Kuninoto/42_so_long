/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:24:00 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/08 23:27:19 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_tile(t_game *game)
{
	char	*moves_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.wall, 0, 0);
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves_str);
	free(moves_str);
}

static void	which_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == COLLECTIBLE)
	{
		game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] = OPEN_SPACE;
		game->tile_map[game->map.player_pos.y]
		[game->map.player_pos.x].img = game->tiles.floor;
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == EXIT
		&& game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		quit_game(game);
	}
}

static void	update_left_behind_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == EXIT)
	{
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.exit,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
	}
	else
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
}

void	update_player_pos(t_game *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_pos.y]
			[game->map.player_pos.x + length] == WALL)
			return ;
		update_left_behind_tile(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == WALL)
			return ;
		update_left_behind_tile(game);
		game->map.player_pos.y += length;
	}
	which_tile(game);
	put_player_tile(game);
}
