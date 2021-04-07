/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_chardata.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:07:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 12:03:29 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

t_data		*ft_lstnew_chardata(char *data)
{
	t_data	*out;

	if (!(out = malloc(sizeof(t_data))))
		return (NULL);
	out->num = data;
	out->next = NULL;
	return (out);
}
