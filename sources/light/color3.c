/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:03 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/14 16:13:49 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/light/color3.h"

t_color2	int_color(int color)
{
	t_color		tmp;
	t_color2	rtn;

	tmp = int_to_color(color);
	rtn.red = (float)tmp.red / 256;
	rtn.green = (float)tmp.green / 256;
	rtn.blue = (float)tmp.blue / 256;
	return (rtn);
}

t_color2	from_color(t_color color)
{
	t_color2	rtn;

	rtn.red = color.red / 256;
	rtn.green = color.green / 256;
	rtn.blue = color.blue / 256;
	return (rtn);
}
