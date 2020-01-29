/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:53:27 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,\
		size_t dstsize)
{
	size_t dstlength;
	size_t srclength;
	size_t j;

	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (srclength + dstsize);
	while (*(src + j) && (dstsize - 1 > (dstlength + j)))
	{
		*(dst + dstlength + j) = *(src + j);
		j++;
	}
	if ((dstlength + j < dstsize) || !src[j])
		*(dst + dstlength + j) = '\0';
	if (dstsize <= dstlength)
		return (srclength + dstsize);
	else
		return (dstlength + srclength);
}
