/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:31:29 by lezhang           #+#    #+#             */
/*   Updated: 2017/11/29 10:39:52 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_form(char *str)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	if ((tab = ft_strsplit(str, '\n')) == NULL)
		return (0);
	while (*(tab + i) != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				count += ft_check_around(tab, i, j);
			j++;
		}
		i++;
	}
	ft_strfree(tab);
	if (count != 6 && count != 8)
		return (0);
	return (1);
}
