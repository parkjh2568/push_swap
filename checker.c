/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 18:24:12 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void	test(t_data *a_start, t_data *b_start)
{
	t_data	*temp1;
	t_data	*temp2;
	int		i;
	int		j;

	j = 0;
	temp1 = a_start->next;
	temp2 = b_start->next;
	i = ft_lstlen(a_start);
	if (i < ft_lstlen(b_start))
		i = ft_lstlen(b_start);
	printf("\t\ta\t|\tb\n");
	printf("\t|---------------|------------\n");
	while(j < i)
	{
		printf("%d\t|\t",j + 1);
		if(temp1)
		{
			printf("%s\t|\t",temp1->num);
			temp1 = temp1->next;
		}
		else
		{
			printf("\t|\t");
		}
		if(temp2)
		{
			printf("%s",temp2->num);
			temp2 = temp2->next;
		}
		printf("\n");
		j++;
	}
}

void	test1(t_data *a_start, t_data *b_start)
{
	command_solo_s(&a_start);
	printf("sa\n");
	test(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	test(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
}

void	test2(t_data *a_start, t_data *b_start)
{
	printf("ra\n");
	command_solo_r(&a_start);
	test(a_start, b_start);
	printf("\n\n");

	printf("rb\n");
	command_solo_r(&b_start);
	test(a_start, b_start);
	printf("\n\n");

	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");

	printf("ra\n");
	command_solo_r(&a_start);
	test(a_start, b_start);
	printf("\n\n");


	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");

	printf("ra\n");
	command_solo_r(&a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("rb\n");
	command_solo_r(&b_start);
	test(a_start, b_start);
	printf("\n\n");

	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("ra\n");
	command_solo_r(&a_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("rb\n");
	command_solo_r(&b_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	test(a_start, b_start);
	printf("\n\n");
		printf("rb\n");
	command_solo_r(&b_start);
	test(a_start, b_start);
	printf("\n\n");printf("rb\n");
	command_solo_r(&b_start);
	test(a_start, b_start);
	printf("\n\n");
}

void	input_algo_command(t_data *a_start, t_data *b_start)
{
//	test1(a_start, b_start);
//	test2(a_start, b_start);
	ft_lstfree(&a_start);
	ft_lstfree(&b_start);
}

void	check_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	flag = is_available(a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
	test(a_start, &b_start);
	printf("\n");
	input_algo_command(a_start, &b_start);
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
