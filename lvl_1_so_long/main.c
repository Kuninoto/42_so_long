/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 22:17:00 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		handle_error("Invalid number of arguments");
	if (*argv[1] == 0)
		handle_error("NULL map argument");
}

int main(int argc, char **argv)
{
	t_game	*game;
	void	*img_ptr;

	args_check(argc, argv);
	game = init_game();
	game->map = get_map(argv[1]);
	init_mlx(game);

	int width;
	int height;
	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, COIN, &width, &height);

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 13; j++)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, j * IMG_SIZE, i * IMG_SIZE);

//	free(game);
	return (EXIT_SUCCESS);
}