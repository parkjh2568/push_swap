/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_of_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:19:56 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 15:40:53 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		ft_half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt)
{
	t_sort	*b_data;
	int		i;
	long	pb_cnt;

	pb_cnt = 0;
	i = 0;
	while (i < base->cnt)
	{
		if ((*a)->next->index < base->mid)
		{
			command_solo_p(a, b);
			write(1, "pb\n", 3);
			pb_cnt++;
		}
		else
			ft_support_half_r(a, b, 0);
		if (pb_cnt == base->mid_cnt)
			break ;
		i++;
	}
	b_data = ft_find_big_small(*b, ft_lstlen(*b));
	d_cnt->remain = d_cnt->remain - b_data->cnt;
	ft_sort_b(a, b, b_data);
}

void		full_sort_support(t_data **a_start, int *flag, int big_small)
{
	command_solo_r(a_start);
	write(1, "ra\n", 3);
	if (big_small == 1)
	{
		if (*flag == 0)
			*flag = 1;
	}
	else
	{
		if (*flag == 0)
			*flag = 2;
	}
}

void		setting_big_small(t_data **a_start, int flag)
{
	if (flag == 1)
	{
		command_solo_rr(a_start);
		write(1, "rra\n", 4);
	}
	else
	{
		command_solo_rr(a_start);
		write(1, "rra\n", 4);
		command_solo_rr(a_start);
		write(1, "rra\n", 4);
		command_solo_s(a_start);
		write(1, "sa\n", 3);
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
}

void		ft_full_of_sort(t_data **a_start, t_data **b_start, t_sort *s_base)
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
