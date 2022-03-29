/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:00:05 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:13:47 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRATIC_H
# define QUADRATIC_H

# include <math.h>

typedef struct s_qparams
{
	double	a;
	double	b;
	double	c;
}				t_qparams;

void		swap_doubles(double *a, double *b);
t_qparams	new_qparams(double a, double b, double c);
int			solve_quadratic(t_qparams params, double *x0, double *x1);

#endif
