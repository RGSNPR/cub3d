/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:45:16 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/19 20:12:29 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

#define mapWidth 24
#define mapHeight 24



void			my_mlx_pixel_put(t_data *data, int x, int y, int color, char *addr)
{
    char    *dst;

	if ((x < 0 || (size_t)x >= data->sizes.win_w || y < 0 || (size_t)y >= data->sizes.win_h))
		return ;
    dst = addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int			get_clr(t_texs *data, int x, int y, char *addr)
{
    char    *dst;

    dst = addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    return *(unsigned int *)dst;
}

double raycasting(t_data *data, double ang)
{
	double ax = 0;
	double ay = 0;
	double x = 0;
	double y = 0;
	double lenx = 0;
	double leny = 0;
	//double texx = 0;

	if (ang > M_PI * 2)
		ang -= M_PI * 2;
	if (ang < 0)
		ang += M_PI * 2;
	if (ang >= M_PI_2 * 3 && ang <= M_PI * 2)
	{
		ay = (int)(data->player.posy / MSS) * MSS - 0.000001;
		ax = data->player.posx - (data->player.posy - ay) / tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ay -= MSS;
			ax -= MSS / tan(ang);
		}
		lenx = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		x = ax;
		ax = (int)(data->player.posx / MSS) * MSS + MSS;
		ay = data->player.posy - (data->player.posx - ax) * tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ax += MSS;
			ay += MSS * tan(ang);
		}
		leny = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		y = ay;
	}
	else if (ang >= 0 && ang <= M_PI_2)
	{
		ay = (int)(data->player.posy / MSS) * MSS + MSS;
		ax = data->player.posx - (data->player.posy - ay) / tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ay += MSS;
			ax += MSS / tan(ang);
		}
		lenx = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		x = ax;
		ax = (int)(data->player.posx / MSS) * MSS + MSS;
		ay = data->player.posy - (data->player.posx - ax) * tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ax += MSS;
			ay += MSS * tan(ang);
		}
		leny = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		y = ay;
	}
	else if (ang >= M_PI_2 && ang <= M_PI)
	{
		ay = (int)(data->player.posy / MSS) * MSS + MSS;
		ax = data->player.posx - (data->player.posy - ay) / tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ay += MSS;
			ax += MSS / tan(ang);
		}
		lenx = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		x = ax;
		ax = (int)(data->player.posx / MSS) * MSS - 0.000001;
		ay = data->player.posy - (data->player.posx - ax) * tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ax -= MSS;
			ay -= MSS * tan(ang);
		}
		leny = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		y = ay;
	}
	else if (ang >= M_PI && ang <= M_PI_2 * 3)
	{
		ay = (int)(data->player.posy / MSS) * MSS - 0.000001;
		ax = data->player.posx - (data->player.posy - ay) / tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ay -= MSS;
			ax -= MSS / tan(ang);
		}
		lenx = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		x = ax;
		ax = (int)(data->player.posx / MSS) * MSS - 0.000001;
		ay = data->player.posy - (data->player.posx - ax) * tan(ang);
		while((unsigned int)ay / MSS < data->stroks && (unsigned int)ax / MSS < data->stolbs
				&& data->map[(unsigned int)ay / MSS][(unsigned int)ax / MSS] != '1')
		{
			ax -= MSS;
			ay -= MSS * tan(ang);
		}
		leny = sqrt(pow(data->player.posx - ax, 2) + pow(data->player.posy - ay, 2));
		y = ay;
	}

	data->wall_y = leny;
	data->wall_x = lenx;
	if (lenx < leny){
		data->tex_x = x;
		return (lenx);
	}
	data->tex_x = y;
	return (leny);
}

