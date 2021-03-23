/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_of_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:19:56 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 16:41:29 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		ft_half_of_sort(t_data **a_start, t_data **b_start, t_sort *s_base)
{
	t_sort	*b_data;
	int		i;

	i = 0;
	while(i < s_base->cnt)
	{
		if ((*a_start)->next->lnum < s_base->mid)
		{
			command_solo_p(a_start, b_start);
			write(1, "pb\n", 3);
		}
		else
		{
			command_solo_r(a_start);
			write(1, "ra\n", 4);
		}
		i++;
	}
	b_data = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	ft_sort_b(a_start, b_start, b_data);
	free(b_data);
}

void		ft_full_of_sort(t_data **a_start, t_data **b_start, t_sort *s_base)
{
	t_sort	*b_data;
	int		i;

	i = 0;
	while(i < s_base->cnt)
	{
		command_solo_p(a_start, b_start);
		write(1, "pb\n", 3);
		i++;
	}
	b_data = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	ft_sort_b(a_start, b_start, b_data);
	free(b_data);
}
