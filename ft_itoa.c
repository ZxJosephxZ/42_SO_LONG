/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:29:24 by joseph            #+#    #+#             */
/*   Updated: 2023/09/29 11:17:08 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long int	ft_baseexponente(long int base, size_t exp)
{
	long int	nbr;

	if (exp == 0)
	{
		return (1);
	}
	nbr = base;
	while (--exp)
	{
		nbr *= base;
	}
	return (nbr);
}

char	*ft_itoa(int nb)
{
	char	*nbr;
	size_t	digit;

	digit = 1;
	while (nb / ft_baseexponente(10, digit))
		digit++;
	nbr = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!nbr)
	{
		return (0);
	}
	while (--digit)
	{
		nbr[digit] = (char)((nb % 10) + '0');
		nb /= 10;
	}
	nbr[digit] = (char)((nb % 10) + '0');
	return (nbr);
}
