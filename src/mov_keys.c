/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:35:52 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/20 18:32:36 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

int	mov_keys(int key, t_game *game)
{
	ft_printf("player at: %d, %d\n", game->p_row, game->p_col);
	if (key == ESC)
		destroy_game(game);
	if (key == W || key == ARROW_UP)
		move_up(game);
	else if (key == S || key == ARROW_DOWN)
		move_down(game);
	else if (key == A || key == ARROW_LEFT)
		move_left(game);
	else if (key == D || key == ARROW_RIGHT)
		move_right(game);
	return (0);
}

void	move_up(t_game *game)
{
	if (move_valid(game, game->p_row - 1, game->p_col))
	{
		if (game->map[game->p_row][game->p_col] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[2].img_ptr, game->p_col * 32, game->p_row * 32);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[1].img_ptr, game->p_col * 32, game->p_row * 32);
		game->p_row = game->p_row - 1;
		mlx_put_image_to_window(game->mlx, game->mlx_w, \
			game->img[3].img_ptr, game->p_col * 32, game->p_row * 32);
		game_finish(game, game->p_row, game->p_col);
		ft_printf("Moves: %d\n", game->mov);
		game->mov += 1;
	}	
}

void	move_down(t_game *game)
{
	if (move_valid(game, game->p_row + 1, game->p_col))
	{
		if (game->map[game->p_row][game->p_col] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[2].img_ptr, game->p_col * 32, game->p_row * 32);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[1].img_ptr, game->p_col * 32, game->p_row * 32);
		game->p_row = game->p_row + 1;
		mlx_put_image_to_window(game->mlx, game->mlx_w, \
			game->img[3].img_ptr, game->p_col * 32, game->p_row * 32);
		game_finish(game, game->p_row, game->p_col);
		ft_printf("Moves: %d\n", game->mov);
		game->mov += 1;
	}	
}

void	move_left(t_game *game)
{
	if (move_valid(game, game->p_row, game->p_col - 1))
	{
		if (game->map[game->p_row][game->p_col] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[2].img_ptr, game->p_col * 32, game->p_row * 32);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[1].img_ptr, game->p_col * 32, game->p_row * 32);
		game->p_col = game->p_col - 1;
		mlx_put_image_to_window(game->mlx, game->mlx_w, \
			game->img[3].img_ptr, game->p_col * 32, game->p_row * 32);
		game_finish(game, game->p_row, game->p_col);
		ft_printf("Moves: %d\n", game->mov);
		game->mov += 1;
	}	
}

void	move_right(t_game *game)
{
	if (move_valid(game, game->p_row, game->p_col + 1))
	{
		if (game->map[game->p_row][game->p_col] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[2].img_ptr, game->p_col * 32, game->p_row * 32);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_w, \
				game->img[1].img_ptr, game->p_col * 32, game->p_row * 32);
		game->p_col = game->p_col + 1;
		mlx_put_image_to_window(game->mlx, game->mlx_w, \
			game->img[3].img_ptr, game->p_col * 32, game->p_row * 32);
		game_finish(game, game->p_row, game->p_col);
		ft_printf("Moves: %d\n", game->mov);
		game->mov += 1;
	}	
}