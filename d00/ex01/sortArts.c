/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:44:16 by ytran             #+#    #+#             */
/*   Updated: 2019/01/07 14:44:17 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

 int myCompare(const void* a, const void *b)
{
    struct s_art *x = *(struct s_art **)a;
    struct s_art *y = *(struct s_art **)b;

    return strcmp ((const char *)x->name, (const char *)y->name);
}


void  sortArts(struct s_art **arts)
{
    int i = -1;

    while (arts[++i])
        ;
    qsort(arts, i, sizeof (struct arts *), &myCompare);
}