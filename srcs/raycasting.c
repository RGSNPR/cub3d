/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:41:33 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 15:21:14 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycast_1st(t_ray *ray, t_data *data, double ang)
{
	ray->ay = (int)(data->player.posy / MSS) *MSS - 0.000001;
	ray->ax = data->player.posx - (data->player.posy - ray->ay) / tan(ang);
	calculate_point_div_neg(data, ray, ang);
	ray->lenx = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->x = ray->ax;
	ray->ax = (int)(data->player.posx / MSS) *MSS + MSS;
	ray->ay = data->player.posy - (data->player.posx - ray->ax) * tan(ang);
	calculate_point_mul_pos(data, ray, ang);
	ray->leny = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->y = ray->ay;
	return ;
}

void	raycast_2nd(t_ray *ray, t_data *data, double ang)
{
	ray->ay = (int)(data->player.posy / MSS) *MSS + MSS;
	ray->ax = data->player.posx - (data->player.posy - ray->ay) / tan(ang);
	calculate_point_div_pos(data, ray, ang);
	ray->lenx = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->x = ray->ax;
	ray->ax = (int)(data->player.posx / MSS) *MSS + MSS;
	ray->ay = data->player.posy - (data->player.posx - ray->ax) * tan(ang);
	calculate_point_mul_pos(data, ray, ang);
	ray->leny = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->y = ray->ay;
	return ;
}

void	raycast_3rd(t_ray *ray, t_data *data, double ang)
{
	ray->ay = (int)(data->player.posy / MSS) *MSS + MSS;
	ray->ax = data->player.posx - (data->player.posy - ray->ay) / tan(ang);
	calculate_point_div_pos(data, ray, ang);
	ray->lenx = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->x = ray->ax;
	ray->ax = (int)(data->player.posx / MSS) *MSS - 0.000001;
	ray->ay = data->player.posy - (data->player.posx - ray->ax) * tan(ang);
	calculate_point_mul_neg(data, ray, ang);
	ray->leny = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->y = ray->ay;
}

void	raycast_4th(t_ray *ray, t_data *data, double ang)
{
	ray->ay = (int)(data->player.posy / MSS) *MSS - 0.000001;
	ray->ax = data->player.posx - (data->player.posy - ray->ay) / tan(ang);
	calculate_point_div_neg(data, ray, ang);
	ray->lenx = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->x = ray->ax;
	ray->ax = (int)(data->player.posx / MSS) *MSS - 0.000001;
	ray->ay = data->player.posy - (data->player.posx - ray->ax) * tan(ang);
	calculate_point_mul_neg(data, ray, ang);
	ray->leny = sqrt(pow(data->player.posx - ray->ax, 2)
			+ pow(data->player.posy - ray->ay, 2));
	ray->y = ray->ay;
}

double	raycasting(t_data *data, double ang)
{
	t_ray	ray;

	if (ang > M_PI * 2)
		ang -= M_PI * 2;
	if (ang < 0)
		ang += M_PI * 2;
	if (ang >= M_PI_2 * 3 && ang <= M_PI * 2)
		raycast_1st(&ray, data, ang);
	else if (ang >= 0 && ang <= M_PI_2)
		raycast_2nd(&ray, data, ang);
	else if (ang >= M_PI_2 && ang <= M_PI)
		raycast_3rd(&ray, data, ang);
	else if (ang >= M_PI && ang <= M_PI_2 * 3)
		raycast_4th(&ray, data, ang);
	data->wall_y = ray.leny;
	data->wall_x = ray.lenx;
	if (ray.lenx < ray.leny)
	{
		data->tex_x = ray.x;
		return (ray.lenx);
	}
	data->tex_x = ray.y;
	return (ray.leny);
}
