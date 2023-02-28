/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:21:58 by saltinba          #+#    #+#             */
/*   Updated: 2023/02/27 12:21:59 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	end;
	int	start;

	end = game->widthmap;
	start = 0;
	while (start < end)
	{
		if (!(game->map[0][start] == '1' && game->map[game->heightmap - 1][start] == '1'))
			return (0);
		start++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	check_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nDuvarlar sağlam değil.\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nHaritada bir şeyler eksik.%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->collectablescount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectablescount > 1
			&& game->exitcount == 1))
	{
		printf("\nHATA\nOyuncu sayısı, toplanabilir sayısı veya çıkış sayısında bir hata var.\n");
		exit_point(game);
	}
}
void	check_item(t_complete *game)
{
	int	warning;

	warning = 0;
	if (!(game->playercount == 1))
	{
		printf("\n HATA : Oyuncu Sayısı 1 olmalıdır. \n");
		warning = 1;
	}
	if (game->collectablescount <= 1)
	{
		printf("\n HATA : Toplanabilir sayısı 1 veya daha fazla olmalıdır. \n");
		warning = 1;
	}
	if (!(game->exitcount == 1))
	{
		printf("\n HATA : Çıkış Sayısı 1 olmalıdır. \n");
		warning = 1;
	}
	if (warning == 1)
		exit_point(game);
}

void	check_errors(t_complete *game)
{
	check_walls(game);
	character_valid(game);
}
