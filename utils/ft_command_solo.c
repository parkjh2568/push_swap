/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_solo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:06:32 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 18:08:28 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	command_solo_s(t_data **data)
{
	t_data	*temp;
	int		len;

	len = ft_lstlen(*data);
	if (len > 1)
	{
		temp = (*data)->next;
		(*data)->next = (*data)->next->next;
		temp->next = (*data)->next->next;
		(*data)->next->next = temp;
	}
}

void	command_solo_p(t_data **data1, t_data **data2)
{
	t_data *temp1;
	t_data *temp2;

	temp1 = (*data1)->next;
	temp2 = (*data2)->next;
	if (temp1)
	{
		if (temp1->next)
			(*data1)->next = (*data1)->next->next;
		else
			(*data1)->next = NULL;

		if (temp2)
		{
			(*data2)->next = temp1;
			(*data2)->next->next = temp2;
		}
		else
		{
			(*data2)->next = temp1;
			(*data2)->next->next = NULL;
		}
	}
}
