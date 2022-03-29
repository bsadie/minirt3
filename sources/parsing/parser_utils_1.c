/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:37:55 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/22 12:27:58 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parser_utils_1.h"

void	put_error_exit(char *err)
{
	write(2, "Error: ", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(-1);
}

int	array_len(char **splitted_line)
{
	int	i;

	i = 0;
	while (splitted_line[i])
		i++;
	return (i);
}

int	check_normal(t_v3 normal)
{
	if (normal.x < -1 || normal.x > 1 \
	|| normal.y < -1 || normal.y > 1 \
	|| normal.z < -1 || normal.z > 1)
		return (0);
	return (1);
}

int	allowed_symbol(char c)
{
	if (c == '\t' | c == ' ' | c == '\n' | c == '.' || c == ',' || \
	(c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!allowed_symbol(line[i]) && i > 2)
			return (0);
		i++;
	}
	return (1);
}
