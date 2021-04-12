/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:18:52 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/06 19:45:09 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void draw_square(int size, int x, int y, t_data *data, unsigned int color, char *addr)
{
	int maxx = x + size;
	int maxy = y + size;
	int startx;

	startx = x;
	while (y < maxy)
	{
		while (x < maxx)
		{
			my_mlx_pixel_put(data, x, y, color, addr);
			x++;
		}
		x = startx;
		y++;
	}
}

void draw_rect(int xsize, int ysize, int x, int y, t_data *data, unsigned int color, char *addr)
{
	int maxx = x + xsize;
	int maxy = y + ysize;
	int startx;

	startx = x;
	while (y < maxy)
	{
		while (x < maxx)
		{
			my_mlx_pixel_put(data, x, y, color, addr);
			x++;
		}
		x = startx;
		y++;
	}
}

void draw_floor(t_data *data, unsigned int color, char *addr)
{
	draw_rect(data->sizes.win_w, data->sizes.win_h / 2, 0, data->sizes.win_h / 2, data, color, addr);
}

void draw_ceiling(t_data *data, unsigned int color, char *addr)
{
	draw_rect(data->sizes.win_w, data->sizes.win_h / 2, 0, 0, data, color, addr);
}
