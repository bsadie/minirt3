/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:33:05 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:22:01 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/light/color.h"

t_color	int_to_color(int color)
{
	t_int_color	a;
	t_color		rtn;

	a.integer = color;
	rtn.red = a.comps[2];
	rtn.green = a.comps[1];
	rtn.blue = a.comps[0];
	return (rtn);
}

int	color_to_int(t_color color)
{
	t_int_color	a;

	a.comps[2] = color.red;
	a.comps[1] = color.green;
	a.comps[0] = color.blue;
	return (a.integer);
}
