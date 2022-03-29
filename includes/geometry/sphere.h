/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:08:23 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:12:43 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "v3.h"
# include "ray.h"
# include "quadratic.h"
# include "v3_operations.h"
# include <stdlib.h>
# include "../utils/free.h"

typedef struct s_sphere
{
	t_v3	center;
	double	radius;
}				t_sphere;

t_sphere	*new_sphere(t_v3 center, double radius);
t_v3		get_sphere_normal(t_v3 point, t_sphere sphere);
int			get_roots(double *t0, double *t1, t_ray ray, t_sphere sphere);
int			intersect_sphere(t_ray ray, t_sphere sphere, double *t);

#endif
