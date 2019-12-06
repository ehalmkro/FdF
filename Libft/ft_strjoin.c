/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:58:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/28 16:35:47 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*ret;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, (char*)s1);
	ft_strcat(ret, s2);
	return (ret);
}
