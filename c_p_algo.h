/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_p_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:10:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 14:54:06 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_P_ALGO_H
# define C_P_ALGO_H
# include "./libft/libft.h"

# define BUFFER_SIZE 1
# define OK 0
# define KO 1

typedef struct		s_data
{
	char			*num;
	long			lnum;
	long			index;
	struct s_data	*next;
}					t_data;

typedef struct		s_sort
{
	long			cnt;
	long			mid_cnt;
	long			thir1;
	long			thir2;
	long			small;
	long			s_cnt;
	long			big;
	long			b_cnt;
	long			mid;
	long			r_flag;
}					t_sort;

typedef struct		s_cnt
{
	long			max;
	long			remain;
}					t_cnt;

char				*gnl_strjoin(char *s1, char *s2);
int					get_next_line(char **line);

void				ft_lstreset(t_data *data);
void				ft_lstfree(t_data **lst);
int					ft_lstlen(t_data *data);
t_data				*ft_lstnew_chardata(char *data);
int					is_available(t_data **a_start);
void				ft_error(t_data *a_start, t_data *b_start);

void				command_solo_s(t_data **data);
void				command_solo_p(t_data **data1, t_data **data2);
void				command_solo_r(t_data **data);
void				command_solo_rr(t_data **data);
void				command_duo_s(t_data **data1, t_data **data2);
void				command_duo_r(t_data **data1, t_data **data2);
void				command_duo_rr(t_data **data1, t_data **data2);

void				print_data(t_data *a_start, t_data *b_start);
int					is_sorted(t_data *data_start);
int					is_rsorted(t_data *data_start);
void				result_of_checker(t_data **a_start, t_data **b_start);
void				is_can_split(t_data **a_start);

void				ft_full_sm_sort(t_data **a_start, t_data **b_start,
					t_sort *s_base);
void				ft_input_index(t_data **a_start, int cnt);
t_sort				*ft_find_big_small(t_data *a_start, int cnt);
void				ft_half_of_sort(t_data **a_start, t_data **b_start,
					t_sort *s_base, t_cnt *d_cnt);
void				ft_full_of_sort(t_data **a_start, t_data **b_start,
					t_sort *s_base);
void				ft_sort_process(t_data **a_start, t_data **b_start,
					t_sort *s_base);
void				ft_sort_b(t_data **a_start, t_data **b_start,
					t_sort *b_data);
void				ft_support_half_r(t_data **a, t_data **b, int *cnt);

void				half_of_sort(t_data **a, t_data **b, t_sort *base, t_cnt *d_cnt);

void				setting_big_small(t_data **a_start, int flag);

void				full_sort_support(t_data **a_start, int *flag, int big_small);
void				ft_full_of_rsort(t_data **a_start, t_data **b_start, 
					t_sort *s_base);

void				ft_thir_sort(t_data **a_start, t_data **b_start, t_sort *base, t_cnt **d_cnt);
#endif
