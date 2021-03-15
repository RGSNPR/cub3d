/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:45:16 by ksiren            #+#    #+#             */
/*   Updated: 2021/03/15 20:39:11 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

#define mapWidth 24
#define mapHeight 24



void			my_mlx_pixel_put(t_data *data, int x, int y, int color, char *addr)
{
    char    *dst;

    dst = addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}


// void draw_3d(t_data *data, unsigned int c, int i, int x, int y)
// {
// 	int fheight = 360 / c;
// 	draw_square(MAP_SQUARE_SIZE, x, y, data, TURQUOISE);
// }

void angle(t_data *data)
{
	float c;
	float x = 0;
	float y = 0;
	float ang = data->player.p_angle;
	float i = 0;
	int size = 0;

	while (i < data->player.fov)
	{
		ang = data->player.p_angle - (data->player.fov / 2) + i;
		c = 0;
		while (c < 512)
		{
			x = data->player.posx + (c * cos(ang));
			y = data->player.posy + (c * sin(ang));
			c += 0.05;
			if (data->map[(unsigned int)y / MAP_SQUARE_SIZE][(unsigned int)x / MAP_SQUARE_SIZE] != '0')
			{
				size = (int)(512 / (c * cos(ang - data->player.p_angle)));
				draw_rect(size, size, (int)(512/(2 + i)), (int)(512/2 - size/2), data, TURQUOISE, data->addr_3d); //draw 3d visualisation
				break ;
			}
			draw_square(1, (int)x, (int)y, data, YELLOW, data->addr_map); // draw rays

		}
		i += data->player.fov / 256;
	}
	return ;
}

int key_hook(int keycode)
{
	printf("%d\n", keycode);
	return (printf("Hello from key_hook!\n"));
}

int				draw_hook(int keycode, t_data *data)
{
	draw_map(*data);
	draw_square(512, 0, 0, data, WHITE, data->addr_3d);
	if (keycode == ESC)
	{
		printf("<ESC> pressed ^o_o^ EXITING\n");
		exit(0);
	}
	if (keycode == W && data->map[(unsigned int)(data->player.posy + STEP * sin(data->player.p_angle)) / MAP_SQUARE_SIZE]
								[(unsigned int)(data->player.posx + STEP * cos(data->player.p_angle))/ MAP_SQUARE_SIZE] != '1')
	{
		data->player.posy += STEP * sin(data->player.p_angle);
		data->player.posx += STEP * cos(data->player.p_angle);
		draw_square(PLAYER_SIZE, data->player.posx, data->player.posy, data, GREEN, data->addr_map);
	}
	else if (keycode == S && data->map[(unsigned int)(data->player.posy - STEP * sin(data->player.p_angle)) / MAP_SQUARE_SIZE]
									[(unsigned int)(data->player.posx - STEP * cos(data->player.p_angle))/ MAP_SQUARE_SIZE] != '1')
	{
		data->player.posy -= STEP * sin(data->player.p_angle);
		data->player.posx -= STEP * cos(data->player.p_angle);
		draw_square(PLAYER_SIZE, data->player.posx, data->player.posy, data, GREEN, data->addr_map);
	}
	else if (keycode == A)
	{
		//data->player.posx = xinc;
		draw_square(PLAYER_SIZE, data->player.posx, data->player.posy, data, GREEN, data->addr_map);
	}
	else if (keycode == D)
	{
		data->player.posx += MAP_SQUARE_SIZE / STEP;
		draw_square(PLAYER_SIZE, data->player.posx, data->player.posy, data, GREEN, data->addr_map);
	}
	if (keycode == LEFT)
		data->player.p_angle -= M_PI / 18;
	else if (keycode == RIGHT)
		data->player.p_angle += M_PI / 18;
	angle(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_map, 30, 30);
	mlx_put_image_to_window(data->mlx, data->win, data->img_3d, 700, 30);
	return(0);
}



// int             close(/*int keycode,*/ t_vars *vars)
// {
//     return(mlx_destroy_window(vars->mlx, vars->win));
// }

int	main(void)
{

	t_data data;

	data.stolbs = 0;
	data.stroks = 0;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1280, 720, "Mama tut vse chernoe");
	data.player.posx = 32;
	data.player.posy = 32;
	data.player.p_angle = 0.;
	data.player.fov = M_PI/3.;

	data.map = fill_map_array(&data);
	data.img_map = mlx_new_image(data.mlx, 512, 512);
	data.img_3d = mlx_new_image(data.mlx, 512, 512);
	data.addr_map = mlx_get_data_addr(data.img_map, &data.bits_per_pixel, &data.line_length,
									&data.endian);
	data.addr_3d = mlx_get_data_addr(data.img_3d, &data.bits_per_pixel, &data.line_length,
									&data.endian);
	/*while ((unsigned int)i < data.stroks)
	{
		printf("%s\n", dva[i]);
		i++;
	}*/
	mlx_put_image_to_window(data.mlx, data.win, data.img_map, 10, 10);
	//mlx_put_image_to_window(data.mlx, data.win, data.img_3d, 700, 30);
	mlx_hook(data.win, 2, 0, draw_hook, &data);
	//mlx_hook(data.win, 2, 0, key_hook, NULL);
	mlx_loop(data.mlx);
	return (0);
}


