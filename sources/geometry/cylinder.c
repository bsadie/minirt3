/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:31:55 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:15:00 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/cylinder.h"

t_cylinder	*new_cylinder(t_v3 p, t_v3 normal, double radius, double height)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	check_malloc(cylinder);
	cylinder->p = p;
	cylinder->normal = normal;
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}

t_v3	get_cylinder_normal(t_v3 point, t_cylinder cylinder)
{
	t_v3	ctp;
	t_v3	normal;

	ctp = substract(point, cylinder.p);
	normal = substract(ctp, \
						v3_multiply(cylinder.normal, \
									dot_product(cylinder.normal, ctp)));
	normalize_vector(&normal);
	return (normal);
}

void	check_t(double *t, t_cylinder cylinder, t_ray ray)
{
	t_v3	q;
	t_v3	p2;

	p2 = v3_add(cylinder.p, v3_multiply(cylinder.normal, cylinder.height));
	q = v3_add(ray.origin, v3_multiply(ray.direction, *t));
	if (dot_product(cylinder.normal, substract(q, cylinder.p)) <= 0)
		*t = -1;
	if (dot_product(cylinder.normal, substract(q, p2)) >= 0)
		*t = -1;
}

int	cyl_get_roots(double *t0, double *t1, t_cylinder cylinder, t_ray ray)
{
	t_v3	a_sqrt;
	t_v3	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = substract(ray.direction, \
						v3_multiply(cylinder.normal, \
								dot_product(ray.direction, cylinder.normal)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.p), \
						v3_multiply(cylinder.normal, \
								dot_product(substract(ray.origin, cylinder.p), \
													cylinder.normal)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - cylinder.radius * cylinder.radius;
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}

int	intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t)
{
	double	t0;
	double	t1;

	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			*t = t1;
	else
			*t = t0;
	else
	{
		if (t0 > 0)
			*t = t0;
		else
			*t = t1;
	}
	return (1);
}
