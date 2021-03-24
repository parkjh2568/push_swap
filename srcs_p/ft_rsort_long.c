/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsort_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:07:30 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 15:38:48 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

static void	supot_h(t_data **a, t_data **b, int *cnt, int flag)
{
	if (flag == 1)
	{
		command_solo_p(a, b);
		write(1, "pb\n", 3);
		*cnt += 1;
	}
	if (flag == 2)
	{
		command_solo_rr(a);
		write(1, "rra\n", 4);
	}
}

void		half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt)
{
	t_sort	*b_data;
	int		i;
	int		min_cnt;
	int		pb_cnt;

	pb_cnt = 0;
	min_cnt = 0;
	i = 0;
	while (i < base->cnt)
	{
		if ((*a)->next->index < base->mid)
			supot_h(a, b, &pb_cnt, 1);
		else
			ft_support_half_r(a, b, &min_cnt);
		if (pb_cnt == base->mid_cnt)
			break;
		i++;
	}
	while(min_cnt--)
			supot_h(a, b, 0, 2);
	b_data = ft_find_big_small(*b, ft_lstlen(*b));
	d_cnt->remain = d_cnt->remain - b_data->cnt;
	ft_sort_b(a, b, b_data);
}

void		ft_full_of_rsort(t_data **a_start, t_data **b_start, t_sort *s_base)
{
	t_sort	*b_data;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (i < s_base->cnt)
	{
		if ((*a_start)->next->index == s_base->small)
			full_sort_support(a_start, &flag, 1);
		else if ((*a_start)->next->index == s_base->big)
			full_sort_support(a_start, &flag, 2);
		else
		{
			command_solo_p(a_start, b_start);
			write(1, "pb\n", 3);
		}
		i++;
	}
	setting_big_small(a_start, flag);
	b_data = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	ft_sort_b(a_start, b_start, b_data);
	command_solo_r(a_start);
	write(1, "ra\n", 3);
}
