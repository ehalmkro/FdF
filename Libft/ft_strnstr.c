/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:23 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 15:05:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((!needle[i]) || (ft_strcmp(haystack, needle) == 0))
		return ((char*)haystack);
	if (!haystack)
		return (NULL);
	while (*(haystack + i))
	{
		while (*(haystack + (i + j)) == *(needle + j))
		{
			j++;
			if (!*(needle + j) && (int)len >= i + j)
				return ((char*)(haystack + i));
		}
		j = 0;
		i++;
	}
	return (0);
}
