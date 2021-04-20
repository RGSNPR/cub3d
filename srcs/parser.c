/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:33:07 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/18 18:34:15 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "stdio.h"

int	clr_atoi(const char *str)
{
	int	ret;
	int	pusmus;

	pusmus = 1;
	ret = 0;
	printf("clr_atoi str = %s\n", str);
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
	printf("pidar %d\n", ret * pusmus);
	return (ret * pusmus);
}

int		check_format(char *map_name)
{
	size_t i;

	i = ft_strlen(map_name);
	if (ft_strncmp(map_name + i - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int		check_line(char *line, char *set)
{
	int i = 0;
	int j = 0;

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

int		darr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int res_id(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != 'R' || i > 1)
			return (1);
		i++;
	}
	return (0);
}

int res_values(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

char	*check_res(t_data *data, char *line)
{
	static int flag_res;
	char **str;
	int x;
	int y;

	if (flag_res == 1)
		return ("Error: Config has extra parameters\n");
	data->count_params++;
	flag_res = 1;
	str = ft_split(line, ' ');
	if (res_id(str[0]) || darr_len(str) != 3)
		return ("Error: Invalid resolution\n");
	if (res_values(str[1]) || res_values(str[1]) ||
						ft_atoi(str[1]) < 10 || ft_atoi(str[2]) < 10)
		return ("Error: Invalid resolution\n");
	mlx_get_screen_size(data->mlx, &x, &y);
	if (ft_atoi(str[1]) > x)
		data->sizes.win_w = x;
	if (ft_atoi(str[2]) > y)
		data->sizes.win_h = y;
	if (ft_atoi(str[1]) < x || ft_atoi(str[2]) < y)
	{
		data->sizes.win_w = ft_atoi(str[1]);
		data->sizes.win_h = ft_atoi(str[2]);
	}
	return (NULL);
}

char *check_northern_tex(t_data *data, char *line)
{
	data->count_params++;
	static int flag_n;
	char **str;
	if (flag_n == 1)
		return ("Error: Config has extra parameters\n");
	flag_n = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid NO texture\n");
	data->n_tex.img = mlx_xpm_file_to_image(data->mlx, str[1], &data->n_tex.sizew, &data->n_tex.sizeh);
	data->n_tex.addr = mlx_get_data_addr(data->n_tex.img, &data->n_tex.bits_per_pixel, &data->n_tex.line_length,
									&data->n_tex.endian);
	return (NULL);
}

char *check_southern_tex(t_data *data, char *line)
{
	data->count_params++;
	static int flag_s;
	char **str;
	if (flag_s == 1)
		return ("Error: Config has extra parameters\n");
	flag_s = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid SO texture\n");
	data->s_tex.img = mlx_xpm_file_to_image(data->mlx, str[1], &data->s_tex.sizew, &data->s_tex.sizeh);
	data->s_tex.addr = mlx_get_data_addr(data->s_tex.img, &data->s_tex.bits_per_pixel, &data->s_tex.line_length,
									&data->s_tex.endian);
	return (NULL);
}

char *check_eastern_tex(t_data *data, char *line)
{
	data->count_params++;
	static int flag_e;
	char **str;
	if (flag_e == 1)
		return ("Error: Config has extra parameters\n");
	flag_e = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid EA texture\n");
	data->e_tex.img = mlx_xpm_file_to_image(data->mlx, str[1], &data->e_tex.sizew, &data->e_tex.sizeh);
	data->e_tex.addr = mlx_get_data_addr(data->e_tex.img, &data->e_tex.bits_per_pixel, &data->e_tex.line_length,
									&data->e_tex.endian);
	return (NULL);
}

char *check_western_tex(t_data *data, char *line)
{
	data->count_params++;
	static int flag_w;
	char **str;
	if (flag_w == 1)
		return ("Error: Config has extra parameters\n");
	flag_w = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid WE texture\n");
	data->w_tex.img = mlx_xpm_file_to_image(data->mlx, str[1], &data->w_tex.sizew, &data->w_tex.sizeh);
	data->w_tex.addr = mlx_get_data_addr(data->w_tex.img, &data->w_tex.bits_per_pixel, &data->w_tex.line_length,
									&data->w_tex.endian);
	return (NULL);
}

char *check_tex(t_data *data, char *line)
{
	if (line[0] == 'N')
		return (check_northern_tex(data, line));
	if (line[0] == 'S')
		return (check_southern_tex(data, line));
	if (line[0] == 'W')
		return (check_western_tex(data, line));
	if (line[0] == 'E')
		return (check_eastern_tex(data, line));
	return (NULL);
}

char *check_sprite(t_data *data, char *line)
{
	static int flag_spr;
	char **str;

	data->count_params++;
	if (flag_spr == 1)
		return ("Error: Config has extra parameters\n");
	flag_spr = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid sprite texture\n");
	data->sprite.img = mlx_xpm_file_to_image(data->mlx, str[1], &data->sprite.sizew, &data->sprite.sizeh);
	if (data->sprite.img == NULL)
		return ("Error: Invalid sprite texture\n");
	data->sprite.addr = mlx_get_data_addr(data->sprite.img, &data->sprite.bits_per_pixel, &data->sprite.line_length,
									&data->sprite.endian);
	return (NULL);
}

char *check_floor(t_data *data, char *line)
{
	static int flag_fl;
	char **str;
	int clr[3];

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
	printf("%d, %d, %d\n", clr[0], clr[1], clr[2]);
	data->floor_tex = clr[0] * 256 * 256 + clr[1] * 256 + clr[2];
	return (NULL);
}

char *check_ceiling(t_data *data, char *line)
{
	static int flag_fl;
	char **str;
	int clr[3];

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
	printf("%d, %d, %d\n", clr[0], clr[1], clr[2]);
	data->ceiling_tex = clr[0] * 256 * 256 + clr[1] * 256 + clr[2];
	return (NULL);
}


char *check_parameter(t_data *data, char *line)
{
	if (is_parameter(line) == 0 || !check_line(line, "012WESNCFR"))
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
	char *error = NULL;
	char *line;
	int fd = open(data->map_file, O_RDONLY);
	int flag = 0;

	if (check_format(data->map_file) || fd == -1)
	{
		error = ft_strdup("Error: Incorrect map file\n");
		return (error);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(error = ft_strdup(check_parameter(data, line))) != 0)
		{
			flag = 1;
			break ;
		}
		free(line);
	}
	printf("res - %zu %zu\n", data->sizes.win_w, data->sizes.win_h);
	if (flag == 1)
		return (error);
	return (NULL);

}
