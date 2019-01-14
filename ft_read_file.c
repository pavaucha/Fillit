/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:16:55 by lezhang           #+#    #+#             */
/*   Updated: 2017/11/29 10:52:00 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int fd, char *str)
{
	char	buf[22];
	int		ret;
	char	*temp;

	ret = 0;
	if ((temp = ft_strnew(1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buf, 22)))
	{
		buf[ret] = '\0';
		if ((str = ft_strjoin(temp, buf)) == NULL)
			return (NULL);
		free(temp);
		if ((temp = ft_strdup(str)) == NULL)
			return (NULL);
		free(str);
	}
	if ((str = ft_strdup(temp)) == NULL)
		return (NULL);
	ft_strdel(&temp);
	return (str);
}

char	*ft_read_file(char *argv)
{
	char	*str;
	int		fd;

	str = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if ((str = ft_read(fd, str)) == NULL)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (str);
}
