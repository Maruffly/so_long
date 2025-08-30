/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:33:25 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 14:24:40 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill(char **map, t_game *game, t_position current)
{
	if (current.y < 0 || current.y >= game->map.rows
		|| current.x < 0 || current.x >= game->map.columns
		|| map[current.y][current.x] == '1' || map[current.y][current.x] == 'F')
		return ;
	map[current.y][current.x] = 'F';
	fill(map, game, (t_position){current.x - 1, current.y});
	fill(map, game, (t_position){current.x + 1, current.y});
	fill(map, game, (t_position){current.x, current.y - 1});
	fill(map, game, (t_position){current.x, current.y + 1});
}

static void	flood_fill(char **map, t_game *game, t_position initial)
{
	if (initial.x < 0 || initial.x >= game->map.columns
		|| initial.y < 0 || initial.y >= game->map.rows)
		return ;
	fill(map, game, initial);
}

static bool	check_map_access(t_game *game, char **map_copy)
{
	int		i;
	int		j;
	int		shrooms_found;
	bool	exit_accessible;

	exit_accessible = false;
	shrooms_found = 0;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full_map[i][j] == 'C' && map_copy[i][j] == 'F')
				shrooms_found++;
			else if (game->map.full_map[i][j] == 'E' && map_copy[i][j] == 'F')
				exit_accessible = true;
			j++;
		}
		i++;
	}
	if ((shrooms_found == game->map.shrooms) && exit_accessible)
		return (true);
	return (false);
}

void	check_access(t_game *game)
{
	char	**map_copy;

	map_copy = duplicate_map(game);
	if (!map_copy)
		error_free(RED "Failed to duplicate map" RESET, game);
	game->map.player = find_player_pos(game);
	if (game->map.player.x == -1 || game->map.player.y == -1)
		error_free(RED "Player position not set or invalid" RESET, game);
	flood_fill(map_copy, game, game->map.player);
	game->map.is_accessible = check_map_access(game, map_copy);
	free_map_dup(game, map_copy);
}
