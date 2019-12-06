/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:38:45 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/29 10:12:15 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL || ft_strlen(s) < start)
		return (NULL);
	i = 0;
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	else
		while (i < len)
		{
			ret[i] = s[start];
			i++;
			start++;
		}
	ret[i] = '\0';
	return (ret);
}
