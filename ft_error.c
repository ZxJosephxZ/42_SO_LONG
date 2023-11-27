/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:02:54 by joseph            #+#    #+#             */
/*   Updated: 2023/10/04 16:40:50 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error2(t_list *d, int num)
{
	d->moves++;
	d->moves--;
	if (num == 8)
	{
		write(1, "The map contains incorrect characters\n", 38);
	}
	if (num == 9)
	{
		write(1, "Map path blocked\n", 18);
	}
	if (num == 10)
	{
		write(1, "There is no content on the map\n", 31);
	}
	if (num == 11)
	{
		write(1, "Are you, OKEY?\n", 15);
	}
}

void	ft_error(t_list *d, int num)
{
	write(1, "error\n", 6);
	if (num > 7)
		ft_error2(d, num);
	if (num == 1)
		write(1, "At the beginning of the line there is no wall\n", 46);
	if (num == 2)
		write(1, "At the end of the line there is no wall\n", 40);
	if (num == 3)
		write(1, "On the first line there is no wall\n", 35);
	if (num == 4)
		write(1, "In the last line there is no wall\n", 34);
	if (d->consum < 1 && num == 5)
		write(1, "There are no items\n", 19);
	if (d->player != 1 && num == 5)
		write(1, "The map must have a pj\n", 23);
	if ((d->ex < 1 || d->ex > 1) && num == 5)
		write(1, "The map must have an exit.\n", 27);
	if (num == 6)
		write(1, "Incorrect extension\n", 20);
	if (num == 7)
		write(1, "The map is not rectangular\n", 27);
	ft_free(d);
}
