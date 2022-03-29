/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:29:08 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 18:19:31 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt/minirt.h"

void	send_rays(t_info *info)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			color = get_color(info->scene, ray_to_pixel(x, y, info->scene));
			info->image.addr[y * info->scene->width + x] = color;
			x++;
		}
		y++;
	}
}

int	w_close(t_info *info)
{
	mlx_destroy_window(info->id, info->window);
	free_objects(info->scene);
	exit(0);
}

void	render(t_info *info)
{
	send_rays(info);
	mlx_put_image_to_window(info->id, info->window, info->image.img, 0, 0);
}

int	keys(int key, t_info *info)
{
	if (key == 53)
		w_close(info);
	return (0);
}

void	minirt(char *filename)
{
	t_info	info;

	info.scene = parse_file(filename);
	info.id = mlx_init();
	info.window = mlx_new_window(info.id, info.scene->width, \
								info.scene->height, \
								"miniRT");
	info.image.img = mlx_new_image(info.id, info.scene->width, \
											info.scene->height);
	info.image.addr = (int *)mlx_get_data_addr(info.image.img, \
												&info.image.bits_per_pixel, \
												&info.image.line_length, \
												&info.image.endian);
	mlx_hook(info.window, 17, 0, w_close, &info);
	mlx_key_hook(info.window, keys, &info);
	render(&info);
	mlx_loop(info.id);
}