void draw_wall(t_data *data, double len, double ang, int x, t_texs *texs)
{
	int hwall;
	int start;
	int end;
	int fpoint;
	int tex_y;
	int tex_x;
	int color;
	double koef_y;
	double koef_x;
	len = len * cos(data->player.p_angle - ang);
	hwall = MSS / len * (data->sizes.win_w / 2 / tan(data->player.fov / 2));
	// while (hwall % 2)
	// {
	// 	hwall -= 1;
	// }

	start = data->sizes.win_h / 2 - hwall / 2;
	end = data->sizes.win_h / 2 + hwall / 2;
	fpoint = start;
	koef_y = (double)texs->sizeh / (end - start);
	koef_x = (double)texs->sizew / MSS;
	data->tex_x = data->tex_x - ((int)(data->tex_x / MSS) * MSS /*- 0.000001*/);
	tex_x = data->tex_x * koef_x;
	if (start < 0)
		start = 0;
	while (start < end && (size_t)start < data->sizes.win_h)
	{
		tex_y = ((start - fpoint) * koef_y);
		color = get_clr(texs, tex_x, tex_y, texs->addr);
		my_mlx_pixel_put(data, x, (int)start, color, data->addr_3d);
		start++;
	}
}

void render(t_data *data)
{
	double len = 0;
	double step;
	double start;
	double end;
	//int i = 0;
	int x = 0;
	double *arr;

	arr = (double *)malloc(sizeof(double) * (data->sizes.win_w + 1));
	start = data->player.p_angle - data->player.fov / 2;
	end = data->player.p_angle + data->player.fov / 2;
	step = data->player.fov / data->sizes.win_w;
	while(start < end)
	{
		len = raycasting(data, start);
		arr[x] = len;
		// while(i < len)
		// {
		// 	my_mlx_pixel_put(data, data->player.posx + i * cos(start),
		// 						data->player.posy + i * sin(start), YELLOW, data->addr_map);
		// 	i++;
		// }
		//i = 0;
		if (data->wall_x == len)
		{
			if ((start > 0 && start < M_PI) || start > M_PI * 2)
				draw_wall(data, len, start, x, &data->n_tex);
			else
				draw_wall(data, len, start, x,  &data->s_tex);
		}
		else if (data->wall_y == len)
		{
			if (start > M_PI_2 && start < M_PI_2 * 3)
				draw_wall(data, len, start, x,  &data->e_tex);
			else
				draw_wall(data, len, start, x,  &data->w_tex);
		}
		start += step;
		x++;
	}
	sort_sprites(data);
	x = 0;
	while(x < data->count_sprite)
	{
		draw_sprite(data, &data->sprites[x], arr);
		x++;
	}

	//len = raycasting(data, data->player.p_angle);
	// while(i < len)
	// {
	// 	my_mlx_pixel_put(data, data->player.posx + i * cos(data->player.p_angle),
	// 							data->player.posy + i * sin(data->player.p_angle), RED, data->addr_map);
	// 	i++;
	// }
}

int key_release(int keycode, t_data *data)
{
	if (keycode == W && data->player.w == 1)
		data->player.w = 0;
	if (keycode == A && data->player.a == 1)
		data->player.a = 0;
	if (keycode == S && data->player.s == 1)
		data->player.s = 0;
	if (keycode == D && data->player.d == 1)
		data->player.d = 0;
	if (keycode == LEFT && data->player.left == 1)
		data->player.left = 0;
	if (keycode == RIGHT && data->player.right == 1)
		data->player.right = 0;
	return (0);
}

int red_cross()
{
	exit(0);
}

int key_press(int keycode, t_data *data)
{
	//printf("keycode = %d\n", keycode);
	if (keycode == ESC)
	{
		printf("<ESC> pressed ^o_o^ EXITING\n");
		exit(0);
	}

	if (keycode == W && data->player.w == 0)
		data->player.w = 1;
	if (keycode == A && data->player.a == 0)
		data->player.a = 1;
	if (keycode == S && data->player.s == 0)
		data->player.s = 1;
	if (keycode == D && data->player.d == 0)
		data->player.d = 1;
	if (keycode == LEFT && data->player.left == 0)
		data->player.left = 1;
	if (keycode == RIGHT && data->player.right == 0)
		data->player.right = 1;
	return (0);
}

