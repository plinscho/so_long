/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by plinscho          #+#    #+#             */
/*   Updated: 2023/09/18 19:07:43 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_walls_path(t_game *game)
{
	int	i;
	int	j;

	print_map(game->map);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		ft_printf("i: %d\n", i);
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[0].img_ptr, j * 32, i * 32);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'E' \
					|| game->map[i][j] == 'C' || game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[1].img_ptr, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_items(t_game *game)
{
	int	i;
	int	j;

	print_map(game->map);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		ft_printf("i: %d\n", i);
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[1].img_ptr, j * 32, i * 32);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[2].img_ptr, j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[4].img_ptr, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	ft_printf("Start drawing...\n");
	draw_walls_path(game);
	draw_items(game);
}