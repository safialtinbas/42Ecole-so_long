/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:59:27 by saltinba          #+#    #+#             */
/*   Updated: 2023/02/27 12:59:28 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"
#include "../minilibx/mlx.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 50),
			(game.heightmap * 50), "Noxramma");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}


