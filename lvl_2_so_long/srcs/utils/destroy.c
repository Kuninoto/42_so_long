/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:15:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 17:50:29 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_tilemap(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->tile_map[i]);
		game->tile_map[i] = NULL;
		i += 1;
	}
	free(game->tile_map);
	game->tile_map = NULL;
}

void	destroy_tiles(t_game *game)
{
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
	if (game->tiles.player)
		mlx_destroy_image(game->mlx_ptr, game->tiles.player);
	if (game->tiles.collectible)
		mlx_destroy_image(game->mlx_ptr, game->tiles.collectible);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
}

void	destroy(t_game *game)
{
	if (!game || !game->mlx_ptr)
		return ;
	destroy_tiles(game);
	if (game->tile_map)
		destroy_tilemap(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	if (game->map.map)
		free_matrix(game->map.map);
}
