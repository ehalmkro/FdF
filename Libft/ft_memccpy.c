/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:40:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/24 19:48:56 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (d + i + 1);
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
