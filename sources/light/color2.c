/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:48:55 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:28:02 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/light/color2.h"

t_color2	color2_add(t_color2 a, t_color2 b)
{
	t_color2	rtn;

	rtn.red = fmin(a.red + b.red, 0.99);
	rtn.green = fmin(a.green + b.green, 0.99);
	rtn.blue = fmin(a.blue + b.blue, 0.99);
	return (rtn);
}

t_color2	color2_mult(t_color2 a, t_color2 b)
{
	t_color2	rtn;

	rtn.red = fmin(a.red * b.red, 1);
	rtn.green = fmin(a.green * b.green, 1);
	rtn.blue = fmin(a.blue * b. blue, 1);
	return (rtn);
}

t_color2	color2_coeff(t_color2 a, double coeff)
{
	t_color2	rtn;

	rtn.red = fmin(a.red * coeff, 1);
	rtn.green = fmin(a.green * coeff, 1);
	rtn.blue = fmin(a.blue * coeff, 1);
	return (rtn);
}

int	to_int(t_color2 a)
{
	int		rtn;
	t_color	tmp;

	tmp.red = a.red * 256;
	tmp.green = a.green * 256;
	tmp.blue = a.blue * 256;
	rtn = color_to_int(tmp);
	return (rtn);
}
