/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:15:46 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:47:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		fill_ray(t_ray *ray, float dist, t_point wall, float angle)
{
	ray->dist = dist;
	ray->wall_hit = wall;
	ray->angle = angle;
}

static void		ray_d(t_ray *ray)
{
	if (ray->hit_vert)
	{
		if (!(ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI))
			ray->id = 1;
		else
			ray->id = 3;
	}
	else
	{
		if (!((ray->angle > 0) && (ray->angle < M_PI)))
			ray->id = 0;
		else
			ray->id = 2;
	}
}

static void		typ_ray(t_all *game, t_ray *ray, int vert)
{
	t_point		touch;

	touch = ray->wall_hit;
	ray->hit_vert = vert;
	if (vert && (!(ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)))
		touch.x -= 1.0;
	if (!vert && (!((ray->angle > 0) && (ray->angle < M_PI))))
		touch.y -= 1.0;
	if (type_wall(game, touch) == '1')
	{
		ray_d(ray);
	}
	else
		ray->id = 4;
}

static t_ray	wall_hit(float ray_angle, t_all *game)
{
	float		hit_dist_w;
	float		hit_dist_h;
	t_point		wall_cord_h;
	t_point		wall_cord_w;
	t_ray		ray;

	ray_angle = fmod(ray_angle, (2 * M_PI));
	while (ray_angle < 0)
		ray_angle += 2 * M_PI;
	wall_cord_h = wall_hit_h(ray_angle, game);
	wall_cord_w = wall_hit_w(ray_angle, game);
	hit_dist_h = distance(game->player.coord, wall_cord_h);
	hit_dist_w = distance(game->player.coord, wall_cord_w);
	if (hit_dist_w < hit_dist_h)
	{
		fill_ray(&ray, hit_dist_w, wall_cord_w, ray_angle);
		typ_ray(game, &ray, TRUE);
	}
	else
	{
		fill_ray(&ray, hit_dist_h, wall_cord_h, ray_angle);
		typ_ray(game, &ray, FALSE);
	}
	return (ray);
}

void			cast_rays(t_all *game)
{
	float		ray_angle;
	int			i;

	i = 0;
	while (i < game->win.num_rays)
	{
		ray_angle = game->player.rot_angle +
		atan((i - game->win.num_rays / 2) / game->dist_pr);
		game->tab_rays[i] = wall_hit(ray_angle, game);
		i++;
	}
}
