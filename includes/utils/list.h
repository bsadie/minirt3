/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:08:21 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:20:48 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

t_list		*ft_list_last(t_list *list);
void		ft_list_add_back(t_list **old_list, t_list *new_list);
t_list		*ft_list_new(void *data);
int			ft_list_size(t_list *list);
void		check_malloc(void *string);

#endif
