/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:53:43 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 11:57:08 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_vars(t_game *game)
{
	game->map.players = 0;
	game->map.shrooms = 0;
	game->moves = 0;
	game->map.exit = 0;
	game->moves = 0;
	game->player_sprite = RIGHT;
	game->map.player.x = -1;
	game->map.player.y = -1;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game->mlx);
		error_free("MLX pointer failure !", game);
	}
	game->win = mlx_new_window(game->mlx, game->map.columns * WIDTH, \
	game->map.rows * HEIGHT, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		error_free("Windows failure !", game);
	}
}

t_image	create_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm)
		error_free("Sprite failure !", game);
	return (sprite);
}

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->wall = create_sprite(mlx, ASSET_WALL, game);
	game->floor = create_sprite(mlx, ASSET_FLOOR, game);
	game->smurf_up = create_sprite(mlx, ASSET_PLAYER_UP, game);
	game->smurf_down = create_sprite(mlx, ASSET_PLAYER_DOWN, game);
	game->smurf_left = create_sprite(mlx, ASSET_PLAYER_LEFT, game);
	game->smurf_right = create_sprite(mlx, ASSET_PLAYER_RIGHT, game);
	game->shrooms = create_sprite(mlx, ASSET_SHROOMS, game);
	game->exit = create_sprite(mlx, ASSET_EXIT, game);
	game->thru_exit = create_sprite(mlx, ASSET_THRU_EXIT, game);
}
