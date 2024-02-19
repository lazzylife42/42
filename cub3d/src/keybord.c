/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:26 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/19 21:57:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	player_move(int keysym, t_cube *cube)
// {
// 	if (keysym == K_ESC)
// 		on_destroy(cube);
// 	else if (keysym == K_A)
// 		rotate_left(cube);
// 	else if (keysym == K_D)
// 		rotate_right(cube);
// 	else if (keysym == K_W)
// 		move_front(cube);
// 	else if (keysym == K_S)
// 		move_back(cube);
// 	else if (keysym == K_LEFT_ARROW)
// 		move_left(cube);
// 	else if (keysym == K_UP_ARROW)
// 		move_up(cube);
// 	else if (keysym == K_DOWN_ARROW)
// 		move_down(cube);
// 	else if (keysym == K_RIGHT_ARROW)
// 		move_right(cube);
// 	// printf("Key : %d\n", keysym);
// 	frame_render(cube);
// 	return (0);
// }
void    key_init(t_cube *cube)
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
}

void    update_player(t_cube *cube)
{
	if (cube->key->k_esc == true)
		on_destroy(cube);
	else if (cube->key->k_a == true)
		rotate_left(cube);
	else if (cube->key->k_d == true)
		rotate_right(cube);
	else if (cube->key->k_w == true)
		move_front(cube);
	else if (cube->key->k_s == true)
		move_back(cube);
	else if (cube->key->k_left == true)
		move_left(cube);
	else if (cube->key->k_up == true)
		move_up(cube);
	else if (cube->key->k_down == true)
		move_down(cube);
	else if (cube->key->k_right == true)
		move_right(cube);
	else if (cube->key->k_enter == true)
	{
		cube->loadscreen = true;
		load_transition(cube);
	}
}

int keypress(int keysym, t_cube *cube)
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
	return (0);
}

int keyrelease(int keysym, t_cube *cube)
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
	return (0);
}
