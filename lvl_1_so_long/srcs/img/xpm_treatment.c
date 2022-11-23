/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:49:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 18:16:19 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	open_ylw_dino(void *mlx_ptr)
{
	int		width;
	int		height;
	void	*ylw_dino;

	ylw_dino = mlx_xpm_file_to_image(mlx_ptr, "ylw_dino01", &width, &height);
	if (!ylw_dino)
	{
		ft_printf("Error: Couldn't open yellow dino xpm.\n");
		return (EXIT_FAILURE);
	}
}
