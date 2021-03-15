/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:18:52 by ksiren            #+#    #+#             */
/*   Updated: 2021/03/15 20:15:06 by ksiren           ###   ########.fr       */
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
