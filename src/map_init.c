/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:41 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 11:23:02 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_line(char *map, t_game *game)
{
	int	i;

	if (!map || map[0] == '\n')
	{
		free(map);
		error_free(RED "Invalid map ! Empty line at the begenning \
or empty map." RESET, game);
	}
	if (ft_strlen(map) > 0 && map[ft_strlen(map)] == '\n')
	{
		free(map);
		error_free(RED "Invalid map ! Empty line at the end." RESET, game);
	}
	i = 0;
	while (map[i] && map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_free(RED "Invalid map ! Empty line in the map" RESET, game);
		}
		i++;
	}
}

static char	*build_map(t_game *game, char *filename)
{
	char	*map_buffer;
	char	*next_line;
	int		map_fd;
	char	*tmp;

	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		error_free(RED "Map couldn't be opened !" RESET, game);
	map_buffer = ft_strdup("");
	game->map.rows = 0;
	next_line = get_next_line(map_fd);
	while (next_line != NULL)
	{
		tmp = ft_strjoin(map_buffer, next_line);
		free(map_buffer);
		map_buffer = tmp;
		free(next_line);
		next_line = get_next_line(map_fd);
		game->map.rows++;
	}
	close(map_fd);
	return (map_buffer);
}

void	init_map(t_game *game, char **av)
{
	char	*map_buffer;
	int		i;

	map_buffer = build_map(game, av[1]);
	i = 0;
	game->map.columns = 0;
	while (map_buffer[i] && map_buffer[i++] != '\n')
		game->map.columns++;
	check_line(map_buffer, game);
	game->map.full_map = ft_split(map_buffer, '\n');
	game->is_allocated = true;
	free(map_buffer);
}
