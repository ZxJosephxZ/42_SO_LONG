/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:23:11 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/10/02 15:19:17 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate(char **copy, t_list *d, char *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	if (!map)
	{
		return (0);
	}
	while (i <= d->height_l)
	{
		copy[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (copy);
}
