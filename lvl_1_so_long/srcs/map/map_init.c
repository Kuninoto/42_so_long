/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:18:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 18:42:14 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		handle_error("Couldn't allocate memory");
	map->map = NULL;
	map->rows = 0;
	map->columns = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	map->player_coords.x = 0;
	map->player_coords.y = 0;
	map->exit_ok = false;
	map->c_oks = 0;
	return (map);
}
