/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:36:33 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/13 16:08:20 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//	This code checks if the len of the first row is the same as all others.
//	Additionally from that, it saves the number of columns and rows.
//	if cols == rows means map is a square, therefore we exit.
int		check_rec(t_game *game)
{
	size_t	len;
	int		i;

	i = 0;
	while(game->map[i])
		i++;
	len = ft_strlen(game->map[0]);
	game->rows = i - 1;
	game->cols = (int)len - 1;
	
	i = 0;
	while(game->map[i])
	{
		if (!(len == ft_strlen(game->map[i])))
			return (1);
		i++;
	}
	
	return (0);
}

int		check_walls(t_game *game)
{
	int		i;

	i = -1;
	while (game->map[++i])
		ft_printf("%s\n", game->map[i]);
	i = 0;
//	check the 1st row to see if all elements are '1'
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
//	check last row to see if all are '1'
	while (game->map[game->rows][i])
	{
		if (game->map[game->rows][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		check_side_walls(t_game *game)
{
	int		i;
	char	**tmp_map;

	tmp_map = game->map;
	i = 0;
	while (tmp_map[i])
	{
		if (!(tmp_map[i][0] == '1' && tmp_map[i][game->cols] == '1'))
		{
			ft_printf("Error\nSide walls are not sealed!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
