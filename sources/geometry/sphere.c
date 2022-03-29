/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:22:08 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:15:52 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/sphere.h"

t_sphere	*new_sphere(t_v3 center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	check_malloc(sphere);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

t_v3	get_sphere_normal(t_v3 point, t_sphere sphere)
{
	t_v3	rtn;

	rtn = substract(point, sphere.center);
	normalize_vector(&rtn);
	return (rtn);
}

int	get_roots(double *t0, double *t1, t_ray ray, t_sphere sphere)
{
	t_v3	l;
	double	a;
	double	b;
	double	c;

	l = substract(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2.0 * dot_product(ray.direction, l);
	c = dot_product(l, l) - sphere.radius * sphere.radius;
	if (solve_quadratic(new_qparams(a, b, c), t0, t1) == 0)
		return (0);
	return (1);
}

int	intersect_sphere(t_ray ray, t_sphere sphere, double *t)
{
	double	t0;
	double	t1;

	if (get_roots(&t0, &t1, ray, sphere) == 0)
		return (0);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}
