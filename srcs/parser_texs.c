/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:59:20 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:34:01 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_northern_tex(t_data *data, char *line)
{
	static int	flag_n;
	char		**str;

	data->count_params++;
	if (flag_n == 1)
		return ("Error: Config has extra parameters\n");
	flag_n = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid NO texture\n");
	data->n_tex.img = mlx_xpm_file_to_image(data->mlx, str[1],
			&data->n_tex.sizew, &data->n_tex.sizeh);
	data->n_tex.addr = mlx_get_data_addr(data->n_tex.img,
			&data->n_tex.bits_per_pixel, &data->n_tex.line_length,
			&data->n_tex.endian);
	return (NULL);
}

static char	*check_southern_tex(t_data *data, char *line)
{
	static int	flag_s;
	char		**str;

	data->count_params++;
	if (flag_s == 1)
		return ("Error: Config has extra parameters\n");
	flag_s = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid SO texture\n");
	data->s_tex.img = mlx_xpm_file_to_image(data->mlx, str[1],
			&data->s_tex.sizew, &data->s_tex.sizeh);
	data->s_tex.addr = mlx_get_data_addr(data->s_tex.img,
			&data->s_tex.bits_per_pixel, &data->s_tex.line_length,
			&data->s_tex.endian);
	return (NULL);
}

static char	*check_eastern_tex(t_data *data, char *line)
{
	static int	flag_e;
	char		**str;

	data->count_params++;
	if (flag_e == 1)
		return ("Error: Config has extra parameters\n");
	flag_e = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid EA texture\n");
	data->e_tex.img = mlx_xpm_file_to_image(data->mlx, str[1],
			&data->e_tex.sizew, &data->e_tex.sizeh);
	data->e_tex.addr = mlx_get_data_addr(data->e_tex.img,
			&data->e_tex.bits_per_pixel, &data->e_tex.line_length,
			&data->e_tex.endian);
	return (NULL);
}

static char	*check_western_tex(t_data *data, char *line)
{
	static int	flag_w;
	char		**str;

	data->count_params++;
	if (flag_w == 1)
		return ("Error: Config has extra parameters\n");
	flag_w = 1;
	str = ft_split(line, ' ');
	if (darr_len(str) != 2 || open(str[1], O_RDONLY) == -1)
		return ("Error: Invalid WE texture\n");
	data->w_tex.img = mlx_xpm_file_to_image(data->mlx, str[1],
			&data->w_tex.sizew, &data->w_tex.sizeh);
	data->w_tex.addr = mlx_get_data_addr(data->w_tex.img,
			&data->w_tex.bits_per_pixel, &data->w_tex.line_length,
			&data->w_tex.endian);
	return (NULL);
}

char	*check_tex(t_data *data, char *line)
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
