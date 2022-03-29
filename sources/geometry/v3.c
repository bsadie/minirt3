/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:32:47 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:12:24 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/v3.h"

double	vector_len(t_v3 vector)
{
	double	len;

	len = sqrt(vector.x * vector.x + \
				vector.y * vector.y + \
				vector.z * vector.z);
	return (len);
}

void	normalize_vector(t_v3 *vector)
{
	double	len;

	len = vector_len(*vector);
	vector->x /= len;
	vector->y /= len;
	vector->z /= len;
}

t_v3	create_v3(double x, double y, double z)
{
	t_v3	rtn;

	rtn.x = x;
	rtn.y = y;
	rtn.z = z;
	return (rtn);
}

double	dot_product(t_v3 a, t_v3 b)
{
	double	sum;

	sum = a.x * b.x + a.y * b.y + a.z * b.z;
	return (sum);
}
