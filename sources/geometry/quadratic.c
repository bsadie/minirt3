/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:31:50 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 13:17:15 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry/quadratic.h"

void	swap_doubles(double *a, double *b)
{
	double	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

t_qparams	new_qparams(double a, double b, double c)
{
	t_qparams	rtn;

	rtn.a = a;
	rtn.b = b;
	rtn.c = c;
	return (rtn);
}

int	solve_quadratic(t_qparams params, double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = pow(params.b, 2) - 4 * params.a * params.c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.b / params.a;
		*x1 = *x0;
	}
	else
	{
		if (params.b > 0)
			q = -1 * (params.b + sqrt(discr)) / 2;
		else
			q = -1 * (params.b - sqrt(discr)) / 2;
		*x0 = q / params.a;
		*x1 = params.c / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}
