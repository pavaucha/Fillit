/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_around.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:32:17 by lezhang           #+#    #+#             */
/*   Updated: 2017/11/24 17:45:04 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_top(char **tab, int i, int j)
{
	if (tab[i - 1][j] == '#')
		return (1);
	else
		return (0);
}

int		check_right(char **tab, int i, int j)
{
	if (tab[i][j + 1] == '#')
		return (1);
	else
		return (0);
}

int		check_bot(char **tab, int i, int j)
{
	if (tab[i + 1][j] == '#')
		return (1);
	else
		return (0);
}

int		check_left(char **tab, int i, int j)
{
	if (tab[i][j - 1] == '#')
		return (1);
	else
		return (0);
}

int		ft_check_around(char **tab, int i, int j)
{
	int		count;

	count = 0;
	if (tab == NULL)
		return (0);
	if (i != 0)
		count += check_top(tab, i, j);
	if (j != 3)
		count += check_right(tab, i, j);
	if (i != 3)
		count += check_bot(tab, i, j);
	if (j != 0)
		count += check_left(tab, i, j);
	return (count);
}
