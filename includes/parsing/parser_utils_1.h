/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:41:15 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/22 10:43:36 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_1_H
# define PARSER_UTILS_1_H

# include <stdlib.h>
# include "scene.h"
# include "../utils/ft_2.h"

void	put_error_exit(char *err);
int		array_len(char **splitted);
int		check_normal(t_v3 normal);
int		allowed_symbol(char c);
int		check_line(char *line);

#endif
