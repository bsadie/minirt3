/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:43:40 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 17:45:58 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils/list.h"

t_list	*ft_list_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_list_add_back(t_list **old_list, t_list *new_list)
{
	t_list	*tmp;

	if (*old_list == NULL)
		*old_list = new_list;
	else if (old_list && new_list && *old_list)
	{
		tmp = ft_list_last(*old_list);
		tmp->next = new_list;
	}
}

t_list	*ft_list_new(void *data)
{
	t_list	*rtn;

	rtn = malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->data = data;
	rtn->next = NULL;
	return (rtn);
}

int	ft_list_size(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
