/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:19:32 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/29 18:59:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int m;
	int isneg;

	i = 0;
	m = 0;
	isneg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	if (str[i] == '+' && isneg == 1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		m = m * 10 + str[i] - 48;
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (m * isneg);
	}
	return (m * isneg);
}
