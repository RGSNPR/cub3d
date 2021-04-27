/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:05:05 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/27 20:07:27 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	res_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'R' || i > 1)
			return (1);
		i++;
	}
	return (0);
}

static int	res_values(char *str)
{
	int	i;

	i = 0;
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
	static int	flag_res;
	char		**str;
	int			x;
	int			y;

	if (flag_res == 1)
		return ("Error: Config has extra parameters\n");
	data->count_params++;
	flag_res = 1;
	str = ft_split(line, ' ');
	if (res_id(str[0]) || darr_len(str) != 3 || res_values(str[1])
		|| res_values(str[2]) || ft_atoi(str[1]) < 10 || ft_atoi(str[2]) < 10)
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
	clean_array(str);
	return (NULL);
}
