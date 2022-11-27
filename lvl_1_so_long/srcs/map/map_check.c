/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:38:12 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 03:12:52 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	errors(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		handle_error("Invalid number of Exits (E)");
	if (game->map.collectibles == 0)
		handle_error("Map doesn't have any Collectible (C)");
	if (game->map.player == 0 || game->map.player > 1)
		handle_error("Invalid number of Starting Positions (P)");
}

void	elements_check(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (ft_strchr("ECP01", game->map.map[i][j]) == NULL)
				handle_error("Invalid character on map's file");
			if (game->map.map[i][j] == 'E')
				game->map.exit++;
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			else if (game->map.map[i][j] == 'P')
			{
				game->map.player_x = i;
				game->map.player_y = j;
				game->map.player++;
			}
		}
	}
	errors(game);
}

void	closed_check(t_game *game)
{
	int		rows;
	int		columns;
	int		i;
	int		j;

	rows = game->map.rows;
	columns = game->map.columns;
	i = 0;
	j = 0;
	while (game->map.map[i][j] || game->map.map[rows - 1][j])
	{
		if (game->map.map[i][j] != '1' || game->map.map[rows - 1][j] != '1')
			handle_error("Map is not closed by walls");
		j++;
	}
	while (game->map.map[i + 1] != NULL)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][columns - 1] != '1')
			handle_error("Map is not closed by walls");
		i++;
	}
}

void	form_check(t_game *game)
{
	int	len;
	int	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != (int)ft_strlen(game->map.map[i]))
			handle_error("Invalid map format");
		i++;
	}
}

void	map_check(t_game *game)
{
	form_check(game);
	closed_check(game);
	elements_check(game);
	path_check(game);
}
