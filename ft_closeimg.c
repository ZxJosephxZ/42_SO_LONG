/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closeimg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:01:33 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/10/20 12:04:09 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_closeimg(int fd1, int fd2, int fd3, int fd4)
{
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}
