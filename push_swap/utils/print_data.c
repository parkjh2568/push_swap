/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:43:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/04/07 22:05:18 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

long	ft_small(t_data *temp)
{
	t_data	*data;
	long	small;

	if (temp->next)
	{
		data = temp->next;
		small = atoi(data->num);
		data = data->next;
		while(data != NULL)
		{
			if (small > atoi(data->num))
				small = atoi(data->num);
			data = data->next;
		}
	}
	else
		small = -1;
	return (small);
}

long	ft_big(t_data *temp)
{
	t_data	*data;
	long	big;

	if (temp->next)
	{
		data = temp->next;
		big = atoi(data->num);
		data = data->next;
		while(data != NULL)
		{
			if (big < atoi(data->num))
				big = atoi(data->num);
			data = data->next;
		}
	}
	else
		big = -1;
	return (big);
}

void	print_data2(t_data *a_start, t_data *b_start, int i, int len)
{
	t_data	*temp1;
	t_data	*temp2;
	int j;
	long big1;
	long big2;
	long small1;
	long small2;
	long cnt;

	temp1 = a_start->next;
	temp2 = b_start->next;
	big1 = ft_big(a_start);
	big2 = ft_big(b_start);
	small1 = ft_small(a_start);
	small2 = ft_small(b_start);
	j = 0;
	while (j++ < i)
	{
		write(1, "|\t", 2);
		if (temp1)
		{
			if (atoi(temp1->num) == big1)
				write(1, "\033[31m", 5);
			else if (atoi(temp1->num) == small1)
				write(1, "\033[32m", 5);
			len = ft_strlen(temp1->num);
			write(1, temp1->num, len);
			write(1, "\033[0m", 4);
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
			if (atoi(temp2->num) == big2)
				write(1, "\033[31m", 5);
			else if (atoi(temp2->num) == small2)
				write(1, "\033[32m", 5);
			write(1, temp2->num, ft_strlen(temp2->num));
			temp2 = temp2->next;
			write(1, "\033[0m", 4);
		}
		write(1, "\n", 1);		
	}
	cnt = 0;
	while(cnt++ < 50000000){}
}

void	print_data(t_data *a_start, t_data *b_start)
{

	int		i;
	int		len;

	system("clear");
	len = 0;

	i = ft_lstlen(a_start);
	if (i < ft_lstlen(b_start))
		i = ft_lstlen(b_start);
	write(1, "\ta\t\t|\tb\n", 8);
	write(1, "|-----------------------|--------------------\n", 46);
	print_data2(a_start, b_start, i, len);
}
