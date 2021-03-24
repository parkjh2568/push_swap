/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:35:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 12:41:58 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt)
{
	t_sort	*b_data;
	int		i;
	int		min_cnt;
	int		pb_cnt;

	pb_cnt = 0;
	min_cnt = 0;
	i = 0;
	while(i < base->cnt)
	{
		if ((*a)->next->index < base->mid)
		{
			command_solo_p(a, b);
			write(1, "pb\n", 3);
			pb_cnt++;
		}
		else
			ft_support_half_r(a, b, &min_cnt);
		if (pb_cnt == base->mid_cnt)
			break;
		i++;
	}
	while(min_cnt--)
	{
		command_solo_rr(a);
		write(1, "rra\n", 5);
	}
	b_data = ft_find_big_small(*b, ft_lstlen(*b));
	d_cnt->remain = d_cnt->remain - b_data->cnt;
	ft_sort_b(a, b, b_data);
}

void		doing_half_sort(t_data **a_start, t_data **b_start, t_cnt *d_cnt)
{
	t_sort	*base;

	base = ft_find_big_small(*a_start, d_cnt->remain);
	while(d_cnt->remain > 3)
	{
		half_of_sort(a_start, b_start,base, d_cnt);
		free(base);
		base = ft_find_big_small(*a_start, d_cnt->remain);
	}
	ft_full_of_sort(a_start, b_start, base);
	free(base);
}

void		many_sort_start(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	t_cnt	d_cnt;
	t_sort	*base;

	d_cnt.max = b_data->cnt;
	d_cnt.remain = b_data->cnt;
	ft_half_of_sort(a_start, b_start, b_data, &d_cnt);
	base = ft_find_big_small(*a_start, d_cnt.remain);
	if (d_cnt.remain > 5)
		doing_half_sort(a_start, b_start, &d_cnt);
	else
		ft_full_of_sort(a_start, b_start, base);
	free(base);
}

void		ft_sort_process(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	if (b_data->cnt > 5)
		many_sort_start(a_start, b_start, b_data);
	else if (b_data->cnt > 2)
		ft_full_sm_sort(a_start, b_start, b_data);
	else
	{
		command_solo_s(a_start);
		write(1, "sa\n", 3);
	}
}
