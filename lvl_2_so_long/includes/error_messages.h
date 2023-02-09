/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:22:03 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:28:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/* ERROR MESSAGES */

# define MALLOC_ERR "malloc() failed"

# define MLX_INIT_ERR "Failed to initialize mlx"
# define MLX_NEW_WINDOW_ERR "Failed to open a new window"

/* CL arguments validation */
# define INVALID_NBR_ARGS "Invalid number of arguments" 
# define NULL_MAP "NULL map argument"

/* Map validation */

# define INVALID_ENTITY "Invalid entity on map's file"
# define INVALID_FORMAT "Invalid map format"
# define MAP_NOT_CLOSED "Map is not closed by walls"
# define INVALID_NBR_EXITS "Invalid number of Exits (E)"
# define NO_COLLECTIBLES "Map doesn't have any Collectible (C)"
# define INVALID_NBR_PLAYERS "Invalid number of Starting Positions (P)"

# define UNACHIEVABLE_ENTITIES "Map has unachievable entities"

/* Reading map's content */

# define INVALID_MAP_FILE "Invalid map file extension"
# define OPEN_MAP_FILE_ERR "Failed to open map's file"
# define EMPTY_MAP_FILE "Map file is empty"

/* XPM Opening */

# define WALL_XPM_ERR "Failed to open wall image"
# define FLOOR_XPM_ERR "Failed to open floor image"
# define PLAYER_XPM_ERR "Failed to open player image"
# define COLLECTIBLE_XPM_ERR "Failed to open collectible image"
# define EXIT_XPM_ERR "Failed to open exit image"

#endif // ERROR_MESSAGES_H