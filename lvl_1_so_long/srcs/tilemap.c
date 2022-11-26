/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:20:29 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/26 22:11:34 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_xpm(t_game *game)
{	
	int	img_size;

	img_size = 64;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TILE, &img_size, &img_size);
	printf("OPEN WALL = %p\n", game->tiles.wall);
	if (!game->tiles.wall)
		handle_error("Couldn't open wall image");
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TILE, &img_size, &img_size);
	printf("OPEN FLOOR = %p\n", game->tiles.floor);
	if (!game->tiles.floor)
		handle_error("Couldn't open floor image");
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_TILE, &img_size, &img_size);
	if (!game->tiles.player)
		handle_error("Couldn't open player image");
	game->tiles.enemy = mlx_xpm_file_to_image(game->mlx_ptr, ENEMY_TILE, &img_size, &img_size);
	printf("OPEN ENEMY = %p\n", game->tiles.enemy);
	if (!game->tiles.enemy)
		handle_error("Couldn't open enemy image");
	game->tiles.coin = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTIBLE_TILE, &img_size, &img_size);
	if (!game->tiles.coin)
		handle_error("Couldn't open enemy image");
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_TILE, &img_size, &img_size);
	if (!game->tiles.exit)
		handle_error("Couldn't open exit image");
	printf("OPEN_XPM\n");
}

void	get_tilemap(t_game *game)
{
	int		i;
	int		j;

	printf("GET_TILEMAP\n");
	game->tile_map = malloc((game->map->rows + 1) * sizeof(t_tilemap *));
	if (!game->tile_map)
		handle_error("Failed to allocate memory for tilemap");
	i = -1;
	while (++i < game->map->rows)
	{
		game->tile_map[i] = malloc(((game->map->columns) + 1) * sizeof(t_tilemap));
		if (!game->tile_map[i])
			handle_error("Failed to allocate memory for tilemap");
		j = -1;
		while (++j < game->map->columns)
		{
			if (game->map->map[i][j] == WALL)
			{
				printf("wall = %p\n", game->tiles.wall);
				game->tile_map[i][j].img = game->tiles.wall;
			}
			else if (game->map->map[i][j] == COLLECTIBLE)
				game->tile_map[i][j].img = game->tiles.coin;
			else if (game->map->map[i][j] == EXIT)
				game->tile_map[i][j].img = game->tiles.exit;
	 	 	else
			{
				printf("floor = %p\n", game->tiles.floor);
				game->tile_map[i][j].img = game->tiles.floor;
			}
		}
	}
	game->tile_map[i] = NULL;
}

void	render_tilemap(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	printf("RENDER_TILEMAP\n");
	while (++i < game->map->rows)
	{
		j = -1;
		while (++j < game->map->columns)
		{
			printf("[%d][%d]\n", i, j);
			if (i != game->map->player_coords.x || j != game->map->player_coords.y)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tile_map[i][j].img, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
/* 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->tiles.player, TILE_SIZE * game->map->player_coords.y, 
		TILE_SIZE * game->map->player_coords.x); */
	printf("FINISH RENDER_TILEMAP\n");
}

void	init_tilemap(t_game *game)
{
	printf("INIT_TILEMAP\n");
	open_xpm(game);
	get_tilemap(game);
	render_tilemap(game);
}