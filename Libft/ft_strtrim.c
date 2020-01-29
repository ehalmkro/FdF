/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:54:27 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && (s[start] == ' ' || s[start] == '\n' ||
			s[start] == '\t'))
		start++;
	end = ft_strlen(s);
	while (start < end && (s[end - 1] == ' ' || s[end - 1] == '\n' ||
			s[end - 1] == '\t'))
		end--;
	if (start == end)
		return (ft_strnew(1));
	len = end - start;
	ret = ft_strsub(s, start, len);
	if (!ret)
		return (NULL);
	return (ret);
}
