/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:28:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 12:01:10 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	ft_lstfree(t_data **lst)
{
	t_data *ot;
	t_data *clear;

	clear = (*lst);
	if (!clear)
	{
		while (clear)
		{
			ot = clear;
			clear = clear->next;
			free(ot->num);
			free(ot);
		}
		clear = NULL;
	}
}
