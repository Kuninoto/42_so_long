/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/25 23:17:08 by nnuno-ca         ###   ########.fr       */
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

typedef struct s_coords {
	int	x;
	int	y;
}				t_coords;

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_coords		player_coords;
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
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	t_tilemap	**tile_map;
	int			moves;
}				t_game;

void	handle_error(char *error_msg);

t_game	*init_game(char *map_path);
t_map	*get_map(char *map_file);

t_map	*init_map(void);
void	init_tilemap(t_game *game);

void	map_check(t_map	*map);
void	path_check(t_map *map);
void	open_xpm(t_game *game);

void	render_tilemap(t_game *game);

int 	close_game(void);
int		on_press(int key, t_game *game);

void	init_mlx(t_game *game);

#endif