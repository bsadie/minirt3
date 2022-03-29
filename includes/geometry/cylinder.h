/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:14:19 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:14:16 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include <math.h>
# include <stdlib.h>
# include "v3.h"
# include "ray.h"
# include "v3_operations.h"
# include "quadratic.h"
# include "../utils/free.h"

typedef struct s_cylinder
{
	t_v3	p;
	t_v3	normal;
	double	radius;
	double	height;
}				t_cylinder;

t_cylinder	*new_cylinder(t_v3 p, t_v3 normal, double radius, double height);
t_v3		get_cylinder_normal(t_v3 point, t_cylinder cylinder);
void		check_t(double *t, t_cylinder cylinder, t_ray ray);
int			cyl_get_roots(double *t0, double *t1, \
							t_cylinder cylinder, t_ray ray);
int			intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t);

#endif
