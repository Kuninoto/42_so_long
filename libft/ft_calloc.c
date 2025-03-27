/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:25:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/22 02:45:28 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char		*mem_allocated;
	unsigned int		total;
	size_t				i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total = nmemb * size;
	mem_allocated = malloc(total);
	if (mem_allocated == NULL)
		return (NULL);
	i = 0;
	while (total-- > 0)
		mem_allocated[i++] = 0;
	return ((void *)mem_allocated);
}
