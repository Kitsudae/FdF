/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:59:26 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/04/29 22:32:01 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	get_height(char *filename)
{
	int		fd;
	int		height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd) != NULL)
		height = height + 1;
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	read_map(char	*filename, t_fdf *map)
{
	map->height = get_height(filename);
	map->width = get_width(filename);
	printf("height:%d, width:%d", map->height, map->width);
}
