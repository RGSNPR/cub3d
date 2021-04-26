/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:44:19 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 13:14:14 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_release(int keycode, t_data *data)
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

int	red_cross(void)
{
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
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

int	draw_hook(t_data *data)
{
	if (data->player.w == 1)
		pl_move_fwd(data);
	else if (data->player.s == 1)
		pl_move_bwd(data);
	else if (data->player.a == 1)
		pl_move_lft(data);
	else if (data->player.d == 1)
		pl_move_rght(data);
	if (data->player.left == 1)
		pl_turn_left(data);
	else if (data->player.right == 1)
		pl_turn_right(data);
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_3d, 0, 0);
	return (0);
}

int	key_hook(t_data *data)
{
	draw_hook(data);
	mlx_hook(data->win, 2, 1L, key_press, data);
	mlx_hook(data->win, 17, 0L, red_cross, NULL);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_do_sync(data->mlx);
	return (0);
}
