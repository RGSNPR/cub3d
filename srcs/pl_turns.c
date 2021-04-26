/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_turns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:39:33 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 14:04:48 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pl_turn_left(t_data *data)
{
	data->player.p_angle -= STEP_DIR;
	if (data->player.p_angle < 0)
		data->player.p_angle += M_PI * 2;
	return ;
}

void	pl_turn_right(t_data *data)
{
	data->player.p_angle += STEP_DIR;
	if (data->player.p_angle > M_PI * 2)
		data->player.p_angle -= M_PI * 2;
	return ;
}
