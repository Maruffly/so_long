/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:44:30 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/11 17:07:43 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>
#include <stdlib.h>

void	display_title(const char *filename, t_game *game)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_free(RED "Error opening title" RESET, game);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_printf(CYAN "%s" RESET, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		close(fd);
		error_free(RED "Error reading title" RESET, game);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_game	*game;

	(void)ac;
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->is_allocated = false;
	display_title("title.txt", game);
	check_arg(ac, av, game);
	init_map(game, av);
	init_vars(game);
	map_checker(game);
	find_player_pos(game);
	check_access(game);
	parameter_checker(game);
	init_mlx(game);
	init_sprites(game);
	print_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, keyboard_handler, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, close_game, game);
	mlx_hook(game->win, Expose, ExposureMask, print_map, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
