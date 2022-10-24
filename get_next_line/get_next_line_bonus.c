/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:31:47 by sangyeki          #+#    #+#             */
/*   Updated: 2022/04/11 14:24:55 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*target;
	int			ret;

	target = 0;
	ret = 1;
	if (fd < 0 || BUFFER_SIZE == 0 || fd > 1024)
		return (0);
	if (ft_seek(buf[fd], '\n') != -1)
	{
		ft_cut_line(buf[fd], '\n');
		target = ft_strjoin(target, buf[fd]);
		if (target[0] == 0)
			target = ft_free(target);
	}
	while (ret > 0 && ft_seek(buf[fd], '\n') == -1)
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret <= 0)
			return (target);
		buf[fd][ret] = 0;
		target = ft_strjoin(target, buf[fd]);
	}
	return (target);
}
