/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:42:29 by gcollet           #+#    #+#             */
/*   Updated: 2023/10/02 16:46:47 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc) et retourne une nouvelle chaine, résultat de la 
concaténation de s1 et s2. */
/* La nouvelle chaine de caractères. NULL si l’allocation échoue. */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = 0;
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (0);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	free(s1);
	return (tab);
}
