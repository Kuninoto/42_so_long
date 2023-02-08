/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_n_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:46:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/08 23:23:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_pos(game, false, -1);
	else if (key == A || key == LEFT)
		update_player_pos(game, true, -1);
	else if (key == S || key == DOWN)
		update_player_pos(game, false, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17),
		quit_game, game);
	mlx_loop(game->mlx_ptr);
}
