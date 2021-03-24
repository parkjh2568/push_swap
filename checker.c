/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 15:31:35 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_p_algo.h"

int			detect_input_data2(char *input, t_data *a_start, t_data *b_start)
{
	if (input[1] == 'r')
	{
		if (input[2] == 'a')
			command_solo_rr(&a_start);
		else if (input[2] == 'b')
			command_solo_rr(&b_start);
		else if (input[2] == 'r')
			command_duo_rr(&a_start, &b_start);
		else if (input[2] == '\0')
			command_duo_r(&a_start, &b_start);
		else
			return (KO);
	}
	else
	{
		if (input[1] == 'a')
			command_solo_r(&a_start);
		else if (input[1] == 'b')
			command_solo_r(&b_start);
		else
			return (KO);
	}
	return (OK);
}

int			detect_input_data1(char *input, t_data *a_start, t_data *b_start)
{
	if (input[0] == 's')
	{
		if (input[1] == 'a')
			command_solo_s(&a_start);
		else if (input[1] == 'b')
			command_solo_s(&b_start);
		else if (input[1] == 's')
			command_duo_s(&a_start, &b_start);
		else
			return (KO);
	}
	else if (input[0] == 'p')
	{
		if (input[1] == 'a')
			command_solo_p(&b_start, &a_start);
		else if (input[1] == 'b')
			command_solo_p(&a_start, &b_start);
		else
			return (KO);
	}
	else if (input[0] == 'r')
		return (detect_input_data2(input, a_start, b_start));
	else
		return (KO);
	return (OK);
}

void		input_algo_command(t_data *a_start, t_data *b_start)
{
	char	*input;
	int		gnl_flag;
	int		detect_flag;

	gnl_flag = 10;
	detect_flag = OK;
	while (gnl_flag > 0 && detect_flag == OK)
	{
		gnl_flag = get_next_line(&input);
		if (input[0] != '\0')
		{
			if (gnl_flag >= 0)
				detect_flag = detect_input_data1(input, a_start, b_start);
		}
		else
			gnl_flag = 0;
		free(input);
	}
	if (detect_flag != OK)
		ft_error(a_start, b_start);
	result_of_checker(&a_start, &b_start);
}

void		check_start(t_data *a_start)
{
	int		flag;
	t_data	b_start;

	ft_lstreset(&b_start);
	is_can_split(&a_start);
	flag = is_available(&a_start);
	if (flag < 0)
		ft_error(a_start, NULL);
	input_algo_command(a_start, &b_start);
}

int			main(int count, char *data[])
{
	t_data	a_start;
	t_data	*temp;
	int		i;

	i = 0;
	ft_lstreset(&a_start);
	temp = &a_start;
	while (++i < count)
	{
		temp->next = ft_lstnew_chardata(ft_strdup(data[i]));
		temp = temp->next;
	}
	check_start(&a_start);
}
