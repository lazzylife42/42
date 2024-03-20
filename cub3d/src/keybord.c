/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:26 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 20:14:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_init(t_cube *cube)
{
	cube->key = malloc(sizeof(t_key));
	cube->key->k_esc = false;
	cube->key->k_a = false;
	cube->key->k_d = false;
	cube->key->k_w = false;
	cube->key->k_s = false;
	cube->key->k_left = false;
	cube->key->k_up = false;
	cube->key->k_down = false;
	cube->key->k_right = false;
	cube->key->k_enter = false;
	cube->key->k_o = false;
	cube->key->k_m = false;
	cube->map->mini_map = false;
}

static void	menu(t_cube *cube)
{
	if (cube->key->k_enter == true && cube->loadscreen == false)
	{
		cube->loadscreen = true;
		load_transition(cube);
	}
	if (cube->key->k_m == true && cube->map->mini_map == true)
		cube->map->mini_map = false;
	else if (cube->key->k_m == true && cube->map->mini_map == false)
		cube->map->mini_map = true;
}

void	update_player(t_cube *cube)
{
	if (cube->key->k_esc == true)
		on_destroy(cube);
	if (cube->key->k_a == true)
		move_left(cube);
	else if (cube->key->k_d == true)
		move_right(cube);
	if (cube->key->k_w == true)
		move_front(cube);
	else if (cube->key->k_s == true)
		move_back(cube);
	if (cube->key->k_left == true)
		rotate_left(cube);
	else if (cube->key->k_right == true)
		rotate_right(cube);
	if (cube->key->k_up == true)
		rotate_up(cube);
	else if (cube->key->k_down == true)
		rotate_down(cube);
	else if (cube->key->k_o == true)
		handle_door(cube);
	else if (cube->key->k_enter == true || cube->key->k_m == true)
		menu(cube);
}

int	keypress(int keysym, t_cube *cube)
{
	if (keysym == K_ESC)
		cube->key->k_esc = true;
	else if (keysym == K_ENTER)
		cube->key->k_enter = true;
	else if (keysym == K_A)
		cube->key->k_a = true;
	else if (keysym == K_D)
		cube->key->k_d = true;
	else if (keysym == K_W)
		cube->key->k_w = true;
	else if (keysym == K_S)
		cube->key->k_s = true;
	else if (keysym == K_LEFT_ARROW)
		cube->key->k_left = true;
	else if (keysym == K_UP_ARROW)
		cube->key->k_up = true;
	else if (keysym == K_DOWN_ARROW)
		cube->key->k_down = true;
	else if (keysym == K_RIGHT_ARROW)
		cube->key->k_right = true;
	else if (keysym == K_M)
		cube->key->k_m = true;
	else if (keysym == K_O)
		cube->key->k_o = true;
	return (0);
}

int	keyrelease(int keysym, t_cube *cube)
{
	if (keysym == K_ESC)
		cube->key->k_esc = false;
	else if (keysym == K_ENTER)
		cube->key->k_enter = false;
	else if (keysym == K_A)
		cube->key->k_a = false;
	else if (keysym == K_D)
		cube->key->k_d = false;
	else if (keysym == K_W)
		cube->key->k_w = false;
	else if (keysym == K_S)
		cube->key->k_s = false;
	else if (keysym == K_LEFT_ARROW)
		cube->key->k_left = false;
	else if (keysym == K_UP_ARROW)
		cube->key->k_up = false;
	else if (keysym == K_DOWN_ARROW)
		cube->key->k_down = false;
	else if (keysym == K_RIGHT_ARROW)
		cube->key->k_right = false;
	else if (keysym == K_M)
		cube->key->k_m = false;
	else if (keysym == K_O)
		cube->key->k_o = false;
	return (0);
}
