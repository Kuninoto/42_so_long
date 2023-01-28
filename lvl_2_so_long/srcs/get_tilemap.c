/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tilemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:20:29 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 16:03:22 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_error_on_xpms(t_game *game)
{	
	if (!game->tiles.wall)
		panic(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.player)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		panic(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		panic(game, EXIT_XPM_ERR);
}

void	open_xpm(t_game *game)
{	
	int	img_size;

	img_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	check_error_on_xpms(game);
}

void	init_tilemap(t_game *game)
{
	int		i;
	int		j;

	game->tile_map = malloc((game->map.rows) * sizeof(t_tilemap *));
	if (!game->tile_map)
		panic(game, MALLOC_ERR);
	i = -1;
	while (++i < game->map.rows)
	{
		game->tile_map[i] = malloc((game->map.columns) * sizeof(t_tilemap));
		if (!game->tile_map[i])
			panic(game, MALLOC_ERR);
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				game->tile_map[i][j].img = game->tiles.wall;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->tile_map[i][j].img = game->tiles.collectible;
			else if (game->map.map[i][j] == EXIT)
				game->tile_map[i][j].img = game->tiles.exit;
			else
				game->tile_map[i][j].img = game->tiles.floor;
		}
	}
}

void	render_tilemap(t_game *game)
{
	int		i;
	int		j;
	char	*moves;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (i != game->map.player_pos.x || j != game->map.player_pos.y)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tile_map[i][j].img, TILE_SIZE * j, TILE_SIZE * i);
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.y, TILE_SIZE * game->map.player_pos.x);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, TILE_SIZE,
		TILE_SIZE, -1, moves);
	free(moves);
}

void	get_tilemap(t_game *game)
{
	open_xpm(game);
	init_tilemap(game);
	render_tilemap(game);
}
