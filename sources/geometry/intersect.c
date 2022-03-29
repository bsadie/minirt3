/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:31:57 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:02:18 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/intersect.h"

int	intersect(t_ray sent, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (intersect_sphere(sent, *(t_sphere *)object->ptr, t));
	else if (object->type == PLANE)
		return (intersect_plane(sent, *(t_plane *)object->ptr, t));
	else
		return (intersect_cylinder(sent, *(t_cylinder *)object->ptr, t));
}

int	intersect_with_all(t_list *objects, t_ray sent, t_object **closest_object, \
						double *t_min)
{
	t_list		*iter;
	t_object	*this_object;
	double		t;

	*closest_object = NULL;
	iter = objects;
	*t_min = HUGE_VALF;
	while (iter != NULL)
	{
		this_object = iter->data;
		if (intersect(sent, this_object, &t))
		{
			if (t < *t_min)
			{
				*closest_object = this_object;
				*t_min = t;
			}
		}
		iter = iter->next;
	}
	if (*closest_object != NULL)
		return (1);
	else
		return (0);
}
