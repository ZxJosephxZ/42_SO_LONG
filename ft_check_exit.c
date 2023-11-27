/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:55:57 by joseph            #+#    #+#             */
/*   Updated: 2023/10/03 16:10:16 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "win\n", 4);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "collect all the items\n", 22);
		return (1);
	}
	else
	{
		return (0);
	}
}
