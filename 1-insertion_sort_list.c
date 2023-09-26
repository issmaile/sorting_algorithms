#include "sort.h"

/**
 * swap_node - swap a node w the prev one
 * @node: node
 * @list: list of nodes
 * 
 * Return: return a pointer to the prev node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *pre = node->prev, *current = node;

	pre->next = current->next;
	if (current->next)
		current->next->prev = pre;
	current->next = pre;
	current->prev = pre->prev;
	pre->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
 * insertion_sort_list - sorts a double linked list of ints
 * in ascending order using Insertion sort algorithm
 * @list: doubly linked list to sort
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while (node->prev && node->prev->n > node->n)
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
