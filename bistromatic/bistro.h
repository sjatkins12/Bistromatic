/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:54:43 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/12 15:22:11 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H

# define BISTRO_H

# include "libft.h"

typedef struct	s_bistro
{
	char		*base;
	int			base_size;
	char		*exp;
	int			exp_size;
	t_btree		*tree;
}				t_bistro;

#endif
