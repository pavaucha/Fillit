/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:47:08 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/29 11:13:03 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_arg(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	return (2);
}

char		**ft_verif_total(char **argv)
{
	char	*str;
	char	**termi;
	int		i;

	i = -1;
	if ((str = ft_read_file(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	if ((termi = ft_verif_termi(str)) == NULL)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ft_strdel(&str);
	while (termi[++i] != 0)
	{
		if ((ft_verif_form(termi[i])) == 0)
		{
			ft_putstr("error\n");
			return (NULL);
		}
	}
	return (termi);
}

t_tetri		**ft_creat_struct(char **str, t_tetri **stock)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if ((stock[i] = ft_stock_termi(str[i])) == NULL)
		{
			ft_putstr("error\n");
			return (0);
		}
		stock[i]->letter = 'A' + i;
		i++;
	}
	stock[i] = 0;
	return (stock);
}

void		ft_go_fillit(t_tetri **stock)
{
	char	**result;
	size_t	size;
	int		i;

	i = 0;
	size = ft_size_map(stock);
	if ((result = ft_strnew_c(size, '.')) == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	if ((result = ft_fillit_in(result, stock, size)) == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	while (result[i] != 0)
	{
		ft_putstr(result[i]);
		ft_putchar('\n');
		i++;
	}
	ft_strfree(result);
	return ;
}
