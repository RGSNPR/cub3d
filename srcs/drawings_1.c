/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:45:34 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:11:57 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_wall(t_data *data, double ang, t_tx *tx, t_texs *texs)
{
	t_wall	wall;

	tx->len = tx->len * cos(data->player.p_angle - ang);
	wall.hwall = MSS / tx->len * (data->sizes.win_w
			/ 2 / tan(data->player.fov / 2));
	wall.start = data->sizes.win_h / 2 - wall.hwall / 2;
	wall.end = data->sizes.win_h / 2 + wall.hwall / 2;
	wall.fpoint = wall.start;
	wall.koef_y = (double)texs->sizeh / (wall.end - wall.start);
	wall.koef_x = (double)texs->sizew / MSS;
	data->tex_x = data->tex_x - ((int)(data->tex_x / MSS) *MSS);
	wall.tex_x = data->tex_x * wall.koef_x;
	if (wall.start < 0)
		wall.start = 0;
	while (wall.start < wall.end && (size_t)wall.start < data->sizes.win_h)
	{
		wall.tex_y = ((wall.start - wall.fpoint) * wall.koef_y);
		wall.color = get_clr(texs, wall.tex_x, wall.tex_y, texs->addr);
		my_mlx_pixel_put(data, tx->x, (int)wall.start, wall.color);
		wall.start++;
	}
}

void	render_1(t_data *data, double start, double *arr, double step)
{
	t_tx	tx;

	tx.x = 0;
	while (start < data->player.p_angle + data->player.fov / 2)
	{
		tx.len = raycasting(data, start);
		arr[tx.x] = tx.len;
		if (data->wall_x == tx.len)
		{
			if ((start > 0 && start <= M_PI) || start >= M_PI * 2)
				draw_wall(data, start, &tx, &data->n_tex);
			else
				draw_wall(data, start, &tx, &data->s_tex);
		}
		else if (data->wall_y == tx.len)
		{
			if (start >= M_PI_2 && start < M_PI_2 * 3)
				draw_wall(data, start, &tx, &data->e_tex);
			else
				draw_wall(data, start, &tx, &data->w_tex);
		}
		start += step;
		tx.x++;
	}
}

void	render(t_data *data)
{
	double	step;
	double	start;
	int		x;
	double	*arr;

	draw_ceiling(data, data->ceiling_tex);
	draw_floor(data, data->floor_tex);
	arr = (double *)malloc(sizeof(double) * (data->sizes.win_w + 1));
	start = data->player.p_angle - data->player.fov / 2;
	step = data->player.fov / data->sizes.win_w;
	sort_sprites(data);
	x = 0;
	render_1(data, start, arr, step);
	while (x < data->count_sprite)
	{
		draw_sprite(data, &data->sprites[x], arr);
		x++;
	}
	return ;
}
