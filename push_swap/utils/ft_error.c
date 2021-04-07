/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:50:50 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 22:10:24 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	ft_error(t_data *a_start, t_data *b_start)
{
	ft_lstfree(&a_start);
	ft_lstfree(&b_start);
	write(2, "Error\n", 6);
	exit(1);
}
