/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuyucu <hkuyucu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:41:42 by hkuyucu           #+#    #+#             */
/*   Updated: 2023/06/14 12:11:12 by hkuyucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_var
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	a_r;
	double	b_r;
	int		num_it;
}			t_var;

typedef struct s_data
{
	void	*cnx;
	void	*window;
	t_image	image;
	t_var	var;
	double	zoom;
	double	ox;
	double	oy;
	int		max_it;
	int		color;
	int		color_code;
	int		julia;
	int		julia_move;
	int		burning_ship;
}			t_data;

double		ft_map(int in, double min, double max);
void		ft_pre_cal(t_data *data, int x, int y);
void		ft_calculater(t_data *data);
void		ft_mlx_pixel_put(t_data data, int x, int y, int color);
void		ft_draw(t_data data);
void		ft_get_color(t_data *data);
int			ft_atoi(char *num);
void		ft_get_color(t_data *data);
void		ft_key_hook2(t_data *data, int keycode);
int			ft_key_hook(int keycode, void *param);
void		ft_mouse_zoom(t_data *data, int button, int x, int y);
int			ft_mouse_hook(int button, int x, int y, void *param);
void		ft_instructions(void);
int			ft_close(t_data *data);
void		julia_args(char **av);
double		ft_atof(char *str, double res);

#endif
