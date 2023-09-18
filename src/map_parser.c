/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:12:43 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/16 16:45:52 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_parse(t_game *game);
void	map_check(int fd, t_game *game);;

void	game_init(t_game *game)
{
	game->h = 0;
	game->w = 0;
	game->coin = 0;
	game->exit = 0;
	game->wall = 0;
	game->mov = 1;
	game->wh = 0;
	game->wh = 0;
	game->p_col = 0;
	game->p_row = 0;
	game->cols = 0;
	game->rows = 0;
	game->player = 0;
}

void	map_check(int fd, t_game *game)
{
	char	*line;
	char	*all_lines;
	char	*tmp;

	line = ft_strdup("");
	all_lines = ft_strdup("");
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break;		
		if (line && line[0] == '\n')
			error_nl(line);
		tmp = all_lines;
		all_lines = ft_strjoin(tmp, line);
		free(tmp);
	}
	if (all_lines[0] == '\0')
		error_nl(line);
	game->map = ft_split(all_lines, '\n');
	game->map_copy = ft_split(all_lines, '\n');
	free(all_lines);
}

void	map_parse(t_game *game)
{
	if (check_rec(game))
		error_exit(game->map, NOT_RECT, "Error\nMap is not consistent!\n");
	if (check_walls(game) || check_side_walls(game))
		error_exit(game->map, NOT_WALLS, "Error\nMap has wall issues!\n");
	if (check_items(game))
		error_exit(game->map, ITEM_ERR, "Error\nItem not expected.");
	ft_printf("Map parsed succesfully\n");
}

void	start_parse(char **argv, t_game *game)
{
	char	*map;
	int		m_len;
	int		fd;

	map = argv[1];
	m_len = ft_strlen(map);
	if (!(map[m_len - 1] == 'r' && map[m_len - 2] == 'e' && map[m_len -3] == 'b'
			&& map[m_len - 4] == '.'))
	{
		ft_printf("Error\nExtension of map is not .ber!\n");
		free(game);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	ft_printf("Map loaded succesfully!\n");
	map_check(fd, game);
	close(fd);	
	map_parse(game);
}

