/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:03:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 13:57:44 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	**blank_grid(t_game *game)
{
	int		**grid;
	int		i;
	int		j;

	grid = malloc((game->map.rows + 1) * sizeof(int *));
	i = -1;
	j = -1;
	while (++i < game->map.rows)
	{
		grid[i] = malloc((game->map.columns + 1) * sizeof(int));
		j = -1;
		while (++j < game->map.columns)
			grid[i][j] = 0;
		grid[i][j] = '\0';
	}
	grid[i] = NULL;
	return (grid);
}

bool	is_valid(t_game *game, int i, int j)
{
	if (i >= 0 && i < game->map.rows && j >= 0 && j < game->map.columns
		&& game->map.map[i][j] != '1')
		return (true);
	return (false);
}

int	find_path(t_game *game, int i, int j, int **sol_grid)
{
	if (game->map.map[i][j] == 'E')
		game->map.exit_ok = true;
	if (game->map.map[i][j] == 'C' && sol_grid[i][j] != 1)
		game->map.c_oks++;
	if (sol_grid[i][j] == 1)
		return (game->map.c_oks);
	if (is_valid(game, i, j) == false)
		return (game->map.c_oks);
	sol_grid[i][j] = 1;
	game->map.c_oks = find_path(game, i + 1, j, sol_grid);
	game->map.c_oks = find_path(game, i, j + 1, sol_grid);
	game->map.c_oks = find_path(game, i - 1, j, sol_grid);
	game->map.c_oks = find_path(game, i, j - 1, sol_grid);
	return (game->map.c_oks);
}

void	path_check(t_game *game)
{
	int		**sol_grid;

	sol_grid = blank_grid(game);
	if (find_path(game, game->map.player_x, game->map.player_y, sol_grid)
		!= game->map.collectibles)
		handle_error("Unachievable Collectibles (C) in the map");
	free(sol_grid);
	if (game->map.exit_ok == false)
		handle_error("Map's Exit (E) is unachievable");
}
