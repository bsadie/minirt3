/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:53:09 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:20:12 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../geometry/v3.h"
# include "../utils/list.h"
# include "../light/color2.h"

# define IMG_HEIGHT 600
# define IMG_WIDTH 800

typedef struct s_light
{
	t_v3		p0;
	double		intensity;
	t_color2	color;
}				t_light;

typedef struct s_camera
{
	t_v3	origin;
	t_v3	direction;
	int		fov;
}				t_camera;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}				t_otype;

typedef struct s_object
{
	t_otype		type;
	void		*ptr;
	t_color2	color;
	double		albedo;
}				t_object;

typedef struct s_scene
{
	int			width;
	int			height;
	t_light		light;
	t_camera	camera;
	t_color2	ambient_color;
	double		ambient_intensity;
	t_list		*objects;

}				t_scene;

#endif
