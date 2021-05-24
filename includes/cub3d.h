/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:34:29 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:50:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <float.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define FALSE 0
# define TRUE 1
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364

int		g_flag;

typedef struct	s_point
{
	float			x;
	float			y;
}				t_point;

typedef struct	s_ray
{
	float			angle;
	t_point			wall_hit;
	float			dist;
	int				top_pixel;
	int				bot_pixel;
	int				hit_vert;
	int				id;
}				t_ray;

typedef struct	s_map
{
	char			**tab;
	unsigned int	num_rows;
	unsigned int	num_cols;
}				t_map;

typedef struct	s_image
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_image;

typedef struct	s_player
{
	t_point			coord;
	int				turn_dir;
	int				walk_dir;
	int				trans_dir;
	float			rot_angle;
	float			rot_speed;
}				t_player;

typedef struct	s_texture
{
	void			*tex_ptr;
	char			*data;
	char			*file;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_texture;

typedef struct	s_sprite
{
	int				index;
	t_point			pos;
	float			dist;
	float			angle;
	int				is_vis;
	float			height;
	int				top_pixel;
	int				bot_pixel;
	float			first_x;

}				t_sprite;

typedef struct	s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	int				num_rays;
	t_image			image;
	int				f_color;
	int				c_color;

}				t_win;

typedef struct	s_all
{
	t_win			win;
	t_map			map;
	t_player		player;
	t_texture		tex[5];
	t_sprite		*tab_sprite;
	t_ray			*tab_rays;
	float			dist_pr;
	int				count;
	int				in_map;
}				t_all;

int				check_file(char const *name);
int				screenshot(t_all *game);
int				deal_key(int key, t_all *game);
int				release_key(int key, t_all *game);

void			init_all(t_all *game);

int				parse_line(char *line, t_all *game, t_list **list);
int				parse_tab(t_all *game, char *line, t_list **list);

int				color(t_all *game, char **tab);
int				parsing_color(const char *str);
int				get_pixel_color(t_image img, int x, int y);

int				parsing_resolution(t_all *game, char **tab);
int				check_resolution(t_all *game);

int				parsing_texture(t_all *game, char **tab);
int				is_texture(char **tab_line);
int				get_tex_color(t_texture tex, int x, int y);

int				scan_sprite(t_all *game);
int				valid_sprites(t_all *game);
float			sprite_angle(t_point sprite_pos, t_point player_pos,
				float player_rot_angle);
int				sprite_visible(float angle_sprite);
int				is_sprite_at(t_all *game, t_point pos);

int				map(t_all *game, t_list *list);
int				valid_map(t_all *game);
int				is_wall_at(t_all *game, t_point pos);
char			type_wall(t_all *game, t_point pos);

int				valid_player_pos(t_all *game);
void			update_player(t_all *game);

t_point			wall_hit_h(float ray_angle, t_all *game);
t_point			wall_hit_w(float ray_angle, t_all *game);

void			points(t_point *dst, t_point *src);
float			distance(t_point a, t_point b);

int				validation(t_all *game, t_list *list, int ret);
int				exit_game(t_all *game);

int				display(t_all *game);
void			cast_rays(t_all *game);
void			ft_mlx_pixel_put(t_win *win, int x, int y, int color);

void			free_map(t_map *map);
void			free_tab(char **tab);
void			free_sprite(t_all *game);
void			free_list(void *data);
void			free_full(t_all *game);
void			free_texture(t_win *win, t_texture texture[5]);

#endif
