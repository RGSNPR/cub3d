/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:33:07 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/27 20:08:22 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*check_sprite(t_data *data, char *line)
{
	static int	flag_spr;
	char		**str;

	data->count_params++;
	if (flag_spr == 1)
		return ("Error: Config has extra parameters\n");
	flag_spr = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid sprite texture\n");
	data->sprite.img = mlx_xpm_file_to_image(data->mlx, str[1],
			&data->sprite.sizew, &data->sprite.sizeh);
	if (data->sprite.img == NULL)
		return ("Error: Invalid sprite texture\n");
	data->sprite.addr = mlx_get_data_addr(data->sprite.img,
			&data->sprite.bits_per_pixel, &data->sprite.line_length,
			&data->sprite.endian);
	clean_array(str);
	return (NULL);
}

char	*check_floor(t_data *data, char *line)
{
	static int	flag_fl;
	char		**str;
	int			clr[3];

	data->count_params++;
	if (flag_fl == 1)
		return ("Error: Config has extra parameters\n");
	flag_fl = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) > 4)
		return ("Error: Invalid floor color\n");
	while (*line == 'F' || *line == ' ')
		line++;
	clr[0] = clr_atoi(line);
	while (*line != ',' && *line != ' ')
		line++;
	line++;
	clr[1] = clr_atoi(line);
	while (*line != ',' && *line != ' ')
		line++;
	clr[2] = clr_atoi(line);
	if (clr[0] < 0 || clr[0] > 255 || clr[1] < 0 || clr[1] > 255
		|| clr[2] < 0 || clr[2] > 255)
		return ("Error: Invalid floor color\n");
	data->floor_tex = clr[0] * 256 * 256 + clr[1] * 256 + clr[2];
	clean_array(str);
	return (NULL);
}

char	*check_ceiling(t_data *data, char *line)
{
	static int	flag_fl;
	char		**str;
	int			clr[3];

	data->count_params++;
	if (flag_fl == 1)
		return ("Error: Config has extra parameters\n");
	flag_fl = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) > 4)
		return ("Error: Invalid ceiling color\n");
	while (*line == 'C' || *line == ' ')
		line++;
	clr[0] = clr_atoi(line);
	while (*line != ',' && *line != ' ')
		line++;
	line++;
	clr[1] = clr_atoi(line);
	while (*line != ',' && *line != ' ')
		line++;
	clr[2] = clr_atoi(line);
	if (clr[0] < 0 || clr[0] > 255 || clr[1] < 0 || clr[1] > 255
		|| clr[2] < 0 || clr[2] > 255)
		return ("Error: Invalid ceiling color\n");
	data->ceiling_tex = clr[0] * 256 * 256 + clr[1] * 256 + clr[2];
	clean_array(str);
	return (NULL);
}

char	*check_parameter(t_data *data, char *line)
{
	if ((is_parameter(line) != 1 || check_line(line, "012WESNCFR") == 0)
		&& !check_map_line(line, "012NSWE "))
		return ("Error: Eres' v fayle >:(\n");
	if (line[0] == 'R')
		return (check_res(data, line));
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (check_tex(data, line));
	if (ft_strncmp(line, "S ", 2) == 0)
		return (check_sprite(data, line));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (check_floor(data, line));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (check_ceiling(data, line));
	return (NULL);
}

char	*parser(t_data *data)
{
	char	*error;
	char	*line;
	int		fd;

	error = NULL;
	fd = open(data->map_file, O_RDONLY);
	if (check_format(data->map_file) || fd == -1)
	{
		error = ft_strdup("Error: Incorrect map file\n");
		return (error);
	}
	while (get_next_line(fd, &line) > 0)
	{
		error = ft_strdup(check_parameter(data, line));
		free(line);
		if (ft_strlen(error) != 0)
			return (error);
		free(error);
	}
	return (NULL);
}
