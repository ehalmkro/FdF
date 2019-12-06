/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:28:53 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/30 14:42:31 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if ((*(s + i) != c && *(s + (i + 1)) == c) ||\
			(*(s + i) != c && *(s + i + 1) == '\0'))
			count++;
		i++;
	}
	return (count);
}

static size_t	wordlength(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s + i) != c && *(s + i))
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		h;
	char		**ret;

	i = 0;
	h = 0;
	if (!s || !(ret = (char**)malloc(sizeof(char*) * wordcount(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(ret[h] = (char*)malloc(sizeof(char) * wordlength(s, c) + 1)))
				return (NULL);
			while (*s != c && *s)
				ret[h][i++] = (char)*s++;
			ret[h][i] = '\0';
			h++;
			i = 0;
		}
		ret[h] = NULL;
	}
	return (ret);
}
