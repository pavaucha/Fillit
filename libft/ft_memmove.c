/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:42:54 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/13 16:18:30 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char*)(dst + len - 1) = *(unsigned char*)(src + len - 1);
			len--;
		}
	}
	return (dst);
}
