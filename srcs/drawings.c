/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:18:52 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:06:44 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_floor(t_data *data, unsigned int color)
{
	int	maxx;
	int	maxy;
	int	x;
	int	y;

	maxx = data->sizes.win_w;
	maxy = data->sizes.win_h;
	x = 0;
	y = data->sizes.win_h / 2;
	while (y < maxy)
	{
		while (x < maxx)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_ceiling(t_data *data, unsigned int color)
{
	int	maxx;
	int	maxy;
	int	x;
	int	y;

	maxx = data->sizes.win_w;
	maxy = data->sizes.win_h / 2;
	x = 0;
	y = 0;
	while (y < maxy)
	{
		while (x < maxx)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	count_koef(t_data *data, t_sprite *sprite)
{
	sprite->dir = atan2(sprite->pos_y - data->player.posy,
			sprite->pos_x - data->player.posx);
	while (sprite->dir - data->player.p_angle > M_PI)
		sprite->dir -= 2 * M_PI;
	while (sprite->dir - data->player.p_angle < -M_PI)
		sprite->dir += 2 * M_PI;
	sprite->dist = sprite->len;
	sprite->screen_size = MSS / sprite->dist * (data->sizes.win_w
			/ 2 / tan(data->player.fov / 2));
	sprite->h_offset = (sprite->dir - data->player.p_angle)
		 * (data->sizes.win_w) / (data->player.fov) + (data->sizes.win_w)
		/ 2 - sprite->screen_size / 2;
	sprite->v_offset = data->sizes.win_h / 2 - sprite->screen_size / 2;
	sprite->koef = (double)data->sprite.sizeh / sprite->screen_size;
	return ;
}

static void	count_sprite(t_data *data, t_sprite *sprite, double *arr, int i)
{
	int	j;

	while (i < sprite->screen_size)
	{
		if (sprite->h_offset + i >= (int)data->sizes.win_w
			|| arr[i + sprite->h_offset] < sprite->dist)
		{
			i++;
			continue ;
		}
		j = 0;
		while (j < sprite->screen_size)
		{
			if (sprite->v_offset + j >= (int)data->sizes.win_h)
			{
				j++;
				continue ;
			}
			put_sprite_to_window(data, sprite, j, i);
			j++;
		}
		i++;
	}
}

void	draw_sprite(t_data *data, t_sprite *sprite, double *arr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	count_koef(data, sprite);
	if (sprite->h_offset < 0)
		i = -(sprite->h_offset);
	if (sprite->v_offset < 0)
		j = -(sprite->v_offset);
	if (sprite->dist < 5)
		return ;
	count_sprite(data, sprite, arr, i);
	return ;
}
