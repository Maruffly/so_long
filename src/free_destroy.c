/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:04 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/04 14:02:47 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
		free(game->map.full_map[string++]);
	free(game->map.full_map);
}

void	destroy_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm);
	mlx_destroy_image(game->mlx, game->floor.xpm);
	mlx_destroy_image(game->mlx, game->shrooms.xpm);
	mlx_destroy_image(game->mlx, game->smurf_down.xpm);
	mlx_destroy_image(game->mlx, game->smurf_up.xpm);
	mlx_destroy_image(game->mlx, game->smurf_right.xpm);
	mlx_destroy_image(game->mlx, game->smurf_left.xpm);
	mlx_destroy_image(game->mlx, game->thru_exit.xpm);
	mlx_destroy_image(game->mlx, game->exit.xpm);
}

void	free_all(t_game *game)
{
	destroy_all(game);
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	error_free(char *message, t_game *game)
{
	if (game->is_allocated)
		free_map(game);
	free(game);
	ft_printf("Error\n %s\n", message);
	exit (EXIT_FAILURE);
}

void	free_map_dup(t_game *game, char **map_dup)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
}
