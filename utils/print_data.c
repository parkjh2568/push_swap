/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:43:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 15:09:42 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

void	print_data2(t_data *temp1, t_data *temp2, int i, int len)
{
	int j;

	j = 0;
	while (j++ < i)
	{
		write(1, "|\t", 2);
		if (temp1)
		{
			len = ft_strlen(temp1->num);
			write(1, temp1->num, len);
			if (len >= 8)
				write(1, "\t|\t", 3);
			else
				write(1, "\t\t|\t", 4);
			temp1 = temp1->next;
		}
		else
			write(1, "\t\t|\t", 4);
		if (temp2)
		{
			write(1, temp2->num, ft_strlen(temp2->num));
			temp2 = temp2->next;
		}
		write(1, "\n", 1);
	}
}

void	print_data(t_data *a_start, t_data *b_start)
{
	t_data	*temp1;
	t_data	*temp2;
	int		i;
	int		len;

	len = 0;
	temp1 = a_start->next;
	temp2 = b_start->next;
	i = ft_lstlen(a_start);
	if (i < ft_lstlen(b_start))
		i = ft_lstlen(b_start);
	write(1, "\ta\t\t|\tb\n", 8);
	write(1, "|-----------------------|--------------------\n", 46);
	print_data2(temp1, temp2, i, len);
}
