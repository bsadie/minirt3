/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:07:54 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:31:48 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils/free.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	free_objects(t_scene *scene)
{
	t_object	*iter;

	iter = (t_object *)ft_list_last(scene->objects);
	while (iter->ptr != NULL)
	{
		if (iter->ptr)
			free(iter->ptr);
		iter->ptr = NULL;
		iter = (t_object *)ft_list_last(scene->objects);
	}
}

void	ft_error(int err)
{
	if (err == 2)
	{
		ft_putstr_fd("Error! Wrong filename!\n", 0);
		ft_putstr_fd("For example: Name.rt\n", 0);
	}
	if (err == 3)
		ft_putstr_fd("Error! Malloc didn't allocate memory!\n", 0);
	exit(err);
}

void	check_malloc(void *string)
{
	if ((char *)string == NULL)
		ft_error(3);
}
