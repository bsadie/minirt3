/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:22:28 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:22:18 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt/minirt.h"

int	check_filename(char *filename)
{
	int		len;
	int		fd;
	char	c;

	len = ft_strlen(filename);
	if (len < 3 || filename[len - 1] != 't'
		|| filename[len - 2] != 'r' || filename[len - 3] != '.')
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, &c, 1) < 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 1 || check_filename(argv[1]))
		ft_error(2);
	else
		minirt(argv[1]);
	return (0);
}
