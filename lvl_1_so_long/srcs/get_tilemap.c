/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tilemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:20:29 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 14:35:40 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_on_xpms(t_game *game)
{	
	if (!game->tiles.wall)
		handle_error("Couldn't open wall image");
	if (!game->tiles.floor)
		handle_error("Couldn't open floor image");
	if (!game->tiles.player)
		handle_error("Couldn't open player image");
	if (!game->tiles.enemy)
		handle_error("Couldn't open enemy image");
	if (!game->tiles.coin)
		handle_error("Couldn't open collectible image");
	if (!game->tiles.exit)
		handle_error("Couldn't open exit image");
}

void	open_xpm(t_game *game)
{	
	int	img_size;

	img_size = 64;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->tiles.enemy = mlx_xpm_file_to_image(game->mlx_ptr,
			ENEMY_TILE, &img_size, &img_size);
	game->tiles.coin = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	error_on_xpms(game);
}

void	init_tilemap(t_game *game)
{
	int		i;
	int		j;

	game->tile_map = malloc((game->map.rows) * sizeof(t_tilemap *));
	if (!game->tile_map)
		handle_error("Failed to allocate memory for tilemap");
	i = -1;
	while (++i < game->map.rows)
	{
		game->tile_map[i] = malloc((game->map.columns) * sizeof(t_tilemap));
		if (!game->tile_map[i])
			handle_error("Failed to allocate memory for tilemap");
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				game->tile_map[i][j].img = game->tiles.wall;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->tile_map[i][j].img = game->tiles.coin;
			else if (game->map.map[i][j] == EXIT)
				game->tile_map[i][j].img = game->tiles.exit;
			else
				game->tile_map[i][j].img = game->tiles.floor;
		}
	}
}

void	render_tilemap(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (i != game->map.player_x || j != game->map.player_y)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tile_map[i][j].img, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_y, TILE_SIZE * game->map.player_x);
	mlx_string_put(game->mlx_ptr, game->win_ptr, TILE_SIZE,
		TILE_SIZE, -1, ft_itoa(game->moves));
}

void	get_tilemap(t_game *game)
{
	open_xpm(game);
	init_tilemap(game);
	render_tilemap(game);
}
