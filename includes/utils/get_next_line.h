/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:32:57 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:13:57 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ft_1.h"
# include "get_next_line_utils.h"
# include "free.h"

# define BUFF_SIZE 100

int		get_next_line(int fd, char **line);

#endif
