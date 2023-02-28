/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:10:57 by saltinba          #+#    #+#             */
/*   Updated: 2023/02/27 13:10:58 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player_right, width * 50, height * 50);
	game->y_axis = height;
	game->x_axis = width;
}
void	place_player_render(t_complete *game, int height, int width, int command)
{
	if (command == 2)
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player_right, width * 50, height * 50);
	}
	if (command == 0)
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player_left, width * 50, height * 50);
	}
	if (command == 1)
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player_down, width * 50, height * 50);
	}
	if (command == 13)
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player_up, width * 50, height * 50);
	}
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 50, height * 50);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &i, &j);
	game->player_right = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player_right.xpm", &i, &j);
	game->player_left = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player_left.xpm", &i, &j);
	game->player_up = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player_up.xpm", &i, &j);
	game->player_down = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player_down.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &i, &j);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, width * 50, height * 50);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 50, height * 50);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 50, height * 50);
			width++;
		}
		height++;
	}
}
void	adding_in_graphics_render(t_complete *game, int command)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, width * 50, height * 50);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player_render(game, height, width, command);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 50, height * 50);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 50, height * 50);
			width++;
		}
		height++;
	}
}
