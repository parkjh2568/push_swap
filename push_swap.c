/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:19:45 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 17:14:30 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void		sorting_start(t_data *a_start, t_data *b_start)
{
	t_sort	*origin_data;
	int		flag;

	(void)b_start;
	origin_data = ft_find_big_small(a_start, ft_lstlen(a_start));
	flag = is_sorted(a_start);
	if (flag == OK)
		printf("is sorted\n");
	else
		ft_sort_process(&a_start, &b_start, origin_data);

//	print_data(a_start, b_start);
	ft_lstfree(&a_start);
	ft_lstfree(&b_start);
	free(origin_data);
}

void		push_swap_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	is_can_split(&a_start);
	ft_lstfree(&a_start);
	flag = is_available(&a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
//	print_data(a_start, &b_start);
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
