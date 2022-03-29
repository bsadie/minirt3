/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:19:04 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:15:37 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/plane.h"

t_plane	*new_plane(t_v3 p0, t_v3 normal)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	check_malloc(plane);
	plane->p0 = p0;
	plane->normal = normal;
	return (plane);
}

t_v3	get_plane_normal(t_plane plane)
{
	return (plane.normal);
}

int	intersect_plane(t_ray ray, t_plane plane, double *t)
{
	double	denom;
	t_v3	p0l0;

	denom = dot_product(plane.normal, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(plane.p0, ray.origin);
		*t = dot_product(p0l0, plane.normal) / denom;
		return (*t >= 0);
	}
	return (0);
}
