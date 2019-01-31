/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:02:03 by ytran             #+#    #+#             */
/*   Updated: 2019/01/09 15:02:04 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
    if (lst->next)
    {
        printReverse(lst->next);
        printf(" ");
    }
    if (lst)
        printf("%s", lst->word);
}