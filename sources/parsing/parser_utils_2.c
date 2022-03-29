/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:03:51 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 11:54:34 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parser_utils_2.h"

void	parse_coords(t_v3 *point, char *field)
{
	char	**coords;

	coords = ft_split(field, ',');
	if (array_len(coords) != 3)
		put_error_exit("Input: wrong coords");
	point->x = ft_atod(coords[0]);
	point->y = ft_atod(coords[1]);
	point->z = ft_atod(coords[2]);
	free(coords);
}

void	parse_color2(t_color2 *result, char *field)
{
	char	**color;

	color = ft_split(field, ',');
	if (array_len(color) != 3)
		put_error_exit("Input: wrong color");
	result->red = (double)ft_atoi(color[0]) / 256;
	result->green = (double)ft_atoi(color[1]) / 256;
	result->blue = (double)ft_atoi(color[2]) / 256;
	if (!check_color2(*result))
		put_error_exit("Input: wrong color");
	free(color);
}

int	check_color2(t_color2 color)
{
	if (color.red < 0 || color.red > 1
		|| color.green < 0 || color.green > 1
		|| color.blue < 0 || color.blue > 1)
		return (0);
	return (1);
}

void	check_scene(t_scene *scene)
{
	if (scene->camera.fov == 0)
		put_error_exit("Input: wrong camera");
	if (scene->ambient_color.red < 0 || scene->ambient_color.green < 0 \
	|| scene->ambient_color.blue < 0)
		put_error_exit("Input: wrong ambient");
}
