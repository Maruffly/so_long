/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:10:44 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 15:10:26 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	wall_checker(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full_map[0][i] != WALL)
			error_free(RED "Invalid map ! Wall missing \
in the first line.\n" RESET, game);
		else if (game->map.full_map[game->map.rows - 1][i] != WALL)
			error_free(RED "Invalid map ! Wall missing \
in the last line.\n" RESET, game);
		i++;
	}
}

static void	columns_checker(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full_map[i][0] != WALL)
			error_free(RED "Invalid map ! Wall missing \
in the first column.\n" RESET, game);
		if (game->map.rows == game->map.columns)
			error_free(RED"Invalid map! The map cannot be square."RESET, game);
		else if (game->map.full_map[i][game->map.columns - 1] != WALL)
			error_free(RED "Invalid map ! Wall missing \
in the last column.\n" RESET, game);
		i++;
	}
}

static void	count_parameter(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("01CEP", game->map.full_map[y][x]))
				error_free(RED"Invalid map ! Unexpected parameter."RESET, game);
			else if (game->map.full_map[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full_map[y][x] == SHROOMS)
				game->map.shrooms++;
			else if (game->map.full_map[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	parameter_checker(t_game *game)
{
	if (game->map.players != 1)
		error_free(RED "Number of player has to be 1 !" RESET, game);
	else if (game->map.exit == 0)
		error_free(RED "No exit in the map !" RESET, game);
	else if (game->map.exit > 1)
		error_free(RED "Number of exit has to be 1 !" RESET, game);
	else if (game->map.shrooms == 0)
		error_free(RED "No Shrooms in the map !" RESET, game);
	else if (!game->map.is_accessible)
		error_free(RED "Shrooms or Exit not accessible !" RESET, game);
}

void	map_checker(t_game *game)
{
	wall_checker(game);
	columns_checker(game);
	count_parameter(game);
}
