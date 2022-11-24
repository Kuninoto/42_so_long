/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:49:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/24 21:09:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	open_ghost(void *mlx_ptr)
{
	int		width;
	int		height;
	void	*ghost_img;

	ghost_img = mlx_xpm_file_to_image(mlx_ptr, GHOST, &width, &height);
	if (!ghost_img)
		handle_error("Couldn't open ghost image");
	return (ghost_img);
}
