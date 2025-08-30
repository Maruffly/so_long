/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:05:55 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 13:38:13 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_moves(t_game *game, int cur_x, int cur_y, int player_sprite)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	game->player_sprite = player_sprite;
	if (game->map.full_map[cur_y][cur_x] == WALL)
		return ;
	++game->moves;
	game->map.player.x = cur_x;
	game->map.player.y = cur_y;
	if (game->map.full_map[last_y][last_x] != MAP_EXIT)
		game->map.full_map[last_y][last_x] = FLOOR;
	if (game->map.full_map[cur_y][cur_x] == SHROOMS)
	{
		game->map.shrooms--;
		game->map.full_map[cur_y][cur_x] = FLOOR;
	}
	if (game->map.full_map[cur_y][cur_x] != MAP_EXIT)
		game->map.full_map[cur_y][cur_x] = PLAYER;
	if (game->map.full_map[cur_y][cur_x] == MAP_EXIT
		&& game->map.shrooms == 0)
		level_completed(game);
	else
		print_map(game);
}

void	print_player(t_game *game, int x, int y)
{
	if (game->map.full_map[y][x] == MAP_EXIT)
		print_sprite(game, game->thru_exit, x, y);
	else
	{
		if (game->player_sprite == UP)
			print_sprite(game, game->smurf_up, x, y);
		else if (game->player_sprite == DOWN)
			print_sprite(game, game->smurf_down, x, y);
		else if (game->player_sprite == LEFT)
			print_sprite(game, game->smurf_left, x, y);
		else if (game->player_sprite == RIGHT)
			print_sprite(game, game->smurf_right, x, y);
	}
}

void	check_sprite(t_game *game, int x, int y)
{
	char	parameter;

	parameter = game->map.full_map[y][x];
	if (parameter == WALL)
		print_sprite(game, game->wall, x, y);
	else if (parameter == FLOOR)
		print_sprite(game, game->floor, x, y);
	else if (parameter == SHROOMS)
		print_sprite(game, game->shrooms, x, y);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.player.x == x && game->map.player.y == y)
			print_sprite(game, game->thru_exit, x, y);
		else
			print_sprite(game, game->exit, x, y);
	}
	else if (parameter == PLAYER)
		print_player(game, x, y);
}

void	print_counters(t_game *game)
{
	char	*moves;
	char	*shrooms;
	char	*moves_count;
	char	*shrooms_count;
	char	*comb_string;

	moves = ft_itoa(game->moves);
	shrooms = ft_itoa(game->map.shrooms);
	moves_count = ft_strjoin("Movements : ", moves);
	shrooms_count = ft_strjoin("    Mushrooms left : ", shrooms);
	comb_string = ft_strjoin(moves_count, shrooms_count);
	mlx_string_put(game->mlx, game->win, 40, 20, 99999, comb_string);
	free(moves);
	free(moves_count);
	free(shrooms);
	free(shrooms_count);
	free(comb_string);
}

int	print_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.columns)
	{
		y = 0;
		while (y < game->map.rows)
		{
			check_sprite(game, x, y);
			y++;
		}
		x++;
	}
	print_counters(game);
	return (0);
}
