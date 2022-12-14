/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:15:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 03:22:50 by nnuno-ca         ###   ########.fr       */
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

void	get_nbr_rows(char *map_file, t_game *game)
{
	int		counter;
	int		map_fd;

	counter = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		handle_error("Couldn't open map's file");
	while (get_next_line(map_fd))
		counter++;
	if (counter == 0)
		handle_error("Map file is empty");
	game->map.rows = counter;
	close(map_fd);
}

void	get_lines(char *map_file, t_game *game)
{
	int		map_fd;
	int		i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		handle_error("Couldn't open map's file");
	i = 0;
	while (i < game->map.rows)
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (game->map.rows - 1))
	{
		game->map.map[i] = clean_newline(game->map.map[i]);
		i++;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	check_extension(map_file);
	get_nbr_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	get_lines(map_file, game);
}