void draw_sprite(t_data *data, t_sprite *sprite, double *arr)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = 0;
    double sprite_dir = atan2(sprite->pos_y - data->player.posy, sprite->pos_x - data->player.posx);
    while (sprite_dir - data->player.p_angle >  M_PI) sprite_dir -= 2*M_PI;
    while (sprite_dir - data->player.p_angle < -M_PI) sprite_dir += 2*M_PI;

    double sprite_dist = sprite->len;
    int sprite_screen_size = MSS / sprite_dist * (data->sizes.win_w / 2 / tan(data->player.fov / 2));
    size_t h_offset = (sprite_dir - data->player.p_angle)*(data->sizes.win_w)/(data->player.fov) + (data->sizes.win_w)/2 - sprite_screen_size/2;
    size_t v_offset = data->sizes.win_h/2 - sprite_screen_size/2;
	double koef = (double)data->sprite.sizeh / sprite_screen_size;
	if (h_offset < 0)
		i = -h_offset;
	if (v_offset < 0)
		j = -v_offset;
	while (i < sprite_screen_size)
	{
		if (h_offset + i >= data->sizes.win_w || arr[i + h_offset] < sprite_dist)
		{
			i++;
			continue ;
		}
		j = 0;
		while (j < sprite_screen_size)
		{
			if (v_offset + j >= data->sizes.win_h)
			{
				j++;
				continue ;
			}
			if ((color = get_clr(&data->sprite, i * koef, j * koef, data->sprite.addr)) > 0)
			{
				my_mlx_pixel_put(data, h_offset + i, v_offset + j, color, data->addr_3d);
			}
			j++;
		}
		i++;
	}
}

