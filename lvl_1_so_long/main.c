/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 19:03:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int close_win_x(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, void *mlx_ptr)
{
	static int counter;

	if (key == ESC)
		exit(EXIT_SUCCESS);


	
	counter++;
	ft_printf("counter = %d\n", counter);
	return (EXIT_SUCCESS);	
}

/* int deal_mouse(int button, int x, int y, void *mlx_ptr, void *win_ptr)
{
	ft_printf("button = %d\n", button);
	ft_printf("x = %d\n", x);
	ft_printf("y = %d\n", y);


	return (EXIT_SUCCESS);
}
 */
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

	char	*ylw_path;
	void	*ylw_ptr;
	
	char	*red_path;
	void	*red_ptr;

	int		width;
	int		height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 900, 600, "so_long");
	if (!win_ptr)
		handle_error("Failed to open the game window!");

	ylw_path = YLW_DINO_01;
	ylw_ptr = mlx_xpm_file_to_image(mlx_ptr, ylw_path, &width, &height);

	red_path = RED_DINO_01;
	red_ptr = mlx_xpm_file_to_image(mlx_ptr, red_path, &width, &height);

	mlx_put_image_to_window(mlx_ptr, win_ptr, ylw_ptr, 1 * 64, 1 * 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, red_ptr, 2 * 64, 1 * 64);
	mlx_key_hook(win_ptr, on_press, NULL);
	
	
	// close windows on mouse press X
	mlx_hook(win_ptr, 17, 1L << 17, close_win_x, NULL);
	
	//mlx_mouse_hook(win_ptr, deal_mouse, NULL);
	mlx_loop(mlx_ptr);
	return (EXIT_SUCCESS);
}

// mycc srcs/map/* srcs/handle_error.c libft.a main.c -L ./mlx -lmlx -Ilmlx -lXext -lX11