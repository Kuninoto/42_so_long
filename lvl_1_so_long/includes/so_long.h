/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 03:13:21 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "./tiles.h"
# include "./keys.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

/* typedef struct s_coords {
	int	x;
	int	y;
}				t_coords; */

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	int				player_x;
	int				player_y;
	bool			exit_ok;
	int				c_oks;
}				t_map;

typedef struct s_tilemap
{
	void	*img;
}				t_tilemap;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*enemy;
	void	*coin;
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

void	handle_error(char *error_msg);

void	init_game(t_game *game);

void	get_map(char *map_file, t_game *game);
void	map_check(t_game *game);
void	path_check(t_game *game);

void	init_mlx(t_game *game);
void	get_tilemap(t_game *game);

void	render_tilemap(t_game *game);
void	hook_n_run(t_game *game);

#endif