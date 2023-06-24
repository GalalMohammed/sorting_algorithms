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
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p;

	if (!list || (*list) == NULL || (*list)->next == NULL)
		return;

	p = (*list)->next;
	while (p)
	{
		int key = p->n;

		while (p->prev && key < p->prev->n)
		{
			swap(list, p->prev, p);
			print_list(*list);
		}
		p = p->next;
	}
}
