#include "cub.h"

int	is_parameter(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "S ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	is_player_placed(t_data *data, char c)
{
	static int	flag_pl;

	if (c == 'N')
		data->player.p_angle = M_PI_2 * 3;
	else if (c == 'S')
		data->player.p_angle = M_PI_2;
	else if (c == 'W')
		data->player.p_angle = M_PI;
	else if (c == 'E')
		data->player.p_angle = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (flag_pl == 1)
			exit_error("Error: more than one player\n");
		flag_pl = 1;
		return (1);
	}
	return (0);
}

void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player_placed(data, data->map[i][j]))
			{
				data->player.posx = j * MSS + MSS / 2;
				data->player.posy = i * MSS + MSS / 2;
				flag = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		exit_error("Error: Player is not presented\n");
	return ;
}
