/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_of_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:13:41 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 13:56:32 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		check_ok(t_data **a_start, t_data **b_start)
{
	ft_lstfree(a_start);
	ft_lstfree(b_start);
	write(1, "OK\n", 3);
	exit(0);
}

void		check_ko(t_data **a_start, t_data **b_start)
{
	ft_lstfree(a_start);
	ft_lstfree(b_start);
	write(1, "KO\n", 3);
	exit(0);
}

void		result_of_checker(t_data **a_start, t_data **b_start)
{
	int		flag;

	if ((*b_start)->next == NULL)
	{
		flag = is_sorted(*a_start);
		if (flag == OK)
			check_ok(a_start, b_start);
	}
	check_ko(a_start, b_start);
}
