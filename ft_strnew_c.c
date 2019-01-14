/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:35:19 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/20 09:56:03 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_strnew_c(size_t size, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	if ((str = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((str[i] = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
		j = 0;
		while (j < size)
		{
			str[i][j] = c;
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
