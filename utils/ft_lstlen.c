/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:10:05 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 12:00:43 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

int		ft_lstlen(t_data *data)
{
	t_data	*temp;
	int		i;

	temp = data->next;
	if (!temp)
		return (0);
	i = 1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
