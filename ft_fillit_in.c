/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:24:31 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/27 10:31:54 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tab(char **result, t_tetri **stock, size_t size)
{
	(*stock)->xy[0] = 0;
	while ((*stock)->xy[0] < size)
	{
		(*stock)->xy[1] = 0;
		while ((*stock)->xy[1] < size)
		{
			if (ft_isvalid(result, *stock, size) == 1)
			{
				result = ft_place(result, *stock);
				if (*(stock + 1) == NULL)
					return (result);
				else if ((ft_tab(result, stock + 1, size)) != NULL)
					return (result);
				result = ft_del_tetri(result, (*stock)->letter);
			}
			(*stock)->xy[1]++;
		}
		(*stock)->xy[0]++;
	}
	return (NULL);
}

char	**ft_fillit_in(char **result, t_tetri **stock, size_t size)
{
	while ((ft_tab(result, stock, size)) == NULL)
	{
		size++;
		ft_strfree(result);
		result = ft_strnew_c(size, '.');
	}
	return (result);
}
