/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:18:59 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/20 17:25:53 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//	falta hacer el final del videojuego
void	game_finish(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->coin == 0)
		destroy_game(game);
}