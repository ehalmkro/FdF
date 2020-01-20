/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:05:47 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 10:31:22 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: RGB COLOR GRADIENTS


int		set_color(t_point *start, t_point *end)
{
	if (start->z == 0 && end->z == 0)
		return(0xf58d42);
	return(0x42bff5);
}


