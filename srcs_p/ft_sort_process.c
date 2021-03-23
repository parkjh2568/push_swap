/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:35:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 19:18:41 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt)
{
	t_sort	*b_data;
	int		i;
	int		min_cnt;

	min_cnt = 0;
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
			min_cnt++;
		}
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
	free(b_data);
}

void		doing_half_sort(t_data **a_start, t_data **b_start,
		t_sort *b_data, t_cnt *d_cnt)
{
	while(d_cnt->remain > 5)
	{
		half_of_sort(a_start, b_start, b_data, d_cnt);
		free(b_data);
		b_data = ft_find_big_small(*a_start, d_cnt->remain);
/*
		printf("\n fucking\n");
		printf("b_data big = %ld, b_data small = %ld, b_data cnt = %ld\n",
				b_data->big, b_data->small, b_data->cnt);
		printf("max = %ld, remain = %ld\n",d_cnt->max,d_cnt->remain);
		print_data(*a_start, *b_start);
*/
	}
	ft_full_of_sort(a_start, b_start, b_data);
}

void		many_sort_start(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	t_cnt	d_cnt;

	d_cnt.max = b_data->cnt;
	d_cnt.remain = b_data->cnt;
	ft_half_of_sort(a_start, b_start, b_data, &d_cnt);
	free(b_data);
	b_data = ft_find_big_small(*a_start, d_cnt.remain);
/*
	printf("\n fucking\n");
	printf("b_data big = %ld, b_data small = %ld, b_data cnt = %ld\n",
	b_data->big, b_data->small, b_data->cnt);
	printf("max = %ld, remain = %ld\n",d_cnt.max,d_cnt.remain);
	print_data(*a_start, *b_start);
*/	
	if (d_cnt.remain > 5)
		doing_half_sort(a_start, b_start, b_data, &d_cnt);
	else
		ft_full_of_sort(a_start, b_start, b_data);
}


void		ft_sort_process(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	if (b_data->cnt > 5)
	{
		printf("half\n");
		many_sort_start(a_start, b_start, b_data);
	}
	else
	{
		printf("full\n");
		ft_full_of_sort(a_start, b_start, b_data);
	}
}
