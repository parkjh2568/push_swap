/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:42:47 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 15:58:33 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		is_available2(t_data *a_start, int *flag)
{
	t_data	*temp;
	t_data	*temp2;

	temp = a_start->next;
	while (temp && *flag == 0)
	{
		if (temp->lnum < -2147483648 || temp->lnum > 2147483647)
			*flag = -1;
		else
		{
			temp2 = temp->next;
			while (temp2)
			{
				if (temp->lnum == temp2->lnum)
				{
					*flag = -1;
					break ;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}
}

void		set_value(int *i, int *mine, char c)
{
	if (c == '-')
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

int			is_available(t_data **a_start)
{
	t_data	*temp;
	int		i;
	int		flag;
	int		mine;

	temp = (*a_start)->next;
	flag = 0;
	while (temp && flag == 0)
	{
		i = 0;
		set_value(&i, &mine, temp->num[i]);
		while (temp->num[i] && flag == 0)
		{
			if (temp->num[i] < '0' || temp->num[i] > '9')
				flag = -1;
			temp->lnum *= 10;
			temp->lnum += temp->num[i++] - '0';
		}
		if (mine == 1)
			temp->lnum *= -1;
		temp = temp->next;
	}
	if (flag == 0)
		is_available2(*a_start, &flag);
	return (flag);
}
