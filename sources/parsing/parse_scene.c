/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:50 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:24:38 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parse_scene.h"

void	parse_ambient(t_scene *scene, char **splitted_line)
{
	if (scene->ambient_color.red != -1)
		put_error_exit("Input: double \"A\" initialization");
	if (array_len(splitted_line) != 3)
		put_error_exit("Input: wrong A line");
	scene->ambient_intensity = ft_atod(splitted_line[1]);
	if (scene->ambient_intensity > 1 || scene->ambient_intensity < 0)
		put_error_exit("Input: wrong A line");
	parse_color2(&scene->ambient_color, splitted_line[2]);
	if (!check_color2(scene->ambient_color))
		put_error_exit("Input: wrong A line");
}

void	parse_camera(t_scene *scene, char **splitted_line)
{
	if (scene->camera.fov != -1)
		put_error_exit("Input: double \"C\" initialization");
	if (array_len(splitted_line) != 4)
		put_error_exit("Input: wrong \"C\" line");
	parse_coords(&scene->camera.origin, splitted_line[1]);
	parse_coords(&scene->camera.direction, splitted_line[2]);
	normalize_vector(&scene->camera.direction);
	scene->camera.fov = ft_atoi(splitted_line[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		put_error_exit("Input: wrong \"C\" line");
}

void	parse_light(t_scene *scene, char **splitted_line)
{
	if (scene->light.intensity != -1)
		put_error_exit("Input: double \"L\" initialization");
	if (array_len(splitted_line) > 4 || array_len(splitted_line) < 3)
		put_error_exit("Input: wrong \"L\" line1");
	parse_coords(&scene->light.p0, splitted_line[1]);
	scene->light.intensity = ft_atod(splitted_line[2]);
	if (array_len(splitted_line) == 4)
		parse_color2(&scene->light.color, splitted_line[3]);
	else
		parse_color2(&scene->light.color, "255,255,255");
	if (!check_color2(scene->light.color))
		put_error_exit("Input: wrong \"L\" line2");
}
