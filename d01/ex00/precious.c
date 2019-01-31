/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:20:03 by ytran             #+#    #+#             */
/*   Updated: 2019/01/08 22:20:04 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node *new_node(char c)
{
    t_node *new = (t_node*)malloc(sizeof(t_node));

    if (!new)
        return (NULL);
    new->c = c;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

t_node *make_list(const char *s)
{
    t_node *head = new_node(*s);
    t_node *pitr;
    t_node *itr;
    static int i = 0;
    int len = strlen(s);

    if (i < len)
    {
        head = new_node(s[i]);
        pitr = head;
        itr = head;
        i++;
    }
    while (i < len)
    {
        itr = new_node(s[i]);
        pitr->next = itr;
        itr->prev = pitr;
        pitr = itr;
        i++;
    }
    if (len > 0)
    {
        itr->next = head;
        head->prev = itr;
    }
    return (head);
}

char *precious(int *text, int size)
{
    static char ret[512];
    t_node *list;
    int i = 0;
    int j = 0;

    list = make_list(CS);
    if (!size)
        return (NULL);
    while (i < size)
    {
        if (text[i] >= 0)
        {
            while (text[i] != 0)
            {
                list = list->next;
                text[i]--;
            }
        }
        else
        {
            while (text[i] != 0)
            {
                list = list->prev;
                text[i]++;  
            }
        }
        ret[j++] = list->c; 
        i++;
    }
    ret[j] = '\n';
    return (ret);
}