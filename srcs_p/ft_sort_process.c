/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:35:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 16:42:08 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void		ft_sort_process(t_data **a_start, t_data **b_start, t_sort *b_data)
{
	//ft_half_of_sort(a_start, b_start, b_data);
	ft_full_of_sort(a_start, b_start, b_data);
}
