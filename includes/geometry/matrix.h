/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:53:23 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:12:19 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "v3_operations.h"

typedef struct s_matrix
{
	double	d[4][3];
}				t_matrix;

t_v3		multiply_by_matrix(t_v3 p, t_matrix m);
t_matrix	look_at(t_v3 origin, t_v3 cam_vector);

#endif
