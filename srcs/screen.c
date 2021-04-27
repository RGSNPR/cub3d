/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:54:41 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/27 20:33:34 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	take_pix(t_data *data, int line, int *x, int y)
{
	char	save;
	int		a;

	a = 4;
	while (--a >= 0)
	{
		save = data->addr_3d[*x + line * data->line_length];
		data->addr_3d[*x + line * data->line_length]
			= data->addr_3d[y - a + (line * data->line_length - 1)];
		data->addr_3d[y - a + (line * data->line_length - 1)] = save;
		*x += 1;
	}
}

void	take_line(t_data *data)
{
	int		line;
	int		x;
	int		y;

	line = -1;
	while (++line < (int)data->sizes.win_h)
	{
		x = 0;
		y = data->line_length;
		while (x < y)
		{
			take_pix(data, line, &x, y);
			y -= 4;
		}
	}
}

void	name_file(t_data *data, int fd)
{
	int		size;
	int		n;

	size = 40;
	n = 1;
	write(fd, &size, 4);
	write(fd, &data->sizes.win_w, 4);
	write(fd, &data->sizes.win_h, 4);
	write(fd, &n, 2);
	write(fd, &data->bits_per_pixel, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 28);
}

void	screenshot(t_data *data)
{
	int		fd;
	int		size;
	int		i;
	int		a;

	fd = open("screenvs.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IROTH);
	if (fd < 0)
	{
		printf("failed to create file");
		exit(1);
	}
	size = 14 + 40 + data->sizes.win_w * data->sizes.win_h * 4;
	i = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &i, 4);
	name_file(data, fd);
	take_line(data);
	a = data->sizes.win_w * data->sizes.win_h;
	while (--a >= 0)
		write(fd, &data->addr_3d[a * data->bits_per_pixel / 8], 4);
	close(fd);
	exit(0);
}
