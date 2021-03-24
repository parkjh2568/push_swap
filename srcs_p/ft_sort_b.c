/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:56:17 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 15:49:58 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		find_r_flag(t_sort **base)
{
	long	s_m;
	long	b_m;

	s_m = (*base)->s_cnt - (*base)->mid_cnt;
	b_m = (*base)->b_cnt - (*base)->mid_cnt;
	if (s_m < 0)
		s_m *= (-1);
	if (b_m < 0)
		s_m *= (-1);
	if (s_m > b_m)
		(*base)->r_flag = (*base)->s_cnt;
	else
		(*base)->r_flag = (*base)->b_cnt;
}

t_sort		*big_flag(t_data **a_start, t_data **b_start)
{
	t_sort	*out;

	command_solo_p(b_start, a_start);
	write(1, "pa\n", 3);
	out = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	find_r_flag(&out);
	return (out);
}

t_sort		*small_flag(t_data **a_start, t_data **b_start)
{
	t_sort	*out;

	command_solo_p(b_start, a_start);
	write(1, "pa\n", 3);
	out = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	find_r_flag(&out);
	if ((*b_start)->next != NULL)
	{
		if (out->small == (*b_start)->next->index)
		{
			command_solo_r(a_start);
			write(1, "ra\n", 3);
		}
		else
		{
			command_duo_r(a_start, b_start);
			write(1, "rr\n", 3);
		}
	}
	else
	{
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
	return (out);
}

void		reverse_a(t_data **a_start, int cnt)
{
	while (cnt-- > 0)
	{
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
}

void		ft_sort_b(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	int		big_cnt;

	big_cnt = 0;
	while ((*b_start)->next != NULL)
	{
		if ((*b_start)->next->index == b_data->big)
		{
			free(b_data);
			b_data = big_flag(a_start, b_start);
			big_cnt++;
		}
		else if ((*b_start)->next->index == b_data->small)
		{
			free(b_data);
			b_data = small_flag(a_start, b_start);
		}
		else if (b_data->r_flag < b_data->mid_cnt)
			support_b_sort(b_start, 1);
		else
			support_b_sort(b_start, 2);
	}
	reverse_a(a_start, big_cnt);
	free(b_data);
}
