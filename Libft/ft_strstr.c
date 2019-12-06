/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:23:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/17 18:26:09 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!needle[i])
		return ((char*)haystack);
	while (*(haystack + i))
	{
		while (*(haystack + (i + j)) == *(needle + j))
		{
			j++;
			if (!*(needle + j))
				return ((char*)(haystack + i));
		}
		j = 0;
		i++;
	}
	return (0);
}
