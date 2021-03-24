/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:29:43 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 14:51:28 by junhypar         ###   ########.fr       */
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
	data->b_cnt = 0;
	data->s_cnt = 0;
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

static void		find_mid(t_sort **out, t_data *a_start)
{
	long		*data;
	int			len;
	int			i;
	t_data		*temp;
	int			cnt;

	i = 0;
	len = ft_lstlen(a_start);
	temp = a_start->next;
	data = malloc(sizeof(long) * (len));
	while (i < len)
	{
		data[i] = temp->index;
		temp = temp->next;
		i++;
	}
	cnt = (int)(*out)->cnt;
	sort_data(&data, cnt);
	(*out)->mid = data[cnt / 2];
	(*out)->thir1 = data[cnt / 3];
	(*out)->thir2 = data[(cnt / 3) * 2];
	(*out)->mid_cnt = cnt / 2;
	free(data);
}

void		find_b_s(t_sort **out, long index, int i)
{
	if (index > (*out)->big)
	{
		(*out)->big = index;
		(*out)->b_cnt = i + 1;
	}
	else if (index < (*out)->small)
	{
		(*out)->small = index;
		(*out)->s_cnt = i + 1;
	}
}

t_sort		*ft_find_big_small(t_data *a_start, int cnt)
{
	t_data		*temp;
	t_sort		*out;
	int			i;

	i = 0;
	out = malloc(sizeof(t_sort));
	reset_t_sort_data(out, 0);
	if (a_start->next != NULL)
	{
		temp = a_start->next;
		reset_t_sort_data(out, temp->index);
		temp = temp->next;
		while (i < cnt - 1)
		{
			find_b_s(&out, temp->index, i);
			out->cnt++;
			temp = temp->next;
			i++;
		}
		find_mid(&out, a_start);
	}
	return (out);
}
