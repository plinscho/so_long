/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:51:46 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/22 18:20:01 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_free(char **map, char *err_msg);

int	destroy_game(t_game *game)
{
	ft_printf("Game Over\n");
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_w);
	// mlx_destroy(game->mlx);
	free(game);
	exit(2);
}

void	error_nl(char *line)
{
	if (line)
		free(line);
	ft_printf("Error\nMap contains \\n!\n");
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	error_exit(char **map, int error_enum, char *err_msg)
{
	if (error_enum == NOT_RECT)
		error_free(map, err_msg);
	else if (error_enum == NOT_WALLS)
		error_free(map, err_msg);
	else if (error_enum == ITEM_EXIT)
		error_free(map, err_msg);
	else if (error_enum == ITEM_PLAYER)
		error_free(map, err_msg);
	else if (error_enum == ITEM_INV)
		error_free(map, err_msg);
	else if (error_enum == ITEM_ERR)
		error_free(map, err_msg);
}

void	error_free(char **map, char *err_msg)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	ft_printf(err_msg);
	exit(EXIT_FAILURE);
}
