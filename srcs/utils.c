/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:54:21 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 15:25:49 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || (size_t)x >= data->sizes.win_w || y < 0
			|| (size_t)y >= data->sizes.win_h))
		return ;
	dst = data->addr_3d + (y * data->line_length + x
			 * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_clr(t_texs *data, int x, int y, char *addr)
{
	char	*dst;

	dst = addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	exit_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}

void	put_sprite_to_window(t_data *data, t_sprite *sprite, int j, int i)
{
	int	color;

	color = get_clr(&data->sprite, i * sprite->koef,
			j * sprite->koef, data->sprite.addr);
	if (color > 0)
		my_mlx_pixel_put(data, sprite->h_offset + i,
			sprite->v_offset + j, color);
}
