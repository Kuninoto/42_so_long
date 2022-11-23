/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:38:12 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 18:01:25 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	errors(t_map *map)
{
	if (map->exit == 0 || map->exit > 1)
		handle_error("Invalid number of Exits (E)");
	if (map->collectibles == 0)
		handle_error("Map doesn't have any Collectible (C)");
	if (map->player == 0 || map->player > 1)
		handle_error("Invalid number of Starting Positions (P)");
}

void	elements_check(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_strchr("ECP01", map->map[i][j]) == NULL)
				handle_error("Invalid character on map's file");
			if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'C')
				map->collectibles++;
			else if (map->map[i][j] == 'P')
			{
				map->player_coords.x = i;
				map->player_coords.y = j;
				map->player++;
			}
		}
	}
	errors(map);
}

void	closed_check(t_map *map)
{
	int		rows;
	int		columns;
	int		i;
	int		j;

	rows = map->rows;
	columns = map->columns;
	i = 0;
	j = 0;
	while (map->map[i][j] || map->map[rows - 1][j])
	{
		if (map->map[i][j] != '1' || map->map[rows - 1][j] != '1')
			handle_error("Map is not closed by walls");
		j++;
	}
	while (map->map[i + 1] != NULL)
	{
		if (map->map[i][0] != '1' || map->map[i][columns - 1] != '1')
			handle_error("Map is not closed by walls");
		i++;
	}
}

void	form_check(t_map *map)
{
	int	len;
	int	i;

	len = map->columns;
	i = 0;
	while (map->map[i] != NULL)
	{
		if (len != (int)ft_strlen(map->map[i]))
			handle_error("Invalid map format");
		i++;
	}
}

void	map_check(t_map *map)
{
	form_check(map);
	closed_check(map);
	elements_check(map);
	path_check(map);
}
