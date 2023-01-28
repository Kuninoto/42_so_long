/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:54:35 by roramos           #+#    #+#             */
/*   Updated: 2023/01/22 14:44:11 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *to_copy)
{
	char		*copy;
	size_t		i;

	if (!to_copy)
	{
		copy = malloc(2 * sizeof(char));
		copy[0] = ' ';
		copy[1] = '\0';
		return (copy);
	}
	copy = malloc((ft_strlen(to_copy) + 1) * sizeof(char));
	i = 0;
	while (to_copy[i])
	{
		copy[i] = to_copy[i];
		i += 1;
	}
	copy[i] = '\0';
	return (copy);
}
