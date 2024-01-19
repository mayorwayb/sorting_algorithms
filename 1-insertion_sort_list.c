#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new;

	if (!list || !(*list) || !((*list)->next))
		return;

	lead = (*list)->next;

	while (lead)
	{
		new = lead->next;

		follow = lead->prev;

		while (follow && lead->n < follow->n)
		{
			swap_nodes(list, follow, lead);
			print_list(*list);
			follow = lead->prev;
		}

		lead = new;
	}
}
