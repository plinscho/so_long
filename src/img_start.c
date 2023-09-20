/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:51:56 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/20 17:34:25 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image_build(t_game *game);

void	get_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->wh = i;
	game->ww = ft_strlen(game->map[0]);
}

// 	this function loads the tiles into the program
void	image_loader(t_game *game)
{
	game->w = 32;
	game->h = 32;
	game->img = malloc(sizeof(t_img) * (5 + 1));
	if (!game->img)
		exit(1);
	game->img[0].img_ptr = mlx_xpm_file_to_image(game->mlx, 
		"tiles/wall.xpm", &game->w, &game->h);
	game->img[1].img_ptr = mlx_xpm_file_to_image(game->mlx, 
		"tiles/floor.xpm", &game->w, &game->h);
	game->img[2].img_ptr = mlx_xpm_file_to_image(game->mlx, 
		"tiles/exit.xpm", &game->w, &game->h);
	game->img[3].img_ptr = mlx_xpm_file_to_image(game->mlx, 
		"tiles/player.xpm", &game->w, &game->h);
	game->img[4].img_ptr = mlx_xpm_file_to_image(game->mlx, 
		"tiles/coin.xpm", &game->w, &game->h);
	image_build(game);
}

//	This function extracts the data from the image and puts in into the screen
static void	image_build(t_game *game)
{
	game->img[0].data = (int *)mlx_get_data_addr(game->img[0].img_ptr, 
		&game->img[0].bpp, &game->img[0].size_l, &game->img[0].endian);
	game->img[1].data = (int *)mlx_get_data_addr(game->img[1].img_ptr, 
		&game->img[1].bpp, &game->img[1].size_l, &game->img[1].endian);
	game->img[2].data = (int *)mlx_get_data_addr(game->img[2].img_ptr, 
		&game->img[2].bpp, &game->img[2].size_l, &game->img[2].endian);
	game->img[3].data = (int *)mlx_get_data_addr(game->img[3].img_ptr, 
		&game->img[3].bpp, &game->img[3].size_l, &game->img[3].endian);
	game->img[4].data = (int *)mlx_get_data_addr(game->img[4].img_ptr, 
		&game->img[4].bpp, &game->img[4].size_l, &game->img[4].endian);
	ft_printf("Images loaded!\n");
}
