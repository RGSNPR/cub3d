#include "cub.h"

void	calculate_point_div_neg(t_data *data, t_ray *ray, double ang)
{
	while ((unsigned int)ray->ay / MSS < data->stroks
		&& (unsigned int)ray->ax / MSS < data->stolbs
		&& data->map[(unsigned int)ray->ay / MSS]
		[(unsigned int)ray->ax / MSS] != '1')
	{
		ray->ay -= MSS;
		ray->ax -= MSS / tan(ang);
	}
}

void	calculate_point_mul_neg(t_data *data, t_ray *ray, double ang)
{
	while ((unsigned int)ray->ay / MSS < data->stroks
		&& (unsigned int)ray->ax / MSS < data->stolbs
		&& data->map[(unsigned int)ray->ay / MSS]
		[(unsigned int)ray->ax / MSS] != '1')
	{
		ray->ax -= MSS;
		ray->ay -= MSS * tan(ang);
	}
}

void	calculate_point_div_pos(t_data *data, t_ray *ray, double ang)
{
	while ((unsigned int)ray->ay / MSS < data->stroks
		&& (unsigned int)ray->ax / MSS < data->stolbs
		&& data->map[(unsigned int)ray->ay / MSS]
		[(unsigned int)ray->ax / MSS] != '1')
	{
		ray->ay += MSS;
		ray->ax += MSS / tan(ang);
	}
}

void	calculate_point_mul_pos(t_data *data, t_ray *ray, double ang)
{
	while ((unsigned int)ray->ay / MSS < data->stroks
		&& (unsigned int)ray->ax / MSS < data->stolbs
		&& data->map[(unsigned int)ray->ay / MSS]
		[(unsigned int)ray->ax / MSS] != '1')
	{
		ray->ax += MSS;
		ray->ay += MSS * tan(ang);
	}
}
