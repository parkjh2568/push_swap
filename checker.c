/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/16 11:36:40 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void	reset_list(t_list *data)
{
	data->content = 0;
	data->next = NULL;
}

void	check_start(t_list *a_start)
{
	t_list	*temp;
	int		len;

	temp = a_start->next;
	while(temp)
	{
		len = ft_strlen(temp->content);
		write(1,temp->content,len);
		temp = temp->next;
	}
	ft_lstclear(&a_start, ft_delete);
}

int		main(int count, char *data[])
{
	t_list	a_start;
	t_list	*temp;
	int		i;

	i = 0;
	reset_list(&a_start);
	temp = &a_start;
	while(++i < count)
	{
		temp->next = ft_lstnew(data[i]);
		temp = temp->next;
	}
	check_start(&a_start);
}
