/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 11:35:52 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

void	print_data(t_data *a_start, t_data *b_start)
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

int		detect_input_data2(char *input, t_data *a_start, t_data *b_start)
{
	int		err_flag;

	err_flag = 0;
	if (input[1] == 'r')
	{
		if (input[2] == 'a')
			command_solo_rr(&a_start);
		else if (input[2] == 'b')
			command_solo_rr(&a_start);
		else if (input[2] == 'r')
			command_duo_rr(&a_start, &b_start);
		else if (input[2] == '\0')
			command_duo_r(&a_start, &b_start);
		else
			err_flag = 1;
	}
	else
	{
		if (input[1] == 'a')
			command_solo_r(&a_start);
		else if (input[1] == 'b')
			command_solo_r(&b_start);
		else
			err_flag = 1;
	}
	return (err_flag);
}

int		detect_input_data1(char *input, t_data *a_start, t_data *b_start)
{
	int		err_flag;

	err_flag = 0;
	if (input[0] == 's')
	{
		if (input[1] == 'a')
			command_solo_s(&a_start);
		else if (input[1] == 'b')
			command_solo_s(&b_start);
		else if (input[1] == 's')
			command_duo_s(&a_start, &b_start);
		else
			err_flag = 1;
	}
	else if (input[0] == 'p')
	{
		if (input[1] == 'a')
			command_solo_p(&b_start, &a_start);
		else if (input[1] == 'b')
			command_solo_p(&a_start, &b_start);
		else
			err_flag = 1;	
	}
	else if (input[0] == 'r')
		err_flag = detect_input_data2(input, a_start, b_start);
	else
		err_flag = 1;
	return (err_flag);
}

void	input_algo_command(t_data *a_start, t_data *b_start)
{
	char	*input;
	int		gnl_flag;
	int		detect_flag;

	gnl_flag = 10;
	detect_flag = 0;
	while(gnl_flag > 0 && detect_flag == 0)
	{
		gnl_flag = get_next_line(&input);
		if (gnl_flag >= 0)
			detect_flag = detect_input_data1(input, a_start, b_start);
		free(input);
		print_data(a_start, b_start);
		printf("\n\n");
	}
	if (detect_flag != 0)
		ft_error(a_start, b_start);
}

void	check_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	flag = is_available(a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
	print_data(a_start, &b_start);
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
