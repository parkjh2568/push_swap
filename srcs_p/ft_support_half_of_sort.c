/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_half_of_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:15:28 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 12:37:27 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

static void	r_supporter(t_data **a, t_data **b, int flag)
{
	if (flag == 1)
	{
		command_duo_r(a, b);
		write(1, "rr\n", 3);
	}
	else if(flag == 2)
	{
		command_solo_r(a);
		write(1, "ra\n", 3);
	}
}

void		ft_support_half_r(t_data **a, t_data **b, int *cnt)
{
	t_sort	*base;

	if ((*b)->next != NULL)
	{
		base = ft_find_big_small(*b, ft_lstlen(*b));
		if ((*b)->next->index == base->small)
			r_supporter(a, b, 1);
		else if ((*b)->next->index == base->big)
			r_supporter(a, b, 1);
		else
			r_supporter(a, b, 2);
		free(base);
	}
	else
		r_supporter(a, b, 2);
	*cnt += 1;
}
