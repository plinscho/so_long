/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:58:44 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/22 16:59:07 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
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

void	draw_walls_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
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

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_w, \
					game->img[3].img_ptr, j * 32, i * 32);
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
