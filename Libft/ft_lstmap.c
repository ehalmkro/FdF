/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:32:37 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/29 11:12:25 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using malloc(3))resulting from the successive applications
** of f. If the allocation fails, the function returns NULL
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	ret = f(lst);
	current = ret;
	lst = lst->next;
	while (lst)
	{
		current->next = f(lst);
		lst = lst->next;
		current = current->next;
	}
	return (ret);
}
