/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:28:48 by ytran             #+#    #+#             */
/*   Updated: 2019/01/09 17:28:49 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack     *initStack(void)
{
   t_stack  *stack = malloc(sizeof(t_stack));

    if (!stack)
        return (NULL);
    stack->item = NULL;
    return (stack);
}

int                pop(struct s_stack *stack)
{
    int ret;
    struct s_item *tmp;

    if (isEmpty(stack))
        return (0);
    tmp = stack->item;
    ret = stack->item->idx;
    stack->item = stack->item->next;
    free(tmp);
    return (ret);
}

void                push(struct s_stack *stack, int idx)
{
    struct s_item *node = (struct s_item*)malloc(sizeof(struct s_item));

    if (!node)
        return ;
    node->idx = idx;
    node->next = stack->item;
    stack->item = node;
}   

int                 isEmpty(struct s_stack *stack)
{
    return ((stack->item == NULL) ? 1 : 0);
}

int                peek(struct s_stack *stack)
{
    return ((isEmpty(stack) == 1) ? 0 : stack->item->idx);
}

char *console(void)
{
    t_stack *stack = initStack();
    static char message[255];
    char *input = (char*)malloc(sizeof(char) * 26);
    int len = 0;
    int idx = 0;

    while (fgets(input, 255, stdin))
    {
        printf("?: ");

		if (!strncmp(input, "UNDO", 4))
		{
			if (peek(stack) != -1)
			{
				len = pop(stack);
		 		memset(message + len, '\0', 256 - len);
		 		idx = len;
		 	}
		 	else
		 		printf("There is no message to undo\n");
		}
		else if (!strncmp(input, "SEND", 4))
		{
			free(input);
			while (peek(stack))
				pop(stack);
			free(stack);
			return (message);
		}
		else
		{
			len = strlen(input);
			if (len > 1)
			{
				input[len] = 0;
				push(stack, idx);
				strncpy(&message[idx], input, len - 1);
				idx += len - 1;
				strncpy(&message[idx], " ", 1);
				idx++;
			}
		}
		printf("%s\n\n", message);
	}
	free(input);
	return (message);
}