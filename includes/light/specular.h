/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:59:58 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:16:21 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECULAR_H
# define SPECULAR_H

# include "../parsing/scene.h"
# include "../geometry/ray.h"

typedef struct s_inter
{
	t_v3		hit_point;
	t_v3		hit_normal;
	t_list		*objects;
	t_object	*closest_object;
	t_ray		sent;
}				t_inter;

double			spec_coeff(t_light light, t_inter inter);
t_color2		specular(t_light light, t_inter inter);

#endif
