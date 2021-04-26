/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:01:37 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:59:53 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	clr_atoi(const char *str)
{
	int	ret;
	int	pusmus;

	pusmus = 1;
	ret = 0;
	while (*str && (*str == ' ' || *str == ','))
		++str;
	if (*str == '-')
		pusmus = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		++str;
	}
	return (ret * pusmus);
}

int	check_format(char *map_name)
{
	size_t	i;

	i = ft_strlen(map_name);
	if (ft_strncmp(map_name + i - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	check_line(char *line, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (1);
	while (set[j])
	{
		if (set[j] == line[i])
			return (1);
		j++;
	}
	return (0);
}

int	check_map_line(char *line, char *set)
{
	int	i;

	i = 0;
	if (!line[i])
		return (1);
	while (line[i])
	{
		if (ft_strchr(set, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	darr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
