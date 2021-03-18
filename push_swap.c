/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:19:45 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 16:46:53 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void		sorting_start(t_data *a_start, t_data *b_start)
{
	t_sort	*origin_data;

	(void)b_start;
	origin_data = ft_find_big_small(a_start);
	printf("big = %ld, small = %ld\n",origin_data->big,origin_data->small);
	ft_lstfree(&a_start);
	free(origin_data);
}

void		push_swap_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	flag = is_available(&a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
	print_data(a_start, &b_start);
	printf("\n");
	sorting_start(a_start, &b_start);
}

int			main(int count, char *data[])
{
	t_data	a_start;
	t_data	*temp;
	int		i;

	i = 0;
	ft_lstreset(&a_start);
	temp = &a_start;
	while (++i < count)
	{
		temp->next = ft_lstnew_chardata(ft_strdup(data[i]));
		temp = temp->next;
	}
	push_swap_start(&a_start);
}
