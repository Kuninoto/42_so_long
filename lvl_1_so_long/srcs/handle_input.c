/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:26:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 21:27:42 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

