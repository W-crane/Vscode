
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;

} LNode;

void init_list(LNode *l)
{
	l->next = NULL;
}

void print_list(LNode l)
{
	LNode move;
	printf("Elements:");
	move = l;
	while (move.next != NULL)
	{
		move = *(move.next);
		printf("%d  ", move.data);
	}
	printf("\n");
}

int add_back(LNode *l, int num)
{
	LNode *new_node, *move;
	move = l;
	while (move->next != NULL)
	{
		move = move->next;
	}
	new_node = (LNode *)malloc(sizeof(LNode));
	move->next = new_node;
	new_node->data = num;
	new_node->next = NULL;
	return num;
}

int add_head(LNode *l, int num)
{
	LNode *new_node;
	new_node = (LNode *)malloc(sizeof(LNode));
	new_node->next = l->next;
	l->next = new_node;
	new_node->data = num;
	return num;
}

int insert_by_loc(LNode *l, int loc, int num)
{
	LNode *new_node, *move = l;
	new_node = (LNode *)malloc(sizeof(LNode));
	new_node->data = num;

	for (int i = 1; i < loc; i++)
	{
		if (move->next == NULL)
			return 0;
		move = move->next;
	}

	new_node->next = move->next;
	move->next = new_node;
	return loc;
}

int search_by_loc(LNode l, int loc)
{
	LNode move;
	move = l;
	if (loc < 1)
		return -1;
	for (int i = 1; i <= loc; i++)
	{
		if (move.next == NULL)
			return -1;
		move = *(move.next);
	}
	return move.data;
}

void sort_list(LNode *l)
{
	if (l->next == NULL)
		return;
	LNode *move_fro, *move, *max_node, *max_fro, *head = l;
	int max;
	while (head->next != NULL)
	{
		max = head->next->data;
		move_fro = head;
		max_fro = head;
		move = head->next;
		max_node = head->next;
		while (move != NULL)
		{
			if (move->data > max)
			{
				max_node = move;
				max_fro = move_fro;
				max = move->data;
			}
			move = move->next;
			move_fro = move_fro->next;
		}
		max_fro->next = max_node->next;
		max_node->next = head->next;
		head->next = max_node;
		head = max_node;
	}
}

int search_by_num(LNode l, int num)
{
	LNode move;
	int loc = 0;
	move = l;
	if (move.next == NULL)
		return 0;
	while (1)
	{
		move = *(move.next);
		loc++;
		if (move.data == num)
			break;
		if (move.next == NULL)
			return -1;
	}

	return loc;
}

int del_by_loc(LNode *l, int loc)
{
	if (loc < 1)
		return 0;

	LNode *move;
	int deled_num;

	move = l;

	for (int i = 1; i < loc; i++)
	{
		if (move->next == NULL)
			return 0;
		move = move->next;
	}

	deled_num = move->next->data;
	move->next = move->next->next;
	return deled_num;
}

int del_by_num(LNode *l, int num)
{
	LNode *move;
	int loc = 0;
	move = l;
	if (move->next == NULL)
		return 0;
	while (1)
	{
		loc++;
		if (move->next->data == num)
			break;
		if (move->next->next == NULL)
			return -1;

		move = move->next;
	}
	move->next = move->next->next;
	return loc;
}

int change_by_loc(LNode *l, int loc, int num)
{
	if (loc < 1)
		return 0;

	LNode *move = l;
	int changed_num;
	for (int i = 1; i <= loc; i++)
	{
		if (move->next == NULL)
			return 0;
		move = move->next;
	}
	changed_num = move->data;
	move->data = num;
	return changed_num;
}

int change_by_num(LNode *l, int num1, int num2)
{
	LNode *move;
	int loc = 0;
	move = l;
	if (move->next == NULL)
		return 0;
	while (1)
	{
		move = move->next;
		loc++;
		if (move->data == num1)
			break;
		if (move->next == NULL)
			return -1;
	}
	move->data = num2;
	return loc;
}

int main(int argc, char const *argv[])
{
	LNode l;
	init_list(&l);
	add_back(&l, 1);
	add_back(&l, 3);
	add_back(&l, 2);
	add_back(&l, 4);
	add_back(&l, 8);
	add_back(&l, 7);
	add_back(&l, 6);
	add_back(&l, 9);
	sort_list(&l);
	print_list(l);
	return 0;
}
