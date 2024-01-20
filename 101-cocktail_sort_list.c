#include "sort.h"

/**
 * dll_adj_swap - swaps two adjacent nodes of a doubly linked list
 * @list: doubly linked list of integers to be sorted
 * @left: node closer to head, right->prev
 * @right: node closer to tail, left->next
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swap;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->prev = right;
	swap = right;
	left->next = right->next;
	swap->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using a cocktail shaker sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool forward_swapped, backward_swapped;
	int max_checks = 1000000, checks;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		forward_swapped = backward_swapped = false;

		for (checks = 0; temp->next && checks < max_checks; checks++)
		{
			if (temp->next->n < temp->n)
			{
				dll_adj_swap(list, temp, temp->next);
				forward_swapped = true;
			}
			else
				temp = temp->next;
		}

		if (!temp->next)  /* first loop, measuring list */
			max_checks = checks;

		if (forward_swapped)
			temp = temp->prev;

		max_checks--;

		for (checks = 0; temp->prev && checks < max_checks; checks++)
		{
			if (temp->n < temp->prev->n)
			{
				dll_adj_swap(list, temp->prev, temp);
				backward_swapped = true;
			}
			else
				temp = temp->prev;
		}

		if (backward_swapped)
			temp = temp->next;

	} while (forward_swapped || backward_swapped);
}
