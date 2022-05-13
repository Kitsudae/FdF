/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:59:26 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/05/07 21:57:23 by kvodorez      ########   odam.nl         */
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

void	fill_matrix(int *matrix_line, char	*line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		matrix_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_map(char	*filename, t_fdf *map)
{
	int		i;
	int		fd;
	char	*line;

	map->height = get_height(filename);
	map->width = get_width(filename);
	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i <= map->height)
	{
		map->matrix[i] = malloc(sizeof(int) * (map->width + 1));
		i++;
	}
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		fill_matrix(map->matrix[i], line);
		free(line);
		i++;
	}
	map->matrix[i] = NULL;
	//close(fd);
}
