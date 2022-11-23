/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:58:18 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 17:00:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_error(char *error_msg)
{
	write(2, "Error: ", 7);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
