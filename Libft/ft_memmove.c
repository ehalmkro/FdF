/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:54:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	const unsigned char		*s;
	unsigned char			*d;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (s > d)
	{
		while (len > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = len;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dst);
}
