/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:50:19 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/28 14:10:15 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the address of a pointer to a link and frees the memory
** of this link and every successors of that link.
** Finally sets the pointer to the link that was just freed to NULL
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	while (*alst)
	{
		current = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = current;
	}
	*alst = NULL;
}
