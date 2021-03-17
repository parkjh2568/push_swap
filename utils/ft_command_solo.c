/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_solo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:06:32 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 17:22:17 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	command_solo_sa(t_data **data)
{
	t_data	*temp;
	int		len;

	len = ft_lstlen(*data);
	if (len > 1)
	{
		temp = (*data)->next;
		(*data)->next = (*data)->next->next;
		temp->next = (*data)->next->next;
		(*data)->next = temp;
	}
}
