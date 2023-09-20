/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:32:47 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/20 16:25:00 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void get_initial_pos(t_game *game, t_point *player_pos);
void validate_map(t_game *game, t_point *player_pos);

int		move_valid(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (0);
	return (1);
}

void	map_find_path(t_game *game)
{
	t_point	*player_pos;
	
	player_pos = malloc(sizeof(t_point));
	player_pos->x = 0;
	player_pos->y = 0;
	get_initial_pos(game, player_pos);
	validate_map(game, player_pos);
	free(player_pos);
}

void get_initial_pos(t_game *game, t_point *player_pos) 
{
    int	i;
	int	j;

	i = 0;
    while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				player_pos->x = i;
				player_pos->y = j;
			}
			j++;
		}
		i++;
    }
}

void	check_path(t_game *game, int i, int j)
{
	while (game->map_copy[i][j] != '1' && game->map_copy[i][j] != 'X')
	{
		if (game->map_copy[i][j] == 'C')
			game->coin -= 1;
		else if (game->map_copy[i][j] == 'E')
			game->exit -= 1;
		game->map_copy[i][j] = 'X';
		check_path(game, i + 1, j);
		check_path(game, i - 1, j);
		check_path(game, i, j + 1);
		check_path(game, i , j - 1);
	}
}

void validate_map(t_game *game, t_point *player_pos) 
{
	int i;
	int j;
	int	tmp_coins;
	int	tmp_exits;
	
	tmp_coins = game->coin;
	tmp_exits = game->exit;
	i = player_pos->x;
	j = player_pos->y;
    check_path(game, i, j);
	if (game->coin > 0)
		error_exit(game->map_copy, ITEM_ERR, "Error\nNo path to coins.\n");
	if (game->exit > 0)
		error_exit(game->map_copy, ITEM_ERR, "Error\nNo path to exit.\n");
	game->coin = tmp_coins;
	game->exit = tmp_exits;
	free_map(game->map_copy);
}
