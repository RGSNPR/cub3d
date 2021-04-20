/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:04:24 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/19 19:16:13 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_parameter(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "NO ", 3) != 1 || ft_strncmp(line, "SO ", 3) != 1
		|| ft_strncmp(line, "WE ", 3) != 1 || ft_strncmp(line, "EA ", 3) != 1
		|| ft_strncmp(line, "S  ", 2) != 1)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

void find_map(t_data *data, int fd, char **line)
{
	int i = 0;
	while (i <= data->count_params)
	{
		get_next_line(fd, line);
		if (is_parameter(*line) == 0)
			break ;
		i += is_parameter(*line);
	}
	get_next_line(fd, line);
	if (i == data->count_params + 1)
		data->map_flag = 1;
	else
		data->map_flag = 0;
	return ;
}

char	**fill_map_array(t_data *data)
{
	int fd;
	int j;
	char *line;
	char **dva;

	j = 0;
	fd = open(data->map_file, O_RDONLY);
	find_map(data, fd, &line);
	if (data->map_flag == 0)
	{
		ft_putstr_fd("Error: lol\n", 2);
		exit(0);
	}
	while (get_next_line(fd, &line) == 1) //counting size
	{
		printf("%s\n", line);
		if ((unsigned int)ft_strlen(line) > data->stolbs)
			data->stolbs = ft_strlen(line);
		data->stroks++;
		free(line);
	}
	close(fd);
	if (!(dva = (char **)malloc(sizeof(char *) * (data->stroks + 1))))
		return (NULL);
	j = 0;
	fd = open(data->map_file, O_RDONLY);
	find_map(data, fd, &line);
	while (get_next_line(fd, &line) == 1)
	{
		dva[j] = ft_strdup(line);
		j++;
		free(line);
	}
	dva[j] = NULL;
	close(fd);
	return (dva);
}

void draw_map(t_data *data)
{
	unsigned int i;
	unsigned int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < data->stroks)
	{
		y = i * MSS / 2;
		j = 0;
		while (j < data->stolbs)
		{
			x = j * MSS / 2;
			if (data->map[i][j] == '1')
				draw_square(MSS / 2, x, y, data, TURQUOISE, data->addr_3d);
			else if (data->map[i][j] == '0')
				draw_square(MSS / 2, x, y, data, GREY, data->addr_3d);
			j++;
		}
		i++;
	}
}

void check_dvoyki(t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
				k++;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	data->count_sprite = k;
	data->sprites = (t_sprite *)malloc(sizeof(t_sprite) * k);
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
			{
				data->sprites[k].pos_x = j * MSS + MSS / 2;
				data->sprites[k].pos_y = i * MSS + MSS / 2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	swap_sprite(t_sprite *sprite_1, t_sprite *sprite_2)
{
	double x;
	double y;
	double len;

	x = sprite_1->pos_x;
	y = sprite_1->pos_y;
	len = sprite_1->len;
	sprite_1->pos_x = sprite_2->pos_x;
	sprite_1->pos_y = sprite_2->pos_y;
	sprite_1->len = sprite_2->len;
	sprite_2->pos_x = x;
	sprite_2->pos_y = y;
	sprite_2->len = len;
}

void	sort_sprites(t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < data->count_sprite)
	{
		data->sprites[i].len = sqrt(pow(data->player.posx - data->sprites[i].pos_x, 2) +
								pow(data->player.posy - data->sprites[i].pos_y, 2));
		if (i != 0 && data->sprites[i].len > data->sprites[i - 1].len)
			swap_sprite(&data->sprites[i], &data->sprites[i - 1]);
		i++;
	}
}

int		is_player_placed(t_data *data, char c)
{
	if (c == 'N')
		data->player.p_angle = -M_PI_2;
	else if (c == 'S')
		data->player.p_angle = M_PI_2;
	else if (c == 'W')
		data->player.p_angle = M_PI;
	else if (c == 'E')
		data->player.p_angle = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	check_player(t_data *data)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player_placed(data, data->map[i][j]))
			{
				data->player.posx = j * MSS;
				data->player.posy = i * MSS;
				return  ;
			}
			j++;
		}
		i++;
	}
}
