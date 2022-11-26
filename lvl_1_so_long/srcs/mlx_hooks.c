/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:46:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/26 01:54:17 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_tile(t_game *game)
{
	if (game->map->map[game->map->player_coords.x][game->map->player_coords.y] == COLLECTIBLE)
	{
		game->map->map[game->map->player_coords.x][game->map->player_coords.x] = OPEN_SPACE;
		game->tile_map[game->map->player_coords.x][game->map->player_coords.y].img
			= game->tiles.floor;
		game->map->collectibles--;
		return ;
	}
	if (game->map->map[game->map->player_coords.x][game->map->player_coords.y] == EXIT
		&& game->map->collectibles == 0)
	{
		ft_printf("---------------- You won! ----------------");
		exit(EXIT_SUCCESS);
	}
}

void	move_player(t_game *game, bool horizontal, int length)
{
	if (horizontal == true)
	{
		if (game->map->map[game->map->player_coords.x][game->map->player_coords.y + length] == WALL)
			return ;
		game->map->player_coords.y += length;
	}
	else
	{
		if (game->map->map[game->map->player_coords.x + length][game->map->player_coords.y] == WALL)
			return ;
		game->map->player_coords.x += length;
	}
	check_tile(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_tilemap(game);
}

int	on_press(int key, t_game *game)
{

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
	
	/* game->moves++;
	ft_printf("moves = %d\n", game->moves ); */
	return (EXIT_SUCCESS);	
}

int close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}