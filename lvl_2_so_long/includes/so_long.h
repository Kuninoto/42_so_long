/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 18:09:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "tiles.h"
# include "keys.h"
# include "../mlx/mlx.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define WIN_MSG "\nYou won, that's all folks!\n"

/* ERROR MESSAGES */

# define MALLOC_ERR "malloc() failed"

/* CL arguments validation */
# define INVALID_NBR_ARGS "Invalid number of arguments" 
# define NULL_MAP "NULL map argument"

/* Map validation */

# define INVALID_ENTITY "Invalid entity on map's file"
# define INVALID_FORMAT "Invalid map format"
# define MAP_NOT_CLOSED "Map is not closed by walls"
# define INVALID_NBR_EXITS "Invalid number of Exits (E)"
# define NO_COLLECTIBLES "Map doesn't have any Collectible (C)"
# define INVALID_NBR_PLAYERS "Invalid number of Starting Positions (P)"

# define UNACHIEVABLE_ENTITIES "Map has unachievable entities"

/* Reading map's content */

# define INVALID_MAP_FILE "Invalid map file extension"
# define OPEN_MAP_FILE_ERR "Couldn't open map's file"
# define EMPTY_MAP_FILE "Map file is empty"

/* XPM Opening */

# define WALL_XPM_ERR "Couldn't open wall image"
# define FLOOR_XPM_ERR "Couldn't open floor image"
# define PLAYER_XPM_ERR "Couldn't open player image"
# define COLLECTIBLE_XPM_ERR "Couldn't open collectible image"
# define EXIT_XPM_ERR "Couldn't open exit image"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;

typedef struct s_tilemap
{
	void	*img;
}				t_tilemap;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game {
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	t_tilemap	**tile_map;
	int			moves;
}				t_game;

static inline t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = 0,
	});
}

void	get_map(char *map_file, t_game *game);
void	map_check(t_game *game);

/*	Checks if the map has a valid exit path
and if all entities are achievable */
void	check_path(t_game *game);

void	init_mlx(t_game *game);
void	get_tilemap(t_game *game);

void	render_tilemap(t_game *game);
void	hook_n_run(t_game *game);

int		quit_game(t_game *game);

/* UTILS */

/* Calls destroy() and exits the program on FAILURE */
void	panic(t_game *game, char *error_msg);

/* Destroys game ptr and all its inside fields */
void	destroy(t_game *game);

/* Frees matrix ptr and all its inside fields */
void	free_matrix(char **matrix);

#endif