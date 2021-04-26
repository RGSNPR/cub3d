/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:36:47 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 14:04:12 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pl_move_fwd(t_data *data)
{
	if (data->map[(unsigned int)(data->player.posy
			+ (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS]
	[(unsigned int)(data->player.posx
			+ (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS] != '1')
	{
		data->player.posy += STEP * sin(data->player.p_angle);
		data->player.posx += STEP * cos(data->player.p_angle);
	}
	return ;
}

void	pl_move_bwd(t_data *data)
{
	if (data->map[(unsigned int)(data->player.posy
			- (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS]
	[(unsigned int)(data->player.posx
			- (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS] != '1')
	{
		data->player.posy -= STEP * sin(data->player.p_angle);
		data->player.posx -= STEP * cos(data->player.p_angle);
	}
	return ;
}

void	pl_move_lft(t_data *data)
{
	if (data->map[(unsigned int)(data->player.posy
			- (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS]
	[(unsigned int)(data->player.posx
			+ (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS] != '1')
	{
		data->player.posx += STEP * sin(data->player.p_angle);
		data->player.posy -= STEP * cos(data->player.p_angle);
	}
	return ;
}

void	pl_move_rght(t_data *data)
{
	if (data->map[(unsigned int)(data->player.posy
			+ (STEP + PLAYER_SIZE) * cos(data->player.p_angle)) / MSS]
	[(unsigned int)(data->player.posx
			- (STEP + PLAYER_SIZE) * sin(data->player.p_angle)) / MSS] != '1')
	{
		data->player.posx -= STEP * sin(data->player.p_angle);
		data->player.posy += STEP * cos(data->player.p_angle);
	}
	return ;
}
