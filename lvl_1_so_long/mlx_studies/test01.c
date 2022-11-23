/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:39:59 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/20 21:04:42 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "../mlx/mlx.h"

#define W 119
#define A 97
#define S 115
#define D 100

#define up 65362
#define left 65361
#define down 65364
#define right 65363

#define ESC 65307

int	key_hook(int keycode, void *mlx_ptr, void *win_ptr)
{
	if (keycode == ESC)
		mlx_destroy_window(mlx_ptr, win_ptr);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");

	mlx_key_hook(win_ptr, key_hook, NULL);
	
	mlx_loop(mlx_ptr);
}

// W 119
// A 97
// S 115
// D 100

// up 65362
// left 65361
// down 65364
// right 65363

// ESC 65307