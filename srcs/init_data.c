/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:39:56 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:13:45 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_data(t_data *data)
{
	data->player.w = 0;
	data->player.a = 0;
	data->player.s = 0;
	data->player.d = 0;
	data->player.left = 0;
	data->player.right = 0;
	data->player.fov = M_PI / 3.;
	data->mlx = mlx_init();
	data->count_params = 0;
}

void	ext_data_init(t_data *data)
{
	data->sizes.map_w = data->stolbs * MSS;
	data->sizes.map_h = data->stroks * MSS;
	data->win = mlx_new_window(data->mlx, data->sizes.win_w,
			data->sizes.win_h, "Mama tut vse chernoe");
	data->img_map = mlx_new_image(data->mlx,
			data->sizes.map_w, data->sizes.map_h);
	data->img_3d = mlx_new_image(data->mlx,
			data->sizes.win_w, data->sizes.win_h);
	data->addr_map = mlx_get_data_addr(data->img_map,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	data->addr_3d = mlx_get_data_addr(data->img_3d,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return ;
}
