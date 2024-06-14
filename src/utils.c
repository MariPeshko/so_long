/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:28:10 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 18:14:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// destroy everything, except of images
void	cleanup_map_and_exit(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	while (data->assets->map_height--)
		free(data->assets->map[data->assets->map_height]);
	mlx_destroy_display(data->mlx);
	free(data->assets->map);
	free(data->assets->player_pos);
	free(data->assets);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

// Destroy images, destroy the window, free map lines,
// destroy display and exit the program
// mlx_destroy_image expects a fully initialized t_img structure
// Segfault on uninitialized structs t_img
int	cleanup_and_exit(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->assets->player.img);
	mlx_destroy_image(data->mlx, data->assets->coin.img);
	mlx_destroy_image(data->mlx, data->assets->wall.img);
	mlx_destroy_image(data->mlx, data->assets->door_closed.img);
	mlx_destroy_image(data->mlx, data->assets->door_open.img);
	mlx_destroy_image(data->mlx, data->assets->floor.img);
	mlx_destroy_window(data->mlx, data->win);
	while (data->assets->map_height--)
		free(data->assets->map[data->assets->map_height]);
	mlx_destroy_display(data->mlx);
	free(data->assets->map);
	free(data->assets->player_pos);
	free(data->assets);
	free(data->mlx);
	exit(0);
	return (0);
}

// cleanap temp int **passed
void	free_passed(int **passed, t_relement *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(passed[i]);
		i++;
	}
	free(passed);
}
