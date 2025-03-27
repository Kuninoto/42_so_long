/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/27 18:10:47 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_hexa(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		digits += 1;
	}
	return (digits);
}

static void	put_hexa(unsigned int nbr, bool upper_case)
{
	static char	upper[] = "0123456789ABCDEF";
	static char	lower[] = "0123456789abcdef";

	if (nbr > 16)
		put_hexa(nbr, upper_case);
	if (upper_case)
		write(STDOUT_FILENO, &upper[nbr % 10], 1);
	else
		write(STDOUT_FILENO, &lower[nbr % 10], 1);
}

int	prt_hexa(unsigned int nbr, bool upper_case)
{
	put_hexa(nbr, upper_case);
	return (digits_hexa(nbr));
}
