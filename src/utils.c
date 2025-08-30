/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:48:02 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 14:07:41 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_position	find_player_pos(t_game	*game)
{
	int	i;
	int	j;

	game->map.player.x = -1;
	game->map.player.y = -1;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full_map[i][j] == 'P')
			{
				game->map.player.x = j;
				game->map.player.y = i;
				return (game->map.player);
			}
			j++;
		}
		i++;
	}
	return (game->map.player);
}

char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = malloc(sizeof(char) * (game->map.columns + 1));
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			return (free(map_copy), NULL);
		}
		ft_strlcpy(map_copy[i], game->map.full_map[i], game->map.columns + 1);
		map_copy[i][game->map.columns] = '\0';
		i++;
	}
	map_copy[game->map.rows] = NULL ;
	return (map_copy);
}

void	print_sprite(t_game *game, t_image sprite, int column, int line)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm, \
	column * sprite.y, line * sprite.x);
}
