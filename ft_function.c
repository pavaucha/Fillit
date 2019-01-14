/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:47:19 by lezhang           #+#    #+#             */
/*   Updated: 2017/11/29 11:36:32 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_nb_tetri(t_tetri **stock)
{
	size_t	i;

	i = 0;
	while (stock[i])
		i++;
	return (i);
}

size_t	ft_size_map(t_tetri **stock)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_nb_tetri(stock) * 4;
	while ((i * i) < size)
		i++;
	return (i);
}

int		ft_isvalid(char **result, t_tetri *stock, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (((stock->x[i] - stock->x[0] + stock->xy[0]) >= size) ||
			((stock->y[i] - stock->y[0] + stock->xy[1]) >= size) ||
			result[stock->x[i] - stock->x[0] + stock->xy[0]]
			[stock->y[i] - stock->y[0] + stock->xy[1]] != '.')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_place(char **result, t_tetri *stock)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		result[stock->x[i] - stock->x[0] + stock->xy[0]]
			[stock->y[i] - stock->y[0] + stock->xy[1]] = stock->letter;
		i++;
	}
	return (result);
}

char	**ft_del_tetri(char **result, char c)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (result[x] != 0)
	{
		y = 0;
		while (result[x][y] != '\0')
		{
			if (result[x][y] == c)
				result[x][y] = '.';
			y++;
		}
		x++;
	}
	return (result);
}
