/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:05:21 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/16 16:45:32 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
	# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

enum{
	NOT_RECT,
	NOT_WALLS,
	ITEM_ERR,
	ITEM_PLAYER,
	ITEM_EXIT,
	ITEM_INV,
	NICE,	
};

typedef struct s_point
{
	int	x;
	int	y;	
}t_point;

typedef struct s_image
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_w;
	void	*bg;
	t_img	*img;
	char	**map;
	char	**map_copy;
	int		coin;
	int		p_col;
	int		p_row;
	int		mov;
	int		wall;
	int		exit;
	int		cols;
	int		rows;
	int		player;
	int		w;
	int		h;
	int		wh;
	int		ww;
	
}t_game;

//	T_GAME.C
void	map_check(int fd, t_game *game);
void	draw_map(t_game *game);
void	print_map(char **map);
void	get_dimensions(t_game *game);

void	image_loader(t_game *game);

void	game_init(t_game *game);
void	start_parse(char **argv, t_game *game);
void	game_start(t_game *game);

//	ERRORS.C
void	error_nl(char *line);
void	error_exit(char **map, int error_enum, char *err_msg);
void	free_map(char **map);

//	MAP_PARSE.C
void	map_parse(t_game *game);
int		check_walls(t_game *game);
int		check_side_walls(t_game *game);
int		check_rec(t_game *game);
int		check_items(t_game *game);
void	map_find_path(t_game *game);


#endif