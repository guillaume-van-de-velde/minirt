/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:46:50 by stde-la-          #+#    #+#             */
/*   Updated: 2023/08/12 02:46:06 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	randf()
{
	return ((float)rand() / RAND_MAX);
}

float	normal_randf()
{
	float	theta;
	float	rho;

	theta = 2 * M_PI * randf();
	rho = sqrtf(-2 * logf(randf()));
    return (rho * cos(theta));
}

t_vec	random_dir()
{
	return (normalize((t_vec){normal_randf(), normal_randf(), normal_randf()}));
}

t_vec	cosine_hemisphere_dir(t_vec *normal_dir)
{
	return (normalize(add(random_dir(), *normal_dir)));
}
