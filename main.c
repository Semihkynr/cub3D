/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:55:12 by skaynar           #+#    #+#             */
/*   Updated: 2025/08/21 19:17:40 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
		  return (write(1, "Error\nNumber of wrong arguments\n", 32), 0);
    t_data *data;
    data = malloc(sizeof(t_data));
    data->feature = malloc(sizeof(t_feature));
    data->player = malloc(sizeof(t_player));
    if (!check_map(av, data))
		  return (free_data(data), 1);
    free_data(data);
    return(0);    
}