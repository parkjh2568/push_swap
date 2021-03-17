/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_p_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:10:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 18:18:25 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_P_ALGO_H
# define C_P_ALGO_H
# include "./libft/libft.h"

typedef struct		s_data
{
	char			*num;
	struct s_data	*next;
}					t_data;

void				ft_lstreset(t_data *data);
void				ft_lstfree(t_data **lst);
int					ft_lstlen(t_data *data);
t_data				*ft_lstnew_chardata(char *data);
int					is_available(t_data *a_start);
void				ft_error(t_data *a_start, t_data *b_start);

void				command_solo_s(t_data **data);
void				command_solo_p(t_data **data1, t_data **data2);
void				command_solo_r(t_data **data);
#endif
