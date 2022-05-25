/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:02:45 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/05/25 21:44:44 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct fdf
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	read_map(char	*filename, t_fdf *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	bresenham_line(float x1, float y1, float x2, float y2, t_fdf *map);
void	draw(t_fdf *map);
void	trans2dinto3d(float *x, float *y, int z, t_fdf *map);
int		deal_key(int key, t_fdf *map);

#endif