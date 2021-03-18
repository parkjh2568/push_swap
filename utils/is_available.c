/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:42:47 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 15:12:54 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		is_available3(long *is_int, int *flag, int j)
{
	int		i;
	int		k;

	i = 0;
	while (i < j && *flag == 0)
	{
		k = i + 1;
		if (is_int[i] < -2147483648 || is_int[i] > 2147483647)
			*flag = -1;
		while (k < j)
		{
			if (is_int[i] == is_int[k])
			{
				*flag = -1;
				break ;
			}
			k++;
		}
		i++;
	}
}

void		set_value(int *i, int *mine, int flag)
{
	if (flag == 1)
	{
		*mine = 1;
		*i = 1;
	}
	else
	{
		*i = 0;
		*mine = 0;
	}
}

void		is_available2(t_data *temp, long *is_int, int *flag, int i)
{
	int		j;
	int		mine;

	j = 0;
	while (temp != NULL && *flag == 0)
	{
		i = 0;
		if (temp->num[i] == '-')
			set_value(&i, &mine, 1);
		else
			set_value(&i, &mine, 0);
		while (temp->num[i] && *flag == 0)
		{
			if (temp->num[i] < '0' || temp->num[i] > '9')
				*flag = -1;
			is_int[j] *= 10;
			is_int[j] += temp->num[i++] - '0';
		}
		if (mine == 1)
			is_int[j] *= -1;
		temp = temp->next;
		j++;
	}
	if (*flag == 0)
		is_available3(is_int, flag, j);
}

int			is_available(t_data *a_start)
{
	t_data	*temp;
	int		i;
	int		j;
	int		flag;
	long	*is_int;

	temp = a_start->next;
	flag = 0;
	i = ft_lstlen(a_start);
	is_int = malloc(sizeof(long) * (i));
	j = 0;
	while (j < i)
	{
		is_int[j] = 0;
		j++;
	}
	is_available2(temp, is_int, &flag, i);
	free(is_int);
	return (flag);
}
