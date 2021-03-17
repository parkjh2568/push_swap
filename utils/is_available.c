/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:42:47 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 16:49:01 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

int		is_available(t_data	*a_start)
{
	t_data	*temp;
	int		i;
	int		flag;

	temp = a_start->next;
	flag = 0;
	while(temp != NULL && flag == 0)
	{
		i = 0;
		while(temp->num[i] && flag == 0)
		{
			if (num[i] < '0' || num[i] > '9')
				flag = -1;
			i++;
		}
		temp = temp->next;
	}
	return (flag);
}
