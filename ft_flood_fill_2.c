/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:15:57 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/10/20 11:22:16 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_2(char **tab, t_list *d, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= d->height_l || cur.x < 0 || cur.x >= d->width_l
		|| (tab[cur.y][cur.x] != 'F'
		&& (tab[cur.y][cur.x] != 'E' && tab[cur.y][cur.x] != 'P')))
		return ;
	tab[cur.y][cur.x] = 'X';
	flood_fill_2(tab, d, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill_2(tab, d, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill_2(tab, d, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill_2(tab, d, (t_point){cur.x, cur.y + 1}, to_fill);
}
