/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:37:45 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:12:02 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "ray.h"
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"

int	intersect(t_ray sent, t_object *object, double *t);
int	intersect_with_all(t_list *objects, t_ray sent, \
						t_object **closest_object, double *t_min);

#endif
