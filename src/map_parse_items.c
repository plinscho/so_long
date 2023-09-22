/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:21:21 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/22 17:02:50 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_get_items(char **map, t_game *game);
void	map_inv_chars(char **map);

int	check_items(t_game *game)
{
	map_inv_chars(game->map);
	map_get_items(game->map, game);
	map_find_path(game);
	return (0);
}

int	valid_chars(int c)
{
	if (c == 'C' || c == 'P' || c == 'E' || c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	map_inv_chars(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (!(valid_chars(map[i][j])))
				error_exit(map, ITEM_INV, "Error\nInvalid item found\n");
			j++;
		}
		i++;
	}
}

void	add_player(t_game *game, int i, int j)
{
	game->player += 1;
	game->p_row = i;
	game->p_col = j;
}

void	map_get_items(char **map, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->coin += 1;
			else if (map[i][j] == 'P')
				add_player(game, i, j);
			else if (map[i][j] == 'E')
				game->exit += 1;
			j++;
		}
		i++;
	}
	if (game->exit != 1)
		error_exit(map, ITEM_EXIT, "Error\nNo exit. | Too many exits.\n");
	if (game->player != 1)
		error_exit(map, ITEM_PLAYER, "Player not found | player > 1.\n");
}
