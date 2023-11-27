/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:59:03 by joseph            #+#    #+#             */
/*   Updated: 2023/10/20 12:05:26 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*bush;
	void	*npc;
	void	*fond;
	void	*obj;
	void	*imgexit;
	int		moves;
	int		height_l;
	int		width_l;
	int		consum;
	int		wall;
	int		ex;
	int		back;
	int		player;
	int		x;
	int		y;
	int		errors;
	int		linecontrol;
	char	*bigline;
}	t_list;

typedef struct x_point
{
	int	x;
	int	y;
}	t_point;

void	ft_error(t_list *d, int num);
int		ft_strlen(const char *str);
void	read_map(char *map, t_list *d);
void	flood_fill_2(char **tab, t_list *d, t_point cur, char to_fill);
void	ft_closeimg(int fd1, int fd2, int fd3, int fd4);
int		ft_free(t_list *d);
char	*ft_itoa(int nb);
int		key_press(int key, t_list *d);
void	print_map(t_list *d);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	flood_fill(char **tab, t_list *d, t_point cur, char to_fill);
int		check_exit(t_list *d, char letter);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	**duplicate(char **copy, t_list *d, char *map);
int		ft_parche(t_list *d, char *map);
#endif