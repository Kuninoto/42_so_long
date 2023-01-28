/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:03:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/28 16:03:00 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**blank_grid(t_game *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!grid)
		panic(game, MALLOC_ERR);
	while (i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.map[i]);
		if (!grid[i])
		{
			free_matrix(grid);
			panic(game, MALLOC_ERR);
		}
		i += 1;
	}
	return (grid);
}

static bool	flood_fill(t_map *map, t_point curr, char **sol_grid)
{
	static int		coins = 0;
	static bool		found_exit = false;

	if (sol_grid[curr.y][curr.x] == WALL)
		return (false);
	else if (sol_grid[curr.y][curr.x] == COLLECTIBLE)
		coins += 1;
	else if (sol_grid[curr.y][curr.x] == EXIT)
		found_exit = true;
	sol_grid[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid);
	return (coins == map->collectibles && found_exit);
}

void	check_path(t_game *game)
{
	char	**sol_grid;

	sol_grid = blank_grid(game);
	if (!flood_fill(&game->map, game->map.player_pos, sol_grid))
		panic(game, UNACHIEVABLE_ENTITIES);
	free_matrix(sol_grid);
}
