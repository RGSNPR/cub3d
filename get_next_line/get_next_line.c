/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:57:37 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/27 05:21:17 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../srcs/cub.h"

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*new;
	size_t	size1;
	size_t	size2;
	size_t	sizer;

	if (!s1 && !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	sizer = size1 + size2;
	new = (char *)malloc(sizeof(char) * (sizer + 1));
	ft_memmove(new, s1, size1);
	ft_memmove(new + size1, s2, size2);
	new[sizer] = '\0';
	free(s1);
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static char	*ost;
	char		*buf;
	int			rres;

	rres = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (rres != 0 && ft_parse_es(ost) == 0)
	{
		rres = read(fd, buf, BUFFER_SIZE);
		if (rres == -1)
		{
			free(buf);
			return (-1);
		}
		buf[rres] = '\0';
		ost = ft_strjoin_mod(ost, buf);
	}
	*line = ft_newstr(ost);
	ost = ft_cutost(ost);
	free(buf);
	if (rres)
		return (1);
	return (0);
}
