/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_p_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:10:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 15:29:41 by junhypar         ###   ########.fr       */
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
	struct s_data	*next;
}					t_data;

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
void				result_of_checker(t_data **a_start, t_data **b_start);
#endif
