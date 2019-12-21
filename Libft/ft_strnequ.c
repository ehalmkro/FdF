/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:44:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/29 12:18:57 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0 || ((s1 == NULL)))
		return (1);
	if (s2 == NULL)
		return (0);
	if (s2 != NULL)
	{
		while (s1[i] && s2[i] && (n - 1) > i)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}
