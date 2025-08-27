/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:43:31 by skaynar           #+#    #+#             */
/*   Updated: 2025/08/27 13:47:40 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	list_to_char(t_data *data)
{
	t_map	*fakemap;
	int		size;
	char	**map;
	int		i;

	i = 0;
	fakemap = data->map;
	size = ft_mapsize(data->map);
	data->high = size;
	map = malloc(sizeof(char *) * (size + 1));
	while (fakemap)
	{
		if ((int)ft_strlen(fakemap->map_line) > data->widht)
			data->widht = (int)ft_strlen(fakemap->map_line);
		map[i] = ft_strdup(fakemap->map_line);
		i++;
		fakemap = fakemap->next;
	}
	map[i] = NULL;
	data->char_map = map;
}

int	itelim(t_data *data)
{
	t_map	*fakemap;
	int		tmp;

	fakemap = data->map;
	tmp = fakemap->num;
	fakemap = fakemap->next;
	while (fakemap)
	{
		if (tmp + 1 == fakemap->num)
		{
			tmp = fakemap->num;
			fakemap = fakemap->next;
		}
		else
			return (printf("Error\nThere is empty line in map\n"), 1);
	}
	data->widht = 0;
	return (0);
}

void	find_player_position(char **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == data->player->start_pos)
			{
				data->player->map_x = x;
				data->player->map_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}


int	ff_empty(char **a, char c)
{
	int	i;
	int	j;


	i = 0;
	while (a[i])
	{
		printf("%s",a[i]);
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == '0')
			{
				if(i == 0)
					return(1);
				if (i > 0 && a[i - 1][j] && a[i - 1][j] != '1' && a[i - 1][j] != '0' && a[i - 1][j] != c)
					return (1);
				if (a[i + 1] && a[i + 1][j] != '1' && a[i + 1][j] != '0' && a[i + 1][j] != c)
					return (1);
				if (j > 0 && a[i][j - 1] && a[i][j - 1] != '1' && a[i][j - 1] != '0' && a[i][j - 1] != c)
					return (1);
				if (a[i][j + 1] && a[i][j + 1]  && a[i][j + 1] != '1' && a[i][j + 1] != '0' && a[i][j + 1] != c)
					return (1);
				if(!a[i+1] || !a[i-1] || !a[i][j+1] || !a[i][j -1 ])
					return(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void ff_double(char **map, int x, int y, t_data *data)
{
	
    if (x < 0 || x >= data->high || y < 0 || !map[x] || map[x][y] == '\0')
		return;

    if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != data->player->start_pos)
        return;
    
    map[x][y] = '*';

    ff_double(map, x + 1, y, data);
    ff_double(map, x - 1, y, data);
    ff_double(map, x, y + 1, data);
    ff_double(map, x, y - 1, data);
}



int	check_map_zeros(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (1);

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char **av, t_data *data)
{
	int	fd;

	if (!check_map_name(av[1]))
		return (printf("Invalid map name\n"), 0);
	data->line_num = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (close(fd), printf("Error\nCould not open map file\n"), 0);
	if (!is_true_map(data, fd, 0))
		return (0);
	if (itelim(data))
		return (0);
	list_to_char(data);
	find_player_position(data->char_map, data);
	data->fakemap = copy_char_matrix(data->char_map, 0);
	if(ff_empty(data->fakemap, data->player->start_pos))
		return(printf("ff_empty\n"),0);
	ff_double(data->fakemap,data->player->map_x, data->player->map_y,data);
	int i = -1;
	while(data->fakemap[++i])
		printf("%s",data->fakemap[i]);
	if(check_map_zeros(data->fakemap))
		return(printf("Double map\n"), 0);
	// if (flood_fill(data->player->map_y, data->player->map_x, data,
	// 		data->player->start_pos))
	// 	return (printf("Error\nInvalid map\n"), 0);
	return (1);
}
