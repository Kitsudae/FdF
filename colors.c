/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 21:29:40 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/06/16 21:54:58 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	get_r(int color)
{
	int	r_value;

	r_value = color >> 16;
	return (r_value);
}

int	get_g(int color)
{
	int	g_value;

	g_value = (color >> 8) & 0xFF;
	return (g_value);
}

int	get_b(int color)
{
	int	b_value;

	b_value = color & 0xFF;
	return (b_value);
}

int	get_rgb(int r_value, int g_value, int b_value)
{
	int	color;

	color = (r_value << 16) + (g_value << 8) + b_value;
	return (color);
}

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	r_delta;
	double	g_delta;
	double	b_delta;
	int		new_rgb[3];
	int		newcolor;

	r_delta = (double)((get_r(endcolor)) - (get_r(startcolor))) / (double)len;
	g_delta = (double)((get_g(endcolor)) - (get_g(startcolor))) / (double)len;
	b_delta = (double)((get_b(endcolor)) - (get_b(startcolor))) / (double)len;
	new_rgb[0] = (get_r(startcolor)) + ft_round(pix * r_delta);
	new_rgb[1] = (get_g(startcolor)) + ft_round(pix * g_delta);
	new_rgb[2] = (get_b(startcolor)) + ft_round(pix * b_delta);
	newcolor = RGB(new_rgb[0], new_rgb[1], new_rgb[2]);
	return (newcolor);
}
