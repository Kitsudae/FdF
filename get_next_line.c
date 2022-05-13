/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 18:49:01 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/04/28 21:15:39 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*get_remainder(char *saved_line)
{
	char	*p_n;
	char	*remainder;
	int		counter;
	char	*tmp;

	counter = 0;
	p_n = ft_strchr(saved_line, '\n');
	if (!p_n)
		return (NULL);
	tmp = malloc(ft_strlen(p_n));
	if (!tmp)
		return (ft_free(saved_line));
	p_n++;
	while (*p_n)
	{
		*tmp = *p_n;
		p_n++;
		tmp++;
		counter++;
	}
	*tmp = '\0';
	remainder = tmp;
	free(saved_line);
	return (&remainder[-counter]);
}

char	*trim_line(char *saved_line)
{
	char	*cut_line;
	int		i;

	i = 0;
	if (ft_strchr(saved_line, '\n') == NULL)
		return (saved_line);
	while ((saved_line[i] != '\0') && (saved_line[i] != '\n'))
		i++;
	cut_line = malloc(i + 2);
	if (!cut_line)
		return (NULL);
	while ((*saved_line) && (*saved_line != '\n'))
	{
		*cut_line = *saved_line;
		saved_line++;
		cut_line++;
	}
	if (*saved_line == '\n')
		*cut_line++ = '\n';
	*cut_line = '\0';
	return (&cut_line[-i - 1]);
}

char	*read_full_line(int fd, char *saved_line, char *buff)
{
	int		nbytesread;
	char	*tmp;

	nbytesread = 1;
	while (nbytesread > 0)
	{
		nbytesread = read(fd, buff, BUFFER_SIZE);
		if (nbytesread < 0)
			return (NULL);
		buff[nbytesread] = '\0';
		if (!saved_line)
			saved_line = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(saved_line, buff);
			saved_line = tmp;
		}
		if (!saved_line)
			return (NULL);
		if (ft_strchr(saved_line, '\n'))
			break ;
	}
	if (saved_line[0] == '\0')
		return (ft_free(saved_line));
	return (saved_line);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*saved_line;
	char			*cut_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	saved_line = read_full_line(fd, saved_line, buff);
	if (!saved_line)
		return (NULL);
	cut_line = trim_line(saved_line);
	saved_line = get_remainder(saved_line);
	return (cut_line);
}
