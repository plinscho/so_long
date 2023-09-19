/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:04:50 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/19 16:28:36 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void	game_start(t_game *game);

int main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc == 2)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
			exit (1);
		game_init(game);
		start_parse(argv, game);
//		Untill here all good
		game_start(game);
		return (0);
	}
	else 
		ft_printf("Error\nNo map was provided!\n");

	return (0);
}

void	game_start(t_game *game)
{
	game->mlx = mlx_init();
	get_dimensions(game);
	game->mlx_w = mlx_new_window(game->mlx,game->ww * 32, game->wh * 32,"so_long");
	image_loader(game);
	draw_map(game);
	mlx_loop(game->mlx);
}
