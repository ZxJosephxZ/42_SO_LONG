/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:56:45 by joseph            #+#    #+#             */
/*   Updated: 2023/10/20 12:06:18 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	check_extension(char *map, t_list *d)
{
	int	i;

	i = ft_strlen(map);
	if (i > 2 && map[i - 4] == '.' && map[i - 3] == 'b'
		&& map[i - 2] == 'e' && map[i - 1] == 'r')
	{
	}
	else
	{
		ft_error(d, 6);
	}
}

static void	init_img(t_list *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->y = (ft_strlen(d->bigline) / d->width_l + 1) * 50;
	d->x = (d->width_l - 1) * 50;
	d->bush = mlx_xpm_file_to_image(d->mlx, "textures/bush.xpm", &w, &h);
	d->fond = mlx_xpm_file_to_image(d->mlx, "textures/fond.xpm", &w, &h);
	d->npc = mlx_xpm_file_to_image(d->mlx, "textures/npc.xpm", &w, &h);
	d->imgexit = mlx_xpm_file_to_image(d->mlx, "textures/imgexit.xpm", &w, &h);
	d->obj = mlx_xpm_file_to_image(d->mlx, "textures/poke.xpm", &w, &h);
}

int	ft_img(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;

	fd1 = open("textures/bush.xpm", O_RDONLY);
	fd2 = open("textures/fond.xpm", O_RDONLY);
	fd3 = open("textures/npc.xpm", O_RDONLY);
	fd4 = open("textures/poke.xpm", O_RDONLY);
	fd5 = open("textures/imgexit.xpm", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1 || fd5 == -1)
	{
		close(fd5);
		ft_closeimg(fd1, fd2, fd3, fd4);
		return (0);
	}
	close(fd5);
	ft_closeimg(fd1, fd2, fd3, fd4);
	return (1);
}

int	init_data(t_list *d, char *map)
{
	d->moves = 0;
	if (ft_img() == 0)
	{
		ft_error(d, 11);
		return (1);
	}
	check_extension(map, d);
	read_map(map, d);
	if (ft_parche(d, map) == 0)
	{
		ft_error(d, 9);
		return (1);
	}
	return (0);
}

int	main(int arc, char **argc)
{
	t_list	*d;

	if (arc != 2)
	{
		write(1, "Incorrect number of arguments.\n", 32);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_list));
	if (!d)
	{
		return (0);
	}
	if (init_data(d, argc[1]) == 1)
	{
		return (0);
	}
	d->mlx = mlx_init();
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	print_map(d);
	mlx_key_hook(d->win, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}
