/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:04:24 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:22:57 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_map_fl(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	find_map(t_data *data, int fd, char **line)
{
	int	i;

	i = 0;
	while (i < data->count_params)
	{
		get_next_line(fd, line);
		i += is_parameter(*line);
		if (is_map_fl(*line) == 1)
			exit_error("Error: Not enough parameters\n");
	}
	while (is_map_fl(*line) == 0)
	{
		if (get_next_line(fd, line) > 0)
			continue ;
		else
			break ;
	}
	if (i == data->count_params && is_map_fl(*line))
		data->map_flag = 1;
	else
		data->map_flag = 0;
	return ;
}

void	count_map_size(t_data *data, char **line, int fd)
{
	find_map(data, fd, line);
	if (data->map_flag == 0)
		exit_error("Error: no map lol\n");
	data->stolbs = ft_strlen(*line);
	data->stroks = 1;
	while (get_next_line(fd, line) == 1)
	{
		if ((unsigned int)ft_strlen(*line) > data->stolbs)
			data->stolbs = ft_strlen(*line);
		data->stroks++;
	}
	close(fd);
	return ;
}

char	**fill_map(char **line, char **dva, int fd)
{
	int	j;

	j = 1;
	while (get_next_line(fd, line) == 1)
		dva[j++] = ft_strdup(*line);
	dva[j] = NULL;
	close(fd);
	return (dva);
}

char	**fill_map_array(t_data *data)
{
	int		fd;
	int		j;
	int		i;
	char	*line;
	char	**dva;

	j = 0;
	i = 0;
	fd = open(data->map_file, O_RDONLY);
	count_map_size(data, &line, fd);
	dva = (char **)malloc(sizeof(char *) * (data->stroks + 1));
	if (!dva)
		return (NULL);
	j = 0;
	fd = open(data->map_file, O_RDONLY);
	find_map(data, fd, &line);
	i = 0;
	dva[j] = ft_strdup(line);
	free(line);
	dva = fill_map(&line, dva, fd);
	return (dva);
}
