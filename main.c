/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:55:12 by skaynar           #+#    #+#             */
/*   Updated: 2025/08/21 20:11:20 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
		  return (write(1, "Error\nNumber of wrong arguments\n", 32), 0);
    t_data *data;
    data = ft_calloc(1,sizeof(t_data));
    data->feature = ft_calloc(1,sizeof(t_feature));
    data->player = ft_calloc(1,sizeof(t_player));
    if (!check_map(av, data))
		  return (free_data(data), 1);
    printf("aaa->%d\n",data->widht);
    free_data(data);
    return(0);    
}