/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 16:54:14 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/03/10 22:23:33 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len_s;

	c = (const char)c;
	len_s = ft_strlen(s);
	i = 0;
	if (c == 0)
		return ((char *)&s[len_s]);
	while (i < len_s)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	*str = '\0';
	if (len > 0)
	{	
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(str), s2);
	}
	free(s1);
	return (str);
}

char	*ft_strcpy(char *dst, char *src)
{
	unsigned int	len;

	len = ft_strlen(src);
	if (len >= 1)
	{
		dst[len] = '\0';
		while ((len) > 0)
		{
			len--;
			dst[len] = src[len];
		}
	}
	return (dst);
}
