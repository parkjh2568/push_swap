/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:11:02 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/18 10:26:29 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c_p_algo.h"

int		ft_config(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-22);
}

void	print_line(char **out, char **line, int i)
{
	int		j;
	char	*s;

	(*out)[i] = '\0';
	*line = ft_strdup(*out);
	j = ft_strlen(*out + i + 1);
	if (j == 0)
	{
		free(*out);
		*out = 0;
	}
	else
	{
		s = ft_strdup(*out + i + 1);
		free(*out);
		*out = s;
	}
}

int		final_print(char **out, char **line, int i)
{
	if (i < 0)
		return (-1);
	if (*out && (ft_config(*out) >= 0))
	{
		print_line(out, line, ft_config(*out));
		return (1);
	}
	else if (*out)
	{
		*line = *out;
		*out = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*out;
	int			count;
	int			i;

	if (BUFFER_SIZE <= 0)
		return (-1);
	while ((count = read(0, buff, BUFFER_SIZE)) > 0)
	{
		buff[count] = '\0';
		out = gnl_strjoin(out, buff);
		if ((i = ft_config(out)) >= 0)
		{
			print_line(&out, line, i);
			return (1);
		}
	}
	return (final_print(&out, line, count));
}
