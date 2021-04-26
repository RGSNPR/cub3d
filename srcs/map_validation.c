/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:58:03 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:23:51 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map_item(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1' && map[i][j] != ' ')
				exit_error("Error: Invalid map\n");
			else if (i == (int)data->stroks - 1
				&& map[i][j] != '1' && map[i][j] != ' ')
				exit_error("Error: Invalid map\n");
			else
				check_map_unit(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_map_unit(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != ' ')
	{
		if (ft_strlen(map[i - 1]) < j + 1)
			exit_error("Error: Invalid map\n");
		else if (ft_strlen(map[i + 1]) < j + 1)
			exit_error("Error: Invalid map\n");
		else if (j != 0 && j != ft_strlen(map[i]) - 1)
		{
			if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
				exit_error("Error: Invalid map\n");
		}
		else
			exit_error("Error: Invalid map\n");
	}
}

void	check_map_validity(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (!check_map_line(map[i], "012NSWE "))
			exit_error("Error lol\n");
		i++;
	}
	check_map_item(data, map);
	return ;
}
