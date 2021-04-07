/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:00:27 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 10:24:34 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

char			*gnl_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*out;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(out = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy(out, s1, len1 + 1);
	free(s1);
	ft_strlcpy(out + len1, s2, len2 + 1);
	return (out);
}
