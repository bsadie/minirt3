/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:06:13 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:47:27 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/light/shading.h"

t_color2	light_contribution(t_light light, t_inter inter, t_scene scene)
{
	t_object	*closest_object2;
	double		t;
	t_v3		light_ray;
	t_ray		lray;
	double		coeff;

	coeff = 0;
	light_ray = substract(light.p0, inter.hit_point);
	normalize_vector(&light_ray);
	lray = create_ray(v3_add(inter.hit_point, \
								v3_multiply(inter.hit_normal, 0.1)), light_ray);
	if (!intersect_with_all(scene.objects, lray, &closest_object2, &t) \
					|| t > vector_len(substract(light.p0, inter.hit_point)))
	{
		coeff = fmax(0, dot_product(inter.hit_normal, light_ray));
	}
	return (mix_colors(light, coeff, inter));
}

t_color2	shade(t_scene *scene, t_ray sent, t_object *closest_object, \
																double t_min)
{
	t_v3		hit_point;
	t_v3		hit_normal;
	t_color2	result;
	t_color2	addition;

	result = int_color(0);
	hit_point = v3_add(sent.origin, v3_multiply(sent.direction, t_min));
	hit_normal = get_normal(hit_point, closest_object);
	if (dot_product(sent.direction, hit_normal) > 0)
		hit_normal = substract(create_v3(0, 0, 0), v3_multiply(hit_normal, 1));
	addition = light_contribution(scene->light, \
				new_inter(hit_point, hit_normal, closest_object, sent), \
				*scene);
	result = color2_add(result, addition);
	return (result);
}

int	get_color(t_scene *scene, t_ray sent)
{
	double		t_min;
	t_object	*closest_object;
	t_color2	result;
	t_color2	ambient_color;

	if (intersect_with_all(scene->objects, sent, &closest_object, &t_min))
	{
		ambient_color = color2_coeff(scene->ambient_color, \
									scene->ambient_intensity);
		result = color2_add(color2_mult(closest_object->color, ambient_color), \
									shade(scene, sent, closest_object, t_min));
		return (to_int(result));
	}
	else
		return (0);
}
