/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:35:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 14:55:29 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		doing_half_sort(t_data **a_start, t_data **b_start, t_cnt *d_cnt)
{
	t_sort	*base;

	base = ft_find_big_small(*a_start, d_cnt->remain);
	ft_thir_sort(a_start, b_start, base, &d_cnt);
	free(base);
	base = ft_find_big_small(*a_start, d_cnt->remain);
	while(d_cnt->remain > 50)
	{
		half_of_sort(a_start, b_start,base, d_cnt);
		free(base);
		base = ft_find_big_small(*a_start, d_cnt->remain);
	}
	ft_full_of_rsort(a_start, b_start, base);
	free(base);
}

void		many_sort_start(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	t_cnt	d_cnt;
	t_sort	*base;

	d_cnt.max = b_data->cnt;
	d_cnt.remain = b_data->cnt;
	if (d_cnt.remain > 100)
		doing_half_sort(a_start, b_start, &d_cnt);
	else
	{
		ft_half_of_sort(a_start, b_start, b_data, &d_cnt);
		base = ft_find_big_small(*a_start, d_cnt.remain);
		ft_full_of_sort(a_start, b_start, base);
		free(base);
	}
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
