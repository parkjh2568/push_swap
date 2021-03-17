/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 17:03:57 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void	test(t_data *a_start)
{
	t_data	*temp;

	temp = a_start->next;
	while(temp)
	{
		printf("%s---\n",temp->num);
		temp = temp->next;
	}
}

void	input_algo_command(t_data *a_start, t_data *b_start)
{

}

void	check_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	flag = is_available(a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
	input_algo_command(a_start, &b_start);
	test(a_start);
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
