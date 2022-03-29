/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:32 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:15:36 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR2_H
# define COLOR2_H

# include "color.h"

typedef struct s_color2
{
	float	red;
	float	green;
	float	blue;
}				t_color2;

t_color2	color2_add(t_color2 a, t_color2 b);
t_color2	color2_mult(t_color2 a, t_color2 b);
t_color2	color2_coeff(t_color2 a, double coeff);
int			to_int(t_color2 a);

#endif
