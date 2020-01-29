/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:33:25 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the amount of words on a string *s with the delimeter char c.
*/

size_t	ft_wordcount(char const *s, char c)
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
