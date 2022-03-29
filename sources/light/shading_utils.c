/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:44:13 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:46:49 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/light/shading_utils.h"

t_v3	get_normal(t_v3 point, t_object *object)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(point, *(t_sphere *)object->ptr));
	else if (object->type == PLANE)
		return (get_plane_normal(*(t_plane *)object->ptr));
	else
		return (get_cylinder_normal(point, *(t_cylinder *)object->ptr));
}

t_color2	mix_colors(t_light light, double coeff, t_inter inter)
{
	t_color2	rtn;
	t_color2	light_color;
	t_color2	object_color;

	light_color = color2_coeff(light.color, light.intensity);
	object_color = inter.closest_object->color;
	rtn = color2_coeff(color2_mult(light_color, object_color), coeff);
	if (coeff)
		rtn = color2_add(rtn, specular(light, inter));
	return (rtn);
}

t_inter	new_inter(t_v3 hit_point, t_v3 hit_normal, \
									t_object *closest_object, t_ray sent)
{
	t_inter	inter;

	inter.hit_point = hit_point;
	inter.hit_normal = hit_normal;
	inter.closest_object = closest_object;
	inter.sent = sent;
	return (inter);
}
