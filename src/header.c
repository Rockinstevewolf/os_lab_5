#include "header.h"

typedef struct T
{
	unsigned long long l;
	unsigned long long r;
} T;

T T_crt(unsigned long long l, unsigned long long r){
	T data;
	data.l = l;
	data.r = r;
	return data;
}

typedef struct st
{
	T data;
	struct st *next;
} st;

//Вставка элемента на верх стека
st* push(T val, st *stack){
	st *element;
	element = (st*) malloc(sizeof(st));
	element->data = val;
	element->next = stack;
	return(element);
}
//Удаление элемента сверху
st* pop(st *stack){
	if (!stack){
		printf("\nНет элементов в списке\n");
		return(NULL);
	}
	else{
		st *next;
		next = stack->next;
		free(stack);
		return(next);
	}
}
//Длина списка
int length(st *stack){
	int length = 0;
	st *item;
	item = stack;
	while(item){
		length++;
		item = item->next;
	}
	return(length);
}
//Печать(1 элемента или всех)
void print_stack(st *stack){
	int i = 1;
	st *item;
	item = stack;
	if(!stack){
		printf("Stack is clear\n");
		return;
	}
	else{
		printf("From top: ");
		while(item){
			printf("%llX%llX", item->data.l, item->data.r);
			item = item->next;
			if(item != NULL)
				printf(" -> ");
			i++;
		}
		printf("\n");
	}
}

