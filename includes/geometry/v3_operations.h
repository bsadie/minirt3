/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:10:55 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/14 15:02:18 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3_OPERATIONS_H
# define V3_OPERATIONS_H

# include "v3.h"

t_v3	cross_product(t_v3 a, t_v3 b);
t_v3	substract(t_v3 a, t_v3 b);
t_v3	v3_add(t_v3 a, t_v3 b);
t_v3	v3_multiply(t_v3 a, double x);

#endif
