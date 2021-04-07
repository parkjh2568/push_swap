/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rsorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:12:14 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 00:35:46 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

int			is_rsorted(t_data *data_start)
{
	t_data	*data;
	t_data	*data2;
	int		flag;

	flag = OK;
	if (data_start->next != NULL)
	{
		data = data_start->next;
		while (data && flag == OK)
		{
			data2 = data->next;
			while (data2)
			{
				if (data->lnum < data2->lnum)
					flag = KO;
				data2 = data2->next;
			}
			data = data->next;
		}
	}
	return (flag);
}
