/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:56:17 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 18:17:41 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

t_sort		*big_flag(t_data **a_start, t_data **b_start)
{
	t_sort	*out;

	out = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	command_solo_p(b_start, a_start);
	write(1, "pa\n", 3);
	return (out);
}

t_sort		*small_flag(t_data **a_start, t_data **b_start)
{
	t_sort	*out;

	out = ft_find_big_small(*b_start, ft_lstlen(*b_start));
	command_solo_p(b_start, a_start);
	write(1, "pa\n", 3);
	if ((*b_start)->next != NULL)
	{
		if (out->small == (*b_start)->next->lnum)
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

void		ft_sort_b(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	int		big_cnt;

	big_cnt = 0;
	while((*b_start)->next != NULL)
	{
		if ((*b_start)->next->lnum == b_data->big)
		{
			free(b_data);
			b_data = big_flag(a_start, b_start);
			big_cnt++;
		}
		else if ((*b_start)->next->lnum == b_data->small)
		{
			free(b_data);
			b_data = small_flag(a_start, b_start);
		}
		else
		{
			command_solo_r(b_start);
			write(1, "rb\n", 3);
		}
	}
	while(big_cnt-- > 0)
	{
		command_solo_r(a_start);
		write(1, "ra\n", 3);
	}
}
