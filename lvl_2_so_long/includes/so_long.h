/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/08 23:29:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "tiles.h"
# include "keys.h"
# include "error_messages.h"
# include "../mlx/mlx.h"

// CONSTANTS

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "You won, that's all folks!\n"

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
		.moves = -1,
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
void	update_player_pos(t_game *game, bool horizontal, int length);
void 	put_player_tile(t_game *game);
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