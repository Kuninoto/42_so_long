/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:03:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 17:55:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	**blank_grid(t_map *map)
{
	int		**grid;
	int		i;
	int		j;

	grid = malloc((map->rows + 1) * sizeof(int *));
	i = -1;
	j = -1;
	while (++i < map->rows)
	{
		grid[i] = malloc((map->columns + 1) * sizeof(int));
		j = -1;
		while (++j < map->columns)
			grid[i][j] = 0;
		grid[i][j] = '\0';
	}
	grid[i] = NULL;
	return (grid);
}

bool	is_valid(t_map *map, int i, int j)
{
	if (i >= 0 && i < map->rows && j >= 0 && j < map->columns
		&& map->map[i][j] != '1')
		return (true);
	return (false);
}

int	find_path(t_map *map, int i, int j, int **sol_grid)
{
	if (map->map[i][j] == 'E')
		map->exit_ok = true;
	if (map->map[i][j] == 'C' && sol_grid[i][j] != 1)
		map->c_oks++;
	if (sol_grid[i][j] == 1)
		return (map->c_oks);
	if (is_valid(map, i, j) == false)
		return (map->c_oks);
	sol_grid[i][j] = 1;
	map->c_oks = find_path(map, i + 1, j, sol_grid);
	map->c_oks = find_path(map, i, j + 1, sol_grid);
	map->c_oks = find_path(map, i - 1, j, sol_grid);
	map->c_oks = find_path(map, i, j - 1, sol_grid);
	return (map->c_oks);
}

void	path_check(t_map *map)
{
	int		**sol_grid;

	sol_grid = blank_grid(map);
	if (find_path(map, map->player_coords.x, map->player_coords.y, sol_grid)
		!= map->collectibles)
		handle_error("Unachievable Collectibles (C) in the map");
	free(sol_grid);
	if (map->exit_ok == false)
		handle_error("Map's Exit (E) is unachievable");
}
