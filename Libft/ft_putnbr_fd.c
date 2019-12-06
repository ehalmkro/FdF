/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:06:18 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/21 17:12:28 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if ((l / 10) > 0)
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putnbr_fd(l % 10, fd);
	}
	else
		ft_putchar_fd(l + 48, fd);
}
