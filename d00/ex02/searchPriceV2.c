/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:00:42 by ytran             #+#    #+#             */
/*   Updated: 2019/01/07 16:00:43 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <string.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
    int l = 0;
    int r = n - 1;
    int m;

    while (l <= r)
    {
        m = floor((l + r) / 2);
        if (!strcmp(arts[m]->name, name))
            return (arts[m]->price);
        else if (strcmp(arts[m]->name, name) < 0)
            l = m + 1;
        else
            r = m - 1;
    }
    return (-1);
}