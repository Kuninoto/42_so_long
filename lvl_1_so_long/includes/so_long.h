/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 22:16:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "./images.h"
# include "./keys.h"

void	handle_error(char *error_msg);

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

typedef struct s_game {
	t_map	*map;
	void	*mlx_ptr;
	void	*win_ptr;

	int		player_moves;
	
}				t_game;

t_game	*init_game(void);
t_map	*init_map(void);
t_map	*get_map(char *map_file);
void	map_check(t_map	*map);
void	path_check(t_map *map);

int 	close_win_x(void);
int		on_press(int key);
void	init_mlx(t_game *game);

#endif