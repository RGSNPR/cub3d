/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:45:16 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/27 20:33:56 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map(t_data *data)
{
	check_map_validity(data, data->map);
	check_player(data);
	check_dvoyki(data);
	return ;
}

int	check_argc(int argc, t_data *data, char **argv)
{
	if (argc < 2)
		exit_error("Error: Map not found\n");
	else if (argc > 3)
		exit_error("Error: Too many arguments\n");
	else if (argc == 2)
		return (1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
	{
		data->sizes.win_w = 1280;
		data->sizes.win_h = 720;
		screenshot(data);
	}
	else if (argc == 3
		&& ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0)
		exit_error("Error: Bad argument\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*error;

	init_data(&data);
	if (argc < 2)
		exit_error("Error: Vbey kartu, pozhaluysta, brat\n");
	data.map_file = argv[1];
	error = NULL;
	error = parser(&data);
	if (error != NULL)
		exit_error(error);
	if (data.count_params != 8)
		exit_error("Error: Not enough parameters\n");
	data.map = fill_map_array(&data);
	check_map(&data);
	ext_data_init(&data);
	draw_ceiling(&data, data.ceiling_tex);
	draw_floor(&data, data.floor_tex);
	render(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img_3d, 0, 0);
	check_argc(argc, &data, argv);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
