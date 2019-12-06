/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:50:45 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/28 17:02:01 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*numwrite(char *ret, int charcount, long nb)
{
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	while (charcount--)
	{
		if (ret[charcount] == '-')
			return (ret);
		ret[charcount] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (ret);
}

static char		*retwrite(char *ret)
{
	ret = ft_strnew(1);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		charcount;

	charcount = 1;
	ret = NULL;
	if (n == 0)
		return (retwrite(ret));
	nb = n;
	if (nb < 0)
	{
		charcount += 1;
		nb *= -1;
	}
	while (nb / 10 > 0)
	{
		nb /= 10;
		charcount++;
	}
	ret = ft_strnew(charcount);
	if (!ret)
		return (NULL);
	else
		return (numwrite(ret, charcount, (long)n));
}
