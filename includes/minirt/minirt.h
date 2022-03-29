/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:43:49 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 18:15:50 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include "../../mlx.h"
# include "../parsing/scene.h"
# include "../utils/list.h"
# include "../geometry/ray.h"
# include "../geometry/sphere.h"
# include "../geometry/plane.h"
# include "../geometry/cylinder.h"
# include "../geometry/quadratic.h"
# include "../geometry/matrix.h"
# include "../light/color2.h"
# include "../light/shading.h"
# include "../parsing/parser.h"
# include "../utils/free.h"

typedef struct s_image
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}				t_image;

typedef struct s_info
{
	void		*id;
	void		*window;
	t_scene		*scene;
	t_image		image;
}				t_info;

void	minirt(char *filename);
void	render(t_info *info);
int		w_close(t_info *info);
void	send_rays(t_info *info);

#endif
