/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:12:32 by ytran             #+#    #+#             */
/*   Updated: 2019/01/09 15:12:33 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverseV2(struct s_node *lst)
{
    t_stack *stack = stackInit();
    
    if (!stack)
        return ;
    struct s_node *tmp = lst;
    while (tmp)
    {
        push(stack, tmp->word);
        tmp = tmp->next;
    }
    while (peek(stack))
    {
        printf("%s", pop(stack));
        if (peek(stack))
            printf(" ");
    }
}

struct s_stack     *stackInit(void)
{
   t_stack  *stack = malloc(sizeof(t_stack));

    if (!stack)
        return (NULL);
    stack->item = NULL;
    return (stack);
}

void                *pop(struct s_stack *stack)
{
    void *ret;
    struct s_item *tmp;

    if (isEmpty(stack))
        return (NULL);
    tmp = stack->item;
    ret = stack->item->word;
    stack->item = stack->item->next;
    free(tmp);
    return (ret);
}

void                push(struct s_stack *stack, char *word)
{
    struct s_item *node = (struct s_item*)malloc(sizeof(struct s_item));

    if (!node)
        return ;
    node->word = word;
    node->next = stack->item;
    stack->item = node;
}   

int                 isEmpty(struct s_stack *stack)
{
    return ((stack->item == NULL) ? 1 : 0);
}

void                *peek(struct s_stack *stack)
{
    return ((isEmpty(stack) == 1) ? NULL : stack->item->word);
}