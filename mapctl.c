/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:43:31 by skaynar           #+#    #+#             */
/*   Updated: 2025/08/21 00:39:43 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void list_to_char(t_data *data)
{
	t_map *fakemap;
	int size;
	char **map;
	int i;
	
	i = 0;
	fakemap = data->map;
	size = ft_mapsize(data->map);
	data->map->high = size;
	map = malloc(sizeof(char *) * size);
	while (fakemap)
	{
		map[i] = fakemap->map_line;
		i++;
		fakemap = fakemap->next;
	}
	map[i] = NULL;
	data->charmap = map;
}

int itelim(t_data *data)
{
	t_map *fakemap;
	int tmp;
	fakemap = data->map;
	tmp = fakemap->num;
	fakemap = fakemap->next;
	while (fakemap)
	{
		if(tmp + 1 == fakemap->num)
		{
			tmp = fakemap->num;
			fakemap = fakemap->next;
		}
		else
			return(printf("Error\nThere is empty line in map\n"), 1);	
	}
	return(0);
}

void find_player_position(char **map, t_data *data)
{
    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == data->player->start_pos)
            {
                data->player->player_x = x;
                data->player->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

int check_map(char **av, t_data *data)
{
    if(!check_map_name(av[1]))
        return(printf("Invalid map name\n"),0);
    if(!is_true_map(av[1], data))
			return(0);
	if(itelim(data))
		return(0);
	list_to_char(data);
	find_player_position(data->charmap, data);
	
	if(data->feature->we)
		printf("%s",data->feature->we);
	if(data->feature->so)
		printf("%s",data->feature->so);
	if(data->feature->no)
		printf("%s",data->feature->no);			
	if(data->feature->ea)
		printf("%s",data->feature->ea);
	if(data->feature->f)
		printf("%s",data->feature->f);
	if(data->feature->c)
		printf("%s",data->feature->c);
	if(!data->map)
		printf("data map yok\n");
    // while (data->map)
    // { 
	// 	if(data->map != NULL)
    //     {
	// 		printf("%d-%s",  data->map->num, data->map->map_line);
	// 		data->map = data->map->next;
	// 	}
	// 	else
	// 		printf("NOMAP\n");
	// }
    return(1);
}