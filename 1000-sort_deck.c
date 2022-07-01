#include "deck.h"
/**
 * aux_num_fun - turn into integer card value.
 * Description: as above.
 * @head_tmp1: pointer to the list.
 * Return: integer rep.
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
	int aux_num, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};
	/*
	 * @aux_num: dummy.
	 * @j: counter.
	 * @num: array numbers.
	 * @val: array with symbols.
	 */
	for (j = 0; j < 13; j++)
	{
		if (head_tmp1->card->value[0] == val[j])
			aux_num = num[j];
	}
	return (aux_num);
}
/**
 * num_sort - sorts a doubly linked list of integers, 4 stages.
 * Description: as above.
 * @list: pointer to the list head.
 * Return: no return.
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag = 0, i, aux_num1, aux_num2;
	unsigned int k;
	/*
	 * @head_tmp1: ptr to type, @head_tmp2: ptr to type.
	 * @aux1: ptr to type, @aux2: ptr to type.
	 * @flag: in zero, @i: counter, @aux_num1: aux, @aux_num2: aux.
	 * @k: counter.
	 */
	head_tmp1 = *list;
	head_tmp2 = *list;
	for (i = 0; i < 4; i++)
	{ k =  head_tmp1->card->kind;
		while (head_tmp1->next && head_tmp1->next->card->kind == k)
		{
			aux_num1 = aux_num_fun(head_tmp1);
			aux_num2 = aux_num_fun(head_tmp1->next);
			flag = 0;
			head_tmp2 = head_tmp1;
			while (head_tmp2 && head_tmp2->card->kind == k && aux_num1 > aux_num2)
			{
				aux1 = head_tmp2;
				aux2 = head_tmp2->next;
				aux1->next = aux2->next;
				if (aux2->next)
					aux2->next->prev = aux1;
				aux2->prev = aux1->prev;
				aux2->next = aux1;
				aux1->prev = aux2;
				if (aux2->prev)
					aux2->prev->next = aux2;
				head_tmp2 = aux2->prev;
				if (!aux2->prev)
					*list = aux2;
				flag = 1;
				if (!head_tmp2)
					break;
				aux_num1 = aux_num_fun(head_tmp2);
				aux_num2 = aux_num_fun(head_tmp2->next);
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort ailgorithm.
 * Description: as above.
 * @list: pointer to the list head.
 * Return: no return.
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag;
	/*
	 * @head_tmp1: ptr to type, @head_tmp2: ptr to type.
	 * @aux1: ptr to type, @aux2: ptr to type.
	 * @flag: int flag.
	 */
	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				flag = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->card->kind > head_tmp2->next->card->kind)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					flag = 1;
				}
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}
/**
 * sort_deck - sorts a deck of cards.
 * Description: as above.
 * @deck: pter to the deck.
 * Return: no return.
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
