/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_p_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:10:55 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/17 16:25:14 by junhypar         ###   ########.fr       */
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

void				ft_lstfree(t_data **lst);
t_data				*ft_lstnew_chardata(char *data);
#endif
