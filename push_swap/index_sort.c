/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:32:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/06 20:18:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static	int *bubble_sort(int arr[], int n) 
{
    int sorted = 0; // Variable pour indiquer si le tableau est déjà trié
    for (int i = 0; i < n - 1; i++) {
        sorted = 1; // Supposons que le tableau est trié
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                sorted = 0; // Le tableau n'est pas encore trié
            }
        }
        // Si le tableau est déjà trié à ce stade, inutile de continuer
        if (sorted) {
            break;
        }
    }
    return arr;
}

t_stack *index_sort(t_stack *a) {
    int length = ft_llen(a);
    int *pos_to_sort = (int *)malloc(sizeof(int) * length);
    t_stack *tmp = a;

    // Copiez les données (pas les indices) dans un tableau temporaire
    int i = 0;
    while (tmp != NULL) {
        pos_to_sort[i] = tmp->data;
        tmp = tmp->next;
        i++;
    }

    // Triez le tableau des données
    bubble_sort(pos_to_sort, length);

    // Réaffectez les indices triés aux éléments de la liste en fonction de l'ordre trié des données
    tmp = a;
    for (i = 0; i < length; i++) {
        while (tmp != NULL && tmp->data != pos_to_sort[i]) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->index = i + 1; // Mettez à jour l'indice en fonction de la position triée
            tmp = a; // Réinitialisez tmp pour parcourir la liste depuis le début
        }
    }

    // Libérez la mémoire du tableau temporaire
    free(pos_to_sort);

    // Renvoyez la liste triée par les indices
    return a;
}
