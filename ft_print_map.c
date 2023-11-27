/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:05:51 by joseph            #+#    #+#             */
/*   Updated: 2023/10/03 16:28:09 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

static	void	calc_xy(char c, int i, t_list *d)
{
	int	x;
	int	y;

	y = (i / d->width_l) * 50;
	x = (i % d->width_l) * 50;
	if (d->errors == 0)
	{
		if (c == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->obj, x, y);
		if (c == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->imgexit, x, y);
		if (c == '1')
		{
			mlx_put_image_to_window(d->mlx, d->win, d->bush, x, y);
		}
		if (c == '0')
		{
			mlx_put_image_to_window(d->mlx, d->win, d->fond, x, y);
		}
		if (c == 'P')
		{
			mlx_put_image_to_window(d->mlx, d->win, d->npc, x, y);
		}
	}
}

void	print_map(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i])
	{
		if (d->bigline[i] == '\n')
			i++;
		if (d->bigline[i] != 'C' && d->bigline[i] != 'E' && d->bigline[i] != '1'
			&& d->bigline[i] != '0' && d->bigline[i] != 'P')
			exit(0);
		if (d->bigline[i] == 'C')
			calc_xy('C', i, d);
		if (d->bigline[i] == 'E')
			calc_xy('E', i, d);
		if (d->bigline[i] == '1')
			calc_xy('1', i, d);
		if (d->bigline[i] == '0')
			calc_xy('0', i, d);
		if (d->bigline[i] == 'P')
		{
			calc_xy('P', i, d);
		}
		i++;
	}
}
