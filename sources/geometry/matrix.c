/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:52:30 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:02:45 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/matrix.h"

t_v3	multiply_by_matrix(t_v3 p, t_matrix m)
{
	t_v3	rtn;

	rtn.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0] + m.d[3][0];
	rtn.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1] + m.d[3][1];
	rtn.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2] + m.d[3][2];
	return (rtn);
}

t_matrix	look_at(t_v3 origin, t_v3 cam_vector)
{
	t_matrix	m;
	t_v3		random;
	t_v3		right;
	t_v3		up;

	random = create_v3(0, 1, 0);
	normalize_vector(&random);
	right = cross_product(random, cam_vector);
	normalize_vector(&right);
	up = cross_product(cam_vector, right);
	normalize_vector(&up);
	m.d[0][0] = right.x;
	m.d[0][1] = right.y;
	m.d[0][2] = right.z;
	m.d[1][0] = up.x;
	m.d[1][1] = up.y;
	m.d[1][2] = up.z;
	m.d[2][0] = cam_vector.x;
	m.d[2][1] = cam_vector.y;
	m.d[2][2] = cam_vector.z;
	m.d[3][0] = origin.x;
	m.d[3][1] = origin.y;
	m.d[3][2] = origin.z;
	return (m);
}
