/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:28:43 by joseph            #+#    #+#             */
/*   Updated: 2023/10/03 15:28:04 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	check_start_line(t_list *d)
{
	int	i;

	i = d->width_l - 2;
	while (i < ft_strlen(d->bigline))
	{
		if (d->bigline[i] == '1')
		{
			i = i + d->width_l;
		}
		else
		{
			ft_error(d, 2);
		}
	}
	i = d->width_l;
	while (i < ft_strlen(d->bigline))
	{
		if (d->bigline[i] == '1')
			i = i + d->width_l;
		else
		{
			ft_error(d, 1);
		}
	}
}

static	void	check_fst_line(t_list *d)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(d->bigline) - d->width_l;
	while (i != d->width_l)
	{
		if (d->bigline[i] == '1' || d->bigline[i] == '\n')
			i++;
		else
			ft_error(d, 3);
	}
	while (last != ft_strlen(d->bigline))
	{
		if (d->bigline[last] == '1' || d->bigline[last] == '\n')
		{
			last++;
		}
		else
		{
			ft_error(d, 4);
		}
	}
	check_start_line(d);
}

void	checkline(t_list *d)
{
	int	i;

	i = 0;
	while (d->bigline[i])
	{
		if (d->bigline[i] != 'C' && d->bigline[i] != 'E'
			&& d->bigline[i] != '1' && d->bigline[i] != '0'
			&& d->bigline[i] != 'P' && d->bigline[i] != '\n')
			ft_error(d, 8);
		if (d->bigline[i] == 'C')
			d->consum++;
		if (d->bigline[i] == 'E')
			d->ex++;
		if (d->ex > 1)
			ft_error(d, 5);
		if (d->bigline[i] == '1')
			d->wall++;
		if (d->bigline[i] == '0')
			d->back++;
		if (d->bigline[i] == 'P')
			d->player++;
		i++;
	}
	if (d->consum < 1 || d->ex < 1 || d->wall < 1 || d->player != 1)
		ft_error(d, 5);
}

static	void	check_line_break(char *line, t_list *d)
{
	int	i;

	i = 0;
	d->linecontrol = 1;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			d->linecontrol = 0;
		}
		i++;
	}
}

void	read_map(char *map, t_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linecontrol = 2;
	while (d->linecontrol != 1)
	{
		d->height_l++;
		line = get_next_line(fd);
		if (!line)
			ft_error(d, 10);
		if (d->linecontrol == 2)
			d->width_l = ft_strlen(line);
		check_line_break(line, d);
		if (ft_strlen(line) + d->linecontrol != d->width_l)
			ft_error(d, 7);
		d->bigline = ft_strjoin(d->bigline, line);
		if (line)
			free(line);
	}
	close(fd);
	check_fst_line(d);
	checkline(d);
}
