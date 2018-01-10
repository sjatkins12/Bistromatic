/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:17:36 by satkins           #+#    #+#             */
/*   Updated: 2018/01/08 20:17:39 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

int	is_base(char c, t_bistro *bistro)
{
	int	i;

	i = -1;
	while (++i < bistro->base_size)
	{
		if (c == bistro->base[i])
			return (1);
	}
	return (0);
}

void	split_operand(t_bistro *bistro)
{
	
}