/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_termi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:00:08 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/24 18:17:58 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_stock_d(t_tetri *stock)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (stock->tetri[i] != 0)
	{
		j = 0;
		while (stock->tetri[i][j] != '\0')
		{
			if (stock->tetri[i][j] == '#')
			{
				stock->x[k] = i;
				stock->y[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (stock);
}

t_tetri		*ft_stock_termi(char *str)
{
	t_tetri		*stock;
	size_t		i;
	size_t		j;
	size_t		k;

	i = -1;
	k = 0;
	if ((stock = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	if ((stock->tetri = (char**)malloc(sizeof(char*) * 5)) == NULL)
		return (NULL);
	while (++i < 4)
	{
		if ((stock->tetri[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		j = -1;
		while (++j < 4)
			stock->tetri[i][j] = str[k++];
		k++;
		stock->tetri[i][j] = '\0';
	}
	stock->tetri[i] = 0;
	stock = ft_stock_d(stock);
	return (stock);
}
