/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:02:27 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/24 18:34:46 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (!ret)
		return (0);
	ft_bzero(ret, size);
	return (ret);
}
