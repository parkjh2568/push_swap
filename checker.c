/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 16:40:36 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void	check_start(t_data *a_start)
{
	t_data	*temp;
	int		len;

	temp = a_start->next;
	while(temp != NULL)
	{
		len = ft_strlen(temp->num);
		write(1,temp->num,len);
		write(1,"\n",1);
		temp = temp->next;
	}
	ft_lstfree(&a_start);
}

int		main(int count, char *data[])
{
	t_data	a_start;
	t_data	*temp;
	int		i;

	i = 0;
	ft_lstreset(&a_start);
	temp = &a_start;
	while(++i < count)
	{
		temp->next = ft_lstnew_chardata(ft_strdup(data[i]));
		temp = temp->next;
	}
	check_start(&a_start);
}
