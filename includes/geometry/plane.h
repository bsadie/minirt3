/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:12:22 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:12:36 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "v3.h"
# include "ray.h"
# include <stdlib.h>
# include "../utils/free.h"

typedef struct s_plane
{
	t_v3	p0;
	t_v3	normal;
}				t_plane;

t_plane	*new_plane(t_v3 p0, t_v3 normal);
t_v3	get_plane_normal(t_plane plane);
int		intersect_plane(t_ray ray, t_plane plane, double *t);

#endif
