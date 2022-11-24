/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:15:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 22:15:32 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*clean_newline(char	*line)
{
	char	*clean;

	clean = ft_substr(line, 0, (ft_strlen(line) - 1));
	free(line);
	return (clean);
}

void	check_extension(char *map_file)
{
	int		i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) != 0)
		handle_error("Wrong map file extension");
}

void	get_nbr_rows(char *map_file, t_map *map)
{
	int		counter;
	int		map_fd;
	char	*first_line;

	counter = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		handle_error("Couldn't open map's file");
	first_line = get_next_line(map_fd);
	if (first_line)
	{
		ft_strlen(first_line);
		counter++;
	}
	while (get_next_line(map_fd))
		counter++;
	if (counter == 0)
		handle_error("Map file is empty");
	map->rows = counter;
	close(map_fd);
}

void	get_lines(char *map_file, t_map *map)
{
	int		map_fd;
	int		i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		handle_error("Couldn't open map's file");
	i = 0;
	while (i < map->rows)
		map->map[i++] = get_next_line(map_fd);
	map->map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (map->rows - 1))
	{
		map->map[i] = clean_newline(map->map[i]);
		i++;
	}
	map->columns = ft_strlen(map->map[0]);
}

t_map	*get_map(char *map_file)
{
	t_map	*map;

	check_extension(map_file);
	map = init_map();
	get_nbr_rows(map_file, map);
	map->map = malloc((map->rows + 1) * sizeof(char *));
	get_lines(map_file, map);
	map_check(map);
	return (map);
}

/* 
		1111111111111
		10010000000C1
		1000011111001
		1P0011E000001
		1111111111111 
*/
/*
	0 for an empty space,
	1 for a wall,
	C for a collectible,
	E for a map exit,
	P for the player’s starting position
*/