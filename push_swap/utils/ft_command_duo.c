/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_duo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:06:32 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 11:33:04 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	command_duo_s(t_data **data1, t_data **data2)
{
	command_solo_s(data1);
	command_solo_s(data2);
}

void	command_duo_r(t_data **data1, t_data **data2)
{
	command_solo_r(data1);
	command_solo_r(data2);
}

void	command_duo_rr(t_data **data1, t_data **data2)
{
	command_solo_rr(data1);
	command_solo_rr(data2);
}
