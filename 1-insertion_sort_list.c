#include "sort.h"

/**
* insertion_sort_list - sorts a list using insertion alg.
* @list: list to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list((const listint_t *)*list);
		}
		current = next_node;
	}
}

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list.
 * @list: pointer to the head of the list.
 * @node1: first node to swap.
 * @node2: second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t
*node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
