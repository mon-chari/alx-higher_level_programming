#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: double pointer
 * @number: number to be inserted to the list
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *prev;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = number;
	new->next = NULL;

	if (*head == NULL || ((*head)->n > number))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		current = *head;
		prev = NULL;

		while (current != NULL && current->n < number)
		{
			prev = current;
			current = current->next;
		}
		new->next = current;
		prev->next = new;
	}
	return (new);
}
