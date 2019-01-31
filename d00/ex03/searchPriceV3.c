/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:19:28 by ytran             #+#    #+#             */
/*   Updated: 2019/01/07 21:19:29 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_dict *dict, char *name)
{
    struct s_art *search;

    if (dict && name && (search = dictSearch(dict, name)))
		return (search->price);
    return (-1);
}

size_t hash(char *input)
{
    int i = -1;
    long long index = 0;
    while (input[++i])
        index += input[i];
    return ((size_t)(index % i));
}

struct s_dict *dictInit(int capacity)
{
    int i = -1;

    struct s_dict *newDict = (struct s_dict*)malloc(sizeof(struct s_dict));

    if (!newDict)
    {
        free(newDict);
        return (NULL);
    }
    if (capacity < 1)
    {
        free(newDict);
        return (NULL);
    }
    newDict->capacity = capacity;
    newDict->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
    if (!newDict->items)
    {
        free(newDict);
        return (NULL);
    }
    else
        while (++i < capacity)
            newDict->items[i] = NULL;
    return (newDict);
}


struct s_item	*itemInit(char *key, struct s_art *value)
{
	struct s_item	*newItem = (struct s_item *)malloc(sizeof(struct s_item));

	if (!newItem)
		return NULL;
	newItem->key = key;
	newItem->value = value;
	newItem->next = NULL;
	return (newItem);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item		*newItem;
	struct s_item		*itr;
	size_t				idx;

	if (dict && key && value)
	{
		newItem = itemInit(key, value);
		if (!newItem)
			return (-1);

		idx = hash(key);
		//Iterate to last LL item and append
		if (dict->items[idx])
		{
			itr = dict->items[idx];

			while (itr->next)
				itr = itr->next;
			itr->next = newItem;
		}
		else //Assign that array value with newItem
			dict->items[idx] = newItem;

		//Assumedly return the hash ID
		return (idx);
	}
	//Unsuccessful inserted
	return (-1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*itr;
	size_t			idx;

	if (dict && key)
	{
		idx = hash(key);

		if (dict->items[idx])
		{
			itr = dict->items[idx];

			while (itr)
			{
				if (!strcmp(itr->key, key))
					return (itr->value);
				itr = itr->next;
			}
		}
	}
	//Error or not found
	return (NULL);
}