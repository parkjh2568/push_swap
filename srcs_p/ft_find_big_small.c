/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:29:43 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 16:46:39 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		reset_t_sort_data(t_sort *data, long l)
{
	data->cnt = 0;
	data->small = l;
	data->big = l;
}

t_sort		*ft_find_big_small(t_data *a_start)
{
	t_data	*temp;
	t_sort	*out;

	out = malloc(sizeof(t_sort));
	if (a_start->next != NULL)
	{
		temp = a_start->next;
		reset_t_sort_data(out, temp->lnum);
		temp = temp->next;
		while(temp)
		{
			if (temp->lnum > out->big)
				out->big = temp->lnum;
			else if (temp->lnum < out->small)
				out->small = temp->lnum;
			out->cnt++;
			temp = temp->next;
		}
	}
	return (out);
}
