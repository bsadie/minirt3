/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:45:15 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:16:06 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_UTILS_H
# define SHADING_UTILS_H

# include "color3.h"
# include "specular.h"
# include "../geometry/v3_operations.h"
# include "../geometry/ray.h"
# include "../geometry/sphere.h"
# include "../geometry/plane.h"
# include "../geometry/cylinder.h"
# include "../geometry/intersect.h"

t_v3		get_normal(t_v3 point, t_object *object);
t_color2	mix_colors(t_light light, double coeff, t_inter inter);
t_inter		new_inter(t_v3 hit_point, t_v3 hit_normal, \
									t_object *closest_object, t_ray sent);

#endif
