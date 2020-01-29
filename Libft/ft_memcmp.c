/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:30:32 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (n--)
	{
		if (*(unsigned char*)(s1 + i) < *(unsigned char*)(s2 + i) ||\
			*(unsigned char*)(s1 + i) > *(unsigned char*)(s2 + i))
		{
			ret = *(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i);
			return (ret);
		}
		i++;
	}
	return (0);
}
