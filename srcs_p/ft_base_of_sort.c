/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_of_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:19:56 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 18:41:45 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		ft_half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt)
{
	t_sort	*b_data;
	int		i;

	i = 0;
	while(i < base->cnt)
	{
		if ((*a)->next->lnum < base->mid)
		{
			command_solo_p(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			command_solo_r(a);
			write(1, "ra\n", 4);
		}
		i++;
	}
	b_data = ft_find_big_small(*b, ft_lstlen(*b));
	d_cnt->remain = d_cnt->remain - b_data->cnt;
	ft_sort_b(a, b, b_data);
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
