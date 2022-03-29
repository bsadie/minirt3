/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:02 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:12:52 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OBJECTS_H
# define PARSE_OBJECTS_H

# include "scene.h"
# include "parser_utils_2.h"
# include "../geometry/sphere.h"
# include "../geometry/plane.h"
# include "../geometry/cylinder.h"
# include "../utils/free.h"

void	parse_sphere(t_scene *scene, char **splitted_line);
void	parse_plane(t_scene *scene, char **splitted_line);
void	parse_cylinder(t_scene *scene, char **splitted_line);

#endif
