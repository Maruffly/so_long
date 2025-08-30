/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:51:11 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 13:21:13 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_arg(int ac, char **av, t_game *game)
{
	int	len_map_name;

	if (ac > 2)
		error_free(RED "Too many arguments !" RESET, game);
	if (ac < 2)
		error_free(RED "The map is missing !" RESET, game);
	len_map_name = ft_strlen(av[1]);
	if (len_map_name < 4
		|| ft_strncmp(&av[1][len_map_name - 4], ".ber", 4) != 0)
		error_free(RED "Invalid map name or extension !" RESET, game);
}

int	keyboard_handler(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == KEY_UP)
		player_moves(game, game->map.player.x, game->map.player.y - 1, UP);
	if (keysym == KEY_S || keysym == KEY_DOWN)
		player_moves(game, game->map.player.x, game->map.player.y + 1, DOWN);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		player_moves(game, game->map.player.x - 1, game->map.player.y, LEFT);
	if (keysym == KEY_D || keysym == KEY_RIGHT)
		player_moves(game, game->map.player.x + 1, game->map.player.y, RIGHT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_game(game);
	return (0);
}
