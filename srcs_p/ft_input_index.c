/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:29:43 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 23:40:58 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

static void		reset_t_sort_data(t_sort *data, long l)
{
	data->cnt = 1;
	data->small = l;
	data->big = l;
	data->mid = 0;
	data->mid_cnt = 0;
}

static void		sort_data(long **data, int cnt)
{
	int			i;
	int			j;
	long		temp;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if ((*data)[j] > (*data)[j + 1])
			{
				temp = (*data)[j];
				(*data)[j] = (*data)[j + 1];
				(*data)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void			put_index(t_data **a_start, long *data, int cnt)
{
	int			i;
	t_data		*temp;

	temp = (*a_start)->next;
	while (temp != NULL)
	{
		i = 0;
		while (i < cnt)
		{
			if (temp->lnum == data[i])
			{
				temp->index = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

static void		find_mid(t_sort **out, t_data **a_start)
{
	long		*data;
	int			len;
	int			i;
	t_data		*temp;
	int			cnt;

	i = 0;
	len = ft_lstlen(*a_start);
	temp = (*a_start)->next;
	data = malloc(sizeof(long) * (len));
	while (i < len)
	{
		data[i] = temp->lnum;
		temp = temp->next;
		i++;
	}
	cnt = (int)(*out)->cnt;
	sort_data(&data, cnt);
	put_index(a_start, data, cnt);
	free(data);
}

void			ft_input_index(t_data **a_start, int cnt)
{
	t_data		*temp;
	t_sort		*out;
	int			i;

	i = 0;
	out = malloc(sizeof(t_sort));
	reset_t_sort_data(out, 0);
	if ((*a_start)->next != NULL)
	{
		temp = (*a_start)->next;
		reset_t_sort_data(out, temp->lnum);
		temp = temp->next;
		while (i < cnt - 1)
		{
			if (temp->lnum > out->big)
				out->big = temp->lnum;
			else if (temp->lnum < out->small)
				out->small = temp->lnum;
			out->cnt++;
			temp = temp->next;
			i++;
		}
		find_mid(&out, a_start);
	}
	free(out);
}
