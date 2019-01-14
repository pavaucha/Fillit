/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:31:29 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/30 16:16:42 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**termi;
	t_tetri	**stock;
	int		i;

	i = 0;
	if (ft_arg(argc) != 2)
		return (0);
	if ((stock = (t_tetri**)malloc(sizeof(t_tetri*) * 27)) == NULL)
		return (0);
	if ((termi = ft_verif_total(argv)) == NULL)
		return (0);
	if ((stock = ft_creat_struct(termi, stock)) == NULL)
		return (0);
	ft_go_fillit(stock);
	ft_strfree(termi);
	while (stock[i] != 0)
	{
		ft_strfree(stock[i]->tetri);
		free(stock[i]);
		i++;
	}
	free(stock);
	return (0);
}
