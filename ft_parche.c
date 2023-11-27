/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parche.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:12:48 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/10/20 11:37:31 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean(char **copy, t_list *d)
{
	int	i;

	i = 0;
	while (i < d->height_l)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

int	ft_verification(t_list *d, char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->height_l)
	{
		j = 0;
		while (j < d->width_l)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				ft_clean(copy, d);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_clean(copy, d);
	return (1);
}

int	ft_parche(t_list *d, char *map)
{
	char	**copy;
	int		i;
	int		j;
	t_point	start;

	i = -1;
	copy = (char **)ft_calloc(d->height_l + 1, sizeof(char *));
	if (!copy)
		return (0);
	copy = duplicate(copy, d, map);
	while (++i < d->height_l)
	{
		j = 0;
		while (j++ < d->width_l)
		{
			if (copy[i][j] == 'P')
			{
				start.x = j;
				start.y = i;
			}
		}
	}
	flood_fill(copy, d, start, copy[start.y][start.x]);
	flood_fill_2(copy, d, start, copy[start.y][start.x]);
	return (ft_verification(d, copy));
}
