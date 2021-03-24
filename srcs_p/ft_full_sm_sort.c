/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_sm_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:00:09 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 16:00:54 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		command_support(t_data **a_start, int flag)
{
	if (flag == 1)
	{
		command_solo_s(a_start);
		write(1, "sa\n", 3);
	}
	else if (flag == 2)
	{
		command_solo_rr(a_start);
		write(1, "rra\n", 4);
	}
	else if (flag == 3)
	{
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
}

void		command_support_p(t_data **a_start, t_data **b_start, int flag)
{
	if (flag == 1)
	{
		command_solo_p(a_start, b_start);
		write(1, "pb\n", 3);
	}
	else if (flag == 2)
	{
		command_solo_p(b_start, a_start);
		write(1, "pa\n", 3);
	}
}

void		ssm_sorting(t_data **a_start, t_data **b_start)
{
	t_sort	*s_base;

	s_base = ft_find_big_small(*a_start, ft_lstlen(*a_start));
	while ((*a_start)->next->index != s_base->small)
	{
		if ((*a_start)->next->next->index != s_base->small &&
			(*a_start)->next->index == s_base->big)
			command_support(a_start, 1);
		else if ((*a_start)->next->next->index == s_base->small &&
			(*a_start)->next->index != s_base->big)
			command_support(a_start, 1);
		else if (s_base->s_cnt > s_base->mid_cnt)
			command_support(a_start, 2);
		else
			command_support(a_start, 3);
	}
	if (is_sorted(*a_start) != OK)
	{
		command_support_p(a_start, b_start, 1);
		command_support(a_start, 1);
		command_support_p(a_start, b_start, 2);
	}
	free(s_base);
}

void		sm_sorting(t_data **a_start, t_data **b_start, int *pb_cnt)
{
	t_sort	*s_base;

	*pb_cnt = 1;
	s_base = ft_find_big_small(*a_start, ft_lstlen(*a_start));
	while ((*a_start)->next->index != s_base->small)
	{
		if ((*a_start)->next->next->index != s_base->small &&
			(*a_start)->next->index == s_base->big)
			command_support(a_start, 1);
		else if ((*a_start)->next->next->index == s_base->small &&
			(*a_start)->next->index != s_base->big)
			command_support(a_start, 1);
		else if (s_base->s_cnt > s_base->mid_cnt)
			command_support(a_start, 2);
		else
			command_support(a_start, 3);
	}
	if (is_sorted(*a_start) != OK)
	{
		command_support_p(a_start, b_start, 1);
		ssm_sorting(a_start, b_start);
		*pb_cnt = *pb_cnt + 1;
	}
	free(s_base);
}

void		ft_full_sm_sort(t_data **a_start, t_data **b_start, t_sort *s_base)
{
	int		pb_cnt;

	pb_cnt = 0;
	while ((*a_start)->next->index != s_base->small)
	{
		if ((*a_start)->next->next->index != s_base->small &&
			(*a_start)->next->index == s_base->big)
			command_support(a_start, 1);
		else if ((*a_start)->next->next->index == s_base->small &&
			(*a_start)->next->index != s_base->big)
			command_support(a_start, 1);
		else if (s_base->s_cnt > s_base->mid_cnt)
			command_support(a_start, 2);
		else
			command_support(a_start, 3);
	}
	if (is_sorted(*a_start) != OK)
	{
		command_support_p(a_start, b_start, 1);
		sm_sorting(a_start, b_start, &pb_cnt);
	}
	while (pb_cnt--)
		command_support_p(a_start, b_start, 2);
}
