/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:04:24 by ksiren            #+#    #+#             */
/*   Updated: 2021/03/15 19:13:21 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**fill_map_array(t_data *data)
{
	int fd;
	int j;
	char *line;
	char **dva;

	j = 0;
	fd = open("cub.cub", O_RDONLY);
	while (get_next_line(fd, &line) == 1) //counting size
	{
		if ((unsigned int)ft_strlen(line) > data->stolbs)
			data->stolbs = ft_strlen(line);
		data->stroks++;
		free(line);
	}
	if (!(dva = (char **)malloc(sizeof(char *) * (data->stroks))))
		return (NULL);
	j = 0;
	fd = open("cub.cub", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		dva[j] = ft_strdup(line);
		j++;
		free(line);
	}
	return (dva);
}

void draw_map(t_data data)
{
	unsigned int i;
	unsigned int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < data.stroks)
	{
		y = i * MAP_SQUARE_SIZE;
		j = 0;
		while (j < data.stolbs)
		{
			x = j * MAP_SQUARE_SIZE;
			if (data.map[i][j] == '1')
				draw_square(MAP_SQUARE_SIZE, x, y, &data, TURQUOISE, data.addr_map);
			else if (data.map[i][j] == '0')
				draw_square(MAP_SQUARE_SIZE, x, y, &data, GREY, data.addr_map);
			j++;
		}
		i++;
	}
}
