/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:16:38 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/04/15 18:10:00 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_fdf	*map;
	char	*filename;

	filename = "test_maps/10-2.fdf";
	map = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(filename, map);
}
