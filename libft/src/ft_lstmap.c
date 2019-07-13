/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:21:13 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 20:21:35 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using malloc(3)) resulting from the successive applications
** of f. If the allocation fails, the function returns NULL.
*/

static void	ft_lstdel_elem(void *content, size_t content_size)
{
	if (content)
	{
		(void)content_size;
		free(content);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*ptr_list;
	t_list		*prev_list;

	if (!(lst) || !(f))
		return (NULL);
	list = f(lst);
	ptr_list = list;
	prev_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(prev_list->next = f(lst)))
		{
			ft_lstdel(&ptr_list, &ft_lstdel_elem);
			return (NULL);
		}
		prev_list = prev_list->next;
	}
	return (ptr_list);
}
