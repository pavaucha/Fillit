/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_termi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:55:21 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/29 11:09:36 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_nb_cara(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	if (i % 21 != 20)
		return (0);
	return (i);
}

char		**ft_norme(char **src)
{
	size_t		i;
	size_t		j;
	size_t		point;

	j = 0;
	i = 0;
	point = 0;
	return (ft_test_valid(src, i, j, point));
}

char		**ft_test_valid(char **src, size_t i, size_t j, size_t point)
{
	size_t		n;
	size_t		d;

	while (src[j] != 0)
	{
		d = 0;
		point = 0;
		n = 0;
		i = -1;
		while (src[j][++i] != '\0')
		{
			if (src[j][i] == '.' && (i % 5) != 4)
				point++;
			else if (src[j][i] == '#' && (i % 5) != 4)
				d++;
			else if (src[j][i] == '\n' && (i % 5) == 4)
				n++;
			else
				return (NULL);
		}
		if (d != 4 || point != 12 || n != 4)
			return (NULL);
		j++;
	}
	return (src);
}

size_t		ft_count_tetri(size_t i)
{
	if (i > 439)
		return ((i / 20) - 1);
	else
		return (i / 20);
}

char		**ft_verif_termi(char *str)
{
	size_t		i;
	char		**src;
	size_t		j;
	size_t		k;

	k = 0;
	j = 0;
	i = 0;
	if (ft_nb_cara(str) == 0)
		return (0);
	i = ft_nb_cara(str);
	if ((i = ft_count_tetri(i)) > 26)
		return (0);
	if ((src = (char**)malloc(sizeof(char*) * (i + 1))) == 0)
		return (0);
	while (j < i)
	{
		src[j] = ft_strsub(str, k, 20);
		k = k + 21;
		j++;
	}
	src[j] = 0;
	if (ft_norme(src) == 0)
		return (NULL);
	return (ft_norme(src));
}
