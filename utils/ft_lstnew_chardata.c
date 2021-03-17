/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_chardata.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:07:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 16:12:11 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

t_data		ft_lstnew_chardata(char *data)
{
		t_data		*out;

		if (!(out = malloc(sizeof(t_data))))
			return (NULL);
		out->num = data;
		out->new = NULL;
		return (out);
}
