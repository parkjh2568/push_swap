/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:28:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/16 11:36:59 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	ft_lstfree(t_list **lst)
{
	t_list *ot;

	while(*lst)
	{
		ot = *lst;
		*lst = (*lst)->next;
		free(ot)
	}
	*lst = NULL;
}
