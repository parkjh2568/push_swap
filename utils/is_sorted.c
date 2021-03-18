/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:12:14 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 15:10:58 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

int			is_sorted(t_data *data_start)
{
	int		num1;
	int		num2;
	t_data	*data;
	int		flag;

	flag = OK;
	if (data_start->next != NULL)
	{
		data = data_start->next;
		while (data->next && flag == OK)
		{
			num1 = ft_atoi(data->num);
			num2 = ft_atoi(data->next->num);
			if (num1 > num2)
				flag = KO;
			data = data->next;
		}
	}
	return (flag);
}
