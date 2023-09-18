/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:04:50 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/16 17:08:40 by plinscho         ###   ########.fr       */
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
		game_start(game);
		return (0);
	}
	else 
		ft_printf("Error\nNo map was provided!\n");

	return (0);
}

void	game_start(t_game *game)
{
	get_dimensions(game);
	game->mlx = mlx_init();
	game->mlx_w = mlx_new_window(game->mlx,1000, 1000,"hhhh");
		//game->mlx, game->w*game->ww*32, game->h*game->wh*32, "help");
	image_loader(game);
	draw_map(game);

	
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
