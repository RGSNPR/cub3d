/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:04:57 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 15:23:51 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fill_sprites(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
			{
				data->sprites[k].pos_x = j * MSS + MSS / 2;
				data->sprites[k].pos_y = i * MSS + MSS / 2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	check_dvoyki(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
				k++;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	data->count_sprite = k;
	data->sprites = (t_sprite *)malloc(sizeof(t_sprite) * k);
	fill_sprites(data);
}

void	swap_sprite(t_sprite *sprite_1, t_sprite *sprite_2)
{
	double	x;
	double	y;
	double	len;

	x = sprite_1->pos_x;
	y = sprite_1->pos_y;
	len = sprite_1->len;
	sprite_1->pos_x = sprite_2->pos_x;
	sprite_1->pos_y = sprite_2->pos_y;
	sprite_1->len = sprite_2->len;
	sprite_2->pos_x = x;
	sprite_2->pos_y = y;
	sprite_2->len = len;
}

void	sort_sprites(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < data->count_sprite)
	{
		data->sprites[i].len = sqrt(pow(data->player.posx
					- data->sprites[i].pos_x, 2) + pow(data->player.posy
					- data->sprites[i].pos_y, 2));
		if (i != 0 && data->sprites[i].len > data->sprites[i - 1].len)
			swap_sprite(&data->sprites[i], &data->sprites[i - 1]);
		i++;
	}
}
