/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:40 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:14:00 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "matrix.h"
# include "../parsing/scene.h"

typedef struct s_ray
{
	t_v3	origin;
	t_v3	direction;
}				t_ray;

t_ray		create_ray(t_v3 origin, t_v3 direction);
t_camera	pick_camera(t_scene *scene);
t_v3		get_direction(int x, int y, t_scene *scene, t_camera camera);
t_ray		ray_to_pixel(int x, int y, t_scene *scene);

#endif