int				draw_hook(t_data *data)
{
	draw_ceiling(data, data->ceiling_tex, data->addr_3d);
	draw_floor(data, data->floor_tex, data->addr_3d);

	if (data->player.w == 1 && data->map[(unsigned int)(data->player.posy + (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS]
								[(unsigned int)(data->player.posx + (STEP + PLAYER_SIZE) * cos(data->player.p_angle))/ MSS] != '1')
	{
		data->player.posy += STEP * sin(data->player.p_angle);
		data->player.posx += STEP * cos(data->player.p_angle);
	}
	else if (data->player.s == 1 && data->map[(unsigned int)(data->player.posy - (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS]
									[(unsigned int)(data->player.posx - (STEP + PLAYER_SIZE) * cos(data->player.p_angle))/ MSS] != '1')
	{
		data->player.posy -= STEP * sin(data->player.p_angle);
		data->player.posx -= STEP * cos(data->player.p_angle);
	}
	else if (data->player.a == 1 && data->map[(unsigned int)(data->player.posy - (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS]
									[(unsigned int)(data->player.posx + (STEP + PLAYER_SIZE) * sin(data->player.p_angle))/ MSS] != '1')
	{
		data->player.posx += STEP * sin(data->player.p_angle);
		data->player.posy -= STEP * cos(data->player.p_angle);
	}
	else if (data->player.d == 1 && data->map[(unsigned int)(data->player.posy + (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS]
									[(unsigned int)(data->player.posx - (STEP + PLAYER_SIZE) * sin(data->player.p_angle))/ MSS] != '1')
	{
		data->player.posx -= STEP * sin(data->player.p_angle);
		data->player.posy += STEP * cos(data->player.p_angle);
	}
	if (data->player.left == 1)
	{
		data->player.p_angle -= STEP_DIR;
		// if (data->player.p_angle > M_PI * 2)
		// 	data->player.p_angle -= M_PI * 2;
		if (data->player.p_angle < 0)
			data->player.p_angle += M_PI * 2;
	}
	else if (data->player.right == 1)
	{
		data->player.p_angle += STEP_DIR;
		if (data->player.p_angle > M_PI * 2)
			data->player.p_angle -= M_PI * 2;
		// if (data->player.p_angle < 0)
		// 	data->player.p_angle += M_PI * 2;
	}
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_3d, 0, 0);
	return (0);
}

int key_hook(t_data *data)
{
	draw_hook(data);
	mlx_hook(data->win, 2, 1L, key_press, data);
	mlx_hook(data->win, 17, 0L, red_cross, NULL);
	mlx_hook(data->win, 3, 1L<<1, key_release, data);
	mlx_do_sync(data->mlx);
	return (0);
}

// int             close(/*int keycode,*/ t_vars *vars)
// {
//     return(mlx_destroy_window(vars->mlx, vars->win));
// }

int	main(int argc, char **argv)
{

	t_data data;

	data.stolbs = 0;
	data.stroks = 0;

	// data.sizes.win_w = 1024;
	// data.sizes.win_h = 512;

	data.player.posx = 30;
	data.player.posy = 30;
	data.player.p_angle = M_PI_2 * 3;
	data.player.fov = M_PI/3.;
	data.player.w = 0;
	data.player.a = 0;
	data.player.s = 0;
	data.player.d = 0;
	data.player.left = 0;
	data.player.right = 0;

	if (argc < 2)
	{
		ft_putstr_fd("\nError: Vbey kartu dolbaeb\n", 0);
		exit(0);
	}


	// data.n_tex.img = mlx_xpm_file_to_image(data.mlx, "WALL71.xpm", &data.n_tex.sizew, &data.n_tex.sizeh);
	// data.n_tex.addr = mlx_get_data_addr(data.n_tex.img, &data.n_tex.bits_per_pixel, &data.n_tex.line_length,
	// 								&data.n_tex.endian);
	data.mlx = mlx_init();
	data.map_file = argv[1];
	data.count_params = 0;

	char *error = NULL;
	if ((error = parser(&data)) != NULL)
	{
		ft_putstr_fd("( ._.)( ._.)( ._.)( ._.)\n", 0);
		ft_putstr_fd(error, 2);
		ft_putstr_fd("(._. )(._. )(._. )(._. )\n", 0);
		exit (0);
	}
	printf("params counted - %d\n", data.count_params);
	if (data.count_params != 8)
	{
		ft_putstr_fd("( ._.)( ._.)( ._.)( ._.)\n", 0);
		ft_putstr_fd("Error: Not enough parameters\n", 2);
		ft_putstr_fd("(._. )(._. )(._. )(._. )\n", 0);
		exit(0);
	}

	data.win = mlx_new_window(data.mlx, data.sizes.win_w, data.sizes.win_h, "Mama tut vse chernoe");

	data.map = fill_map_array(&data);
	check_map_validity(&data, data.map);
	check_player(&data);
	check_dvoyki(&data);
	data.sizes.map_w = data.stolbs * MSS;
	data.sizes.map_h = data.stroks * MSS;
	data.img_map = mlx_new_image(data.mlx, data.sizes.map_w, data.sizes.map_h);
	data.img_3d = mlx_new_image(data.mlx, data.sizes.win_w, data.sizes.win_h);

	data.addr_map = mlx_get_data_addr(data.img_map, &data.bits_per_pixel, &data.line_length,
									&data.endian);
	data.addr_3d = mlx_get_data_addr(data.img_3d, &data.bits_per_pixel, &data.line_length,
									&data.endian);


	/*while ((unsigned int)i < data.stroks)
	{
		printf("%s\n", dva[i]);
		i++;
	}*/
	// mlx_put_image_to_window(data.mlx, data.win, data.img_map, 10, 10);
	// mlx_put_image_to_window(data.mlx, data.win, data.img_3d, 700, 30);

	//draw_hook(&data);
	// mlx_hook(data.win, 2, 1L, key_press, &data);
	// mlx_hook(data.win, 3, 1L<<1, key_release, &data);


	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}

