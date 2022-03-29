/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:08:04 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:16:40 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parse_objects.h"

void	parse_sphere(t_scene *scene, char **splitted_line)
{
	t_object	*object;
	t_sphere	*sphere;

	if (array_len(splitted_line) != 4)
		put_error_exit("Input: wrong sphere");
	object = malloc(sizeof(t_object));
	check_malloc(object);
	sphere = malloc(sizeof(t_sphere));
	check_malloc(sphere);
	parse_coords(&sphere->center, splitted_line[1]);
	sphere->radius = ft_atod(splitted_line[2]) / 2;
	parse_color2(&object->color, splitted_line[3]);
	object->type = SPHERE;
	object->ptr = sphere;
	ft_list_add_back(&scene->objects, ft_list_new(object));
}

void	parse_plane(t_scene *scene, char **splitted_line)
{
	t_object	*object;
	t_plane		*plane;

	if (array_len(splitted_line) != 4)
		put_error_exit("Input: wrong plane");
	object = malloc(sizeof(t_object));
	check_malloc(object);
	plane = malloc(sizeof(t_plane));
	check_malloc(plane);
	parse_coords(&plane->p0, splitted_line[1]);
	parse_coords(&plane->normal, splitted_line[2]);
	normalize_vector(&plane->normal);
	parse_color2(&object->color, splitted_line[3]);
	object->type = PLANE;
	object->ptr = plane;
	ft_list_add_back(&scene->objects, ft_list_new(object));
}

void	parse_cylinder(t_scene *scene, char **splitted_line)
{
	t_object	*object;
	t_cylinder	*cylinder;

	if (array_len(splitted_line) != 6)
		put_error_exit("Input: wrong cylinder");
	object = malloc(sizeof(t_object));
	check_malloc(object);
	cylinder = malloc(sizeof(t_cylinder));
	check_malloc(cylinder);
	parse_coords(&cylinder->p, splitted_line[1]);
	parse_coords(&cylinder->normal, splitted_line[2]);
	normalize_vector(&cylinder->normal);
	cylinder->radius = ft_atod(splitted_line[3]) / 2;
	cylinder->height = ft_atod(splitted_line[4]);
	parse_color2(&object->color, splitted_line[5]);
	object->type = CYLINDER;
	object->ptr = cylinder;
	ft_list_add_back(&scene->objects, ft_list_new(object));
}
