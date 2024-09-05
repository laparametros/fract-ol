/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuyucu <hkuyucu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:42:06 by hkuyucu           #+#    #+#             */
/*   Updated: 2023/06/14 10:46:21 by hkuyucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_pre_cal(t_data *data, int x, int y)
{
	data->var.a = ft_map(x, data->ox - data->zoom, data->ox + data->zoom);
	data->var.b = ft_map(y, data->oy - data->zoom, data->oy + data->zoom);
	if (!data->julia)
	{
		data->var.a_r = data->var.a;
		data->var.b_r = data->var.b;
	}
	data->var.num_it = 0;
}

//ft_calculater function to calculate the number of iterations for each pixel !
//and check if the complex number is in the set or not !
void	ft_calculater(t_data *data)
{
	while (data->var.num_it < data->max_it)
	{
		if (data->burning_ship)
			data->var.bb = fabs(2 * data->var.a * data->var.b);
		else
			data->var.bb = 2 * data->var.a * data->var.b;
		data->var.aa = data->var.a * data->var.a - data->var.b * data->var.b;
		data->var.a = data->var.aa + data->var.a_r;
		data->var.b = data->var.bb + data->var.b_r;
		data->var.num_it++;
		if (data->var.a * data->var.a + data->var.b * data->var.b > 4)
			break ;
	}
}

//ft_mlx_pixel_put function to put the pixel in the window !
//and give it a color !
void	ft_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*pixel;

	pixel = data.image.address + (y * data.image.line_length + x
			* (data.image.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

//ft_draw function to draw the fractal !
//and put it in the window !
void	ft_draw(t_data data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 600)
		{
			ft_pre_cal(&data, x, y);
			ft_calculater(&data);
			color = data.var.num_it * data.color;
			if (data.var.num_it == data.max_it)
				color = 0;
			ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(data.cnx, data.window);
	mlx_put_image_to_window(data.cnx, data.window, data.image.img, 0, 0);
}
