/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:45:41 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/09 14:09:10 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define BUFFER_SIZE 1000

# define WIDTH		64
# define HEIGHT		64

# define WALL		'1'
# define FLOOR		'0'
# define SHROOMS	'C'
# define PLAYER		'P'
# define MAP_EXIT	'E'

# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

# define KEY_Q		113
# define KEY_ESC	65307

# define UP			1
# define DOWN		2
# define LEFT		3
# define RIGHT		4

# define ASSET_WALL				"assets/wall.xpm"
# define ASSET_FLOOR			"assets/floor.xpm"
# define ASSET_PLAYER_UP		"assets/smurf_up.xpm"
# define ASSET_PLAYER_DOWN		"assets/smurf_down.xpm"
# define ASSET_PLAYER_LEFT		"assets/smurf_left.xpm"
# define ASSET_PLAYER_RIGHT		"assets/smurf_right.xpm"
# define ASSET_SHROOMS			"assets/shrooms.xpm"
# define ASSET_EXIT				"assets/exit.xpm"
# define ASSET_THRU_EXIT		"assets/thru_exit.xpm"

typedef struct s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct s_image
{
	int		x;
	int		y;
	void	*xpm;
}				t_image;

typedef struct s_map
{
	bool		is_accessible;
	char		**full_map;
	char		**map_copy;
	int			rows;
	int			columns;
	int			shrooms;
	int			exit;
	int			players;
	t_position	shrooms_pos;
	t_position	player;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		moves;
	int		player_sprite;
	bool	is_allocated;
	t_map	map;
	t_image	wall;
	t_image	floor;
	t_image	smurf_up;
	t_image	smurf_down;
	t_image	smurf_left;
	t_image	smurf_right;
	t_image	shrooms;
	t_image	exit;
	t_image	thru_exit;
}				t_game;

// Free & error
int			error_free(char *message, t_game *game);
void		free_map_dup(t_game *game, char **map_dup);
void		free_all(t_game *game);

// Utils
t_position	find_collectible(t_game *game);
t_position	find_player_pos(t_game	*game);
char		**duplicate_map(t_game *game);

// Input Handler
void		check_arg(int ac, char **av, t_game *game);
int			keyboard_handler(int keysym, t_game *game);

// Print
void		print_player(t_game *game, int x, int y);
void		print_sprite(t_game *game, t_image sprite, int column, int line);
int			print_map(t_game *game);
void		player_moves(t_game *game, int cur_x, int cur_y, int player_sprite);

// Map parser
void		parameter_checker(t_game *game);
void		map_checker(t_game *game);
void		check_access(t_game *game);

// Init
void		init_mlx(t_game *game);
void		init_sprites(t_game *game);
void		init_map(t_game *game, char **av);
void		init_vars(t_game *game);

// Finish game
int			close_game(t_game *game);
int			level_completed(t_game *game);

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

#endif
