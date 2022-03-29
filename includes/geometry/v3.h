/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:04:34 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:14:40 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3_H
# define V3_H

# include <math.h>

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

double	vector_len(t_v3 vector);
void	normalize_vector(t_v3 *vector);
t_v3	create_v3(double x, double y, double z);
double	dot_product(t_v3 a, t_v3 b);

#endif
