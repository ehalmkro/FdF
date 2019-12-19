/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:31:04 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/19 14:35:55 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
    t_list *current;

    if (!alst || !new)
        return ;
    current = *alst;
    while (current->next)
        current = current->next;
    current->next = new;
}
