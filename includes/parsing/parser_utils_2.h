/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:10:29 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/22 12:17:02 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_2_H
# define PARSER_UTILS_2_H

# include "parser_utils_1.h"
# include <stdlib.h>

void	parse_coords(t_v3 *point, char *field);
void	parse_color2(t_color2 *result, char *field);
int		check_color2(t_color2 c);
void	check_scene(t_scene *scene);

#endif
