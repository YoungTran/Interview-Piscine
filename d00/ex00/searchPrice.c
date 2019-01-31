/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:30:53 by ytran             #+#    #+#             */
/*   Updated: 2019/01/07 11:30:54 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int  searchPrice(struct s_art **arts, char *name)
{
    int i = -1;

    while (arts[++i])
        if (!strcmp(arts[i]->name, name))
            return (arts[i]->price);
    return (-1);
}