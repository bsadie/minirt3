/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:28:24 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/24 14:19:41 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SCENE_H
# define PARSE_SCENE_H

# include "scene.h"
# include "parser_utils_2.h"
# include "../utils/list.h"

void	parse_ambient(t_scene *scene, char **splitted_line);
void	parse_camera(t_scene *scene, char **splitted_line);
void	parse_light(t_scene *scene, char **splitted_line);

#endif
