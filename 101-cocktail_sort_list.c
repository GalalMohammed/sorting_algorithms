#include "sort.h"

/**
 * swap - swaps two nodes
 * @list: the head node of linked list
 * @node1: The first node
 * @node2: the second node
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev)
		prev->next = node2;
	else
		*list = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p, *last = NULL, *start = NULL;
	char swapped = 1;

	if (!list || (*list) == NULL || (*list)->next == NULL)
		return;


	while (swapped)
	{
		swapped = 0;
		p = *list;
		while (p->next != last)
		{
			if ((p->n) > (p->next->n))
			{
				swap(list, p, p->next);
				swapped = 1;
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		last = p;

		while (p->prev != start)
		{
			if ((p->n) < (p->prev->n))
			{
				swap(list, p->prev, p);
				swapped = 1;
				print_list(*list);
			}
			else
				p = p->prev;
		}
		start = p;
	}
}
