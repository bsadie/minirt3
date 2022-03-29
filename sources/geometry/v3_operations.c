/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:09:45 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:14:41 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/v3_operations.h"

t_v3	cross_product(t_v3 a, t_v3 b)
{
	t_v3	rtn;

	rtn.x = a.y * b.z - a.z * b.y;
	rtn.y = a.z * b.x - a.x * b.z;
	rtn.z = a.x * b.y - a.y * b.x;
	return (rtn);
}

t_v3	substract(t_v3 a, t_v3 b)
{
	t_v3	rtn;

	rtn.x = a.x - b.x;
	rtn.y = a.y - b.y;
	rtn.z = a.z - b.z;
	return (rtn);
}

t_v3	v3_add(t_v3 a, t_v3 b)
{
	t_v3	rtn;

	rtn.x = a.x + b.x;
	rtn.y = a.y + b.y;
	rtn.z = a.z + b.z;
	return (rtn);
}

t_v3	v3_multiply(t_v3 a, double x)
{
	t_v3	rtn;

	rtn.x = a.x * x;
	rtn.y = a.y * x;
	rtn.z = a.z * x;
	return (rtn);
}
