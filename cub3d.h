/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:56:14 by skaynar           #+#    #+#             */
/*   Updated: 2025/08/19 15:42:35 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>      // open
#include <stdio.h>      // printf, perror
#include <string.h>     // strerror
#include <sys/time.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line.h"

typedef struct s_player
{
    double	posX; //oyuncunun map üzerindeki x konumu
	double	posY; //oyuncunun map üzerindeki y konumu
	double	dirX; //oyuncunun baktığı x 
	double	dirY; //oyuncunun baktığı y
	char	start_pos; // N-S-E-W oyuncunun hangi yöne bakarak başladığı
	double	fov;
	double	planeX; //oyuncunun sağa ve sola bakabilmesi için dirx ve dir y ye dik bir vektör
	double	planeY;
	double rayDirX; //ışın ın yönü
	double rayDirY;
	int mapX;
	int mapY;
	double deltaDistX;
	double deltaDistY;
	int stepX;
	int stepY;
	double sideDistX;
	double sideDistY;
	int hit;
	int side;
}	t_player;

typedef struct s_map
{
	char *map_line;
	int num;
	struct s_map *next;	
}	t_map;

typedef struct s_feature
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
    
}   t_feature;

typedef struct s_data
{
    t_feature *feature;
	t_player *player;
	t_map *map;
	int line_num;
	void	*mlx;
    void	*win;
    bool    empty;
}	t_data;

int is_true_map(char *map, t_data *data);
int	jumper(char c);
int	check_map_name(char *str);
int check_map(char **av, t_data *data);
t_map	*ft_mapnew(void *content, int line_num);
void    map_add_back(t_map **lst, t_map *new);
int is_exe(char *str);
int	rgb_atoi(const char *str);
int is_truedigit(char *str);
#endif