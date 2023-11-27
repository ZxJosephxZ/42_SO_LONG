/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:47:31 by joseph            #+#    #+#             */
/*   Updated: 2023/10/03 16:28:20 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	move_w(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i] != 'P')
	{
		i++;
	}
	if (d->bigline[i - d->width_l] != '1'
		&& !check_exit(d, d->bigline[i - d->width_l]))
	{
		d->moves++;
		if (d->bigline[i - d->width_l] == 'C')
		{
			d->consum--;
		}
		d->bigline[i] = '0';
		d->bigline[i - d->width_l] = 'P';
	}
	print_map(d);
}

void	move_s(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i] != 'P')
	{
		i++;
	}
	if (d->bigline[i + d->width_l] != '1'
		&& !check_exit(d, d->bigline[i + d->width_l]))
	{
		d->moves++;
		if (d->bigline[i + d->width_l] == 'C')
		{
			d->consum--;
		}
		d->bigline[i] = '0';
		d->bigline[i + d->width_l] = 'P';
	}
	print_map(d);
}

void	move_a(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i] != 'P')
	{
		i++;
	}
	if (d->bigline[i - 1] != '1'
		&& !check_exit(d, d->bigline[i - 1]))
	{
		d->moves++;
		if (d->bigline[i - 1] == 'C')
		{
			d->consum--;
		}
		d->bigline[i] = '0';
		d->bigline[i - 1] = 'P';
	}
	print_map(d);
}

void	move_d(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i] != 'P')
	{
		i++;
	}
	if (d->bigline[i + 1] != '1'
		&& !check_exit(d, d->bigline[i + 1]))
	{
		d->moves++;
		if (d->bigline[i + 1] == 'C')
		{
			d->consum--;
		}
		d->bigline[i] = '0';
		d->bigline[i + 1] = 'P';
	}
	print_map(d);
}

int	key_press(int key, t_list *d)
{
	char	*moves_p;

	(void)d;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 13)
		move_w(d);
	if (key == 0)
		move_a(d);
	if (key == 1)
		move_s(d);
	if (key == 2)
		move_d(d);
	moves_p = ft_itoa(d->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
