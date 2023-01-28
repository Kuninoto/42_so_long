/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_isspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:13:53 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/22 01:06:54 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	only_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_spaces(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}
