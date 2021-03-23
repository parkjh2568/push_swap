/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_can_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:53:37 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 18:33:39 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		divide_a_start(t_data **a_start)
{
	char	**out;
	t_data	*temp;

	out = ft_split((*a_start)->next->num, ' ');
	ft_lstfree(a_start);
	(*a_start)->next = NULL;
	
	temp = *a_start;
	int i;
	i = 0;
	while(out[i])
	{
		temp->next = ft_lstnew_chardata(ft_strdup(out[i]));
		temp = temp->next;
		i++;
	}
	i = 0;
	while(out[i])
	{
		free(out[i]);
		i++;
	}
	free(out[i]);
	free(out);

}

void		is_can_split(t_data **a_start)
{
	t_data *temp;
	int		sep;
	int		flag;
	int		i;

	i = 0;
	sep = 0;
	flag = OK;
	temp = (*a_start)->next;
	while(temp->num[i])
	{
		if (temp->num[i] == ' ')
			sep = 1;
		if ((temp->num[i] < '0' || temp->num[i] > '9') && temp->num[i] != ' ')
		{
			if (temp->num[i] != '-')
			{
				flag = KO;
				break;
			}
		}
		i++;
	}
	if (flag == OK && sep == 1)
	{
		divide_a_start(a_start);
	}
}
