/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 23:19:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int close_win_x(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key)
{
	static int counter;

	if (key == ESC)
		exit(EXIT_SUCCESS);

	
	counter++;
	ft_printf("counter = %d\n", counter);
	return (EXIT_SUCCESS);	
}

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		handle_error("Invalid number of arguments");
	if (*argv[1] == 0)
		handle_error("NULL map argument");
}

int main(int argc, char **argv)
{
	args_check(argc, argv);
	get_map(argv[1]);

 	void	*mlx_ptr;
	void	*win_ptr;
	void	*ylw_ptr;
	
	void	*red_ptr;
	
	void	*grass_ptr;

	void	*meat_ptr;

	int		width;
	int		height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 13 * 48, 5 * 48, "so_long");
	if (!win_ptr)
		handle_error("Failed to open the game window!");

	ylw_ptr = mlx_xpm_file_to_image(mlx_ptr, YLW_DINO_01, &width, &height);

	red_ptr = mlx_xpm_file_to_image(mlx_ptr, RED_DINO_01, &width, &height);

	grass_ptr = mlx_xpm_file_to_image(mlx_ptr, GRASS_01, &width, &height);

	meat_ptr = mlx_xpm_file_to_image(mlx_ptr, MEAT, &width, &height);

	for (int i = 0; i <= 13; i++)
		for (int j = 0; j <= 5; j++)
			mlx_put_image_to_window(mlx_ptr, win_ptr, grass_ptr, j * IMG_SIZE, i * IMG_SIZE);
	
	mlx_put_image_to_window(mlx_ptr, win_ptr, ylw_ptr, 1 * 64, 1 * 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, red_ptr, 5 * 64, 5 * 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, meat_ptr, 7 * 64, 7 * 64);

	mlx_key_hook(win_ptr, on_press, NULL);
	
	// close windows on mouse press X
	mlx_hook(win_ptr, 17, 1L << 17, close_win_x, NULL);
	
	//mlx_mouse_hook(win_ptr, deal_mouse, NULL);
	mlx_loop(mlx_ptr);
	return (EXIT_SUCCESS);
}

// mycc srcs/map/* srcs/handle_error.c libft.a main.c -L ./mlx -lmlx -Ilmlx -lXext -lX11