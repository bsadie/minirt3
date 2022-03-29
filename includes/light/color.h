/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:34:20 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:15:05 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <math.h>

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef union u_int_color
{
	int				integer;
	unsigned char	comps[4];
}				t_int_color;

t_color	int_to_color(int color);
int		color_to_int(t_color color);

#endif
