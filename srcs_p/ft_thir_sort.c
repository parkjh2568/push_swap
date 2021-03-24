/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thir_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:52:09 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 16:06:32 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

static void	support_thir(t_data **a_start, t_data **b_start, int flag,
		int *cnt)
{
	if (flag == 1)
	{
		command_solo_p(a_start, b_start);
		write(1, "pb\n", 3);
		command_solo_r(b_start);
		write(1, "rb\n", 3);
		*cnt += 1;
	}
	else if (flag == 2)
	{
		command_solo_p(a_start, b_start);
		write(1, "pb\n", 3);
		*cnt += 1;
	}
	else if (flag == 3)
	{
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
}

static void	support_th_p(t_data **a_start, t_data **b_start, int flag)
{
	if (flag == 1)
	{
		command_solo_p(b_start, a_start);
		write(1, "pa\n", 3);
	}
	else if (flag == 2)
	{
		command_solo_p(a_start, b_start);
		write(1, "pb\n", 3);
	}
}

static void	set_zero(int *t1, int *t2, int *t3)
{
	*t1 = 0;
	*t2 = 0;
	*t3 = 0;
}

void		ft_thir_sort(t_data **a_start, t_data **b_start, t_sort *s_base,
		t_cnt **d_cnt)
{
	t_sort	*b_data;
	int		t[3];

	set_zero(&t[0], &t[1], &t[2]);
	while (t[0]++ < s_base->cnt)
	{
		if ((*a_start)->next->index < s_base->thir1)
			support_thir(a_start, b_start, 1, &t[1]);
		else if ((*a_start)->next->index >= s_base->thir1 &&
				(*a_start)->next->index < s_base->thir2)
			support_thir(a_start, b_start, 2, &t[2]);
		else
			support_thir(a_start, b_start, 3, 0);
	}
	(*d_cnt)->remain = (*d_cnt)->remain - t[1] - t[2];
	t[1] = t[2];
	while (t[1]--)
		support_th_p(a_start, b_start, 1);
	b_data = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	ft_sort_b(a_start, b_start, b_data);
	while (t[2]--)
		support_th_p(a_start, b_start, 2);
	b_data = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	ft_sort_b(a_start, b_start, b_data);
}
