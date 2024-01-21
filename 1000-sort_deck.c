#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - compare two strings
 * @str1: string
 * @str2: string
 * Return: 1 if str1 and str2 are equal, 0 otherwise
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

	if (str1 == NULL)
		return (0);

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}

	if (str1[i] == '\0' && str2[i])
		return (0);

	return (1);
}

/**
 * get_card_position - return the position based on the card
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(const deck_node_t *node)
{
	int value;

	value = node->card->value[0] - '0';

	if (value < 2 || value > 9)
	{
		if (_strcmp(node->card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp(node->card->value, "10") == 1)
			value = 10;
		else if (_strcmp(node->card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp(node->card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp(node->card->value, "King") == 1)
			value = 13;
	}

	value += node->card->kind * 13;
	return (value);
}

/**
 * swap_card - swap a card for its previous one
 * @card: card
 * @deck: card deck
 * Return: return a pointer to a card which was entered
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;

	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;

	/* Update the next node's previous pointer */
	if (back->next)
		back->next->prev = back;

	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Double linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *node, *temp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	node = (*deck)->next;

	while (node != NULL)
	{
		temp = node;

		while (temp->prev != NULL && get_card_position(temp->prev) > get_card_position(temp))
		{
			temp = swap_card(temp, deck);
		}

		node = node->next;
	}
}

/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
