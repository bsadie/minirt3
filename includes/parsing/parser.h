/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:18:27 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:13:00 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <fcntl.h>
# include "parse_objects.h"
# include "parse_scene.h"
# include "../utils/get_next_line.h"
# include "../utils/ft_2.h"
# include "../utils/free.h"

void	init_scene(t_scene *scene);
void	parse_line(t_scene *scene, char **splitted_line);
int		gnl_loop(int fd, t_scene *scene);
t_scene	*parse_file(char *path);

#endif
