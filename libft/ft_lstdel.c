/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:00:36 by pavaucha          #+#    #+#             */
/*   Updated: 2017/11/15 14:13:30 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst == NULL)
		return ;
	while ((*alst)->next != NULL)
	{
		temp = (*alst)->next;
		(del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = NULL;
		(*alst) = temp;
	}
	if ((*alst)->next == NULL)
	{
		(del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = NULL;
	}
}
