#include <stdlib.h>
#include <stdio.h>
#include "header.h"

typedef struct T
{
	unsigned long long l;
	unsigned long long r;
} T;

st* free_st(st *stack){
	while(stack != NULL)
		stack = pop(stack);
}

int main()
{
	st *start = NULL;

	start = push(T_crt(0x1BC29B36F623BA82,0xAAF6724FD3B16718),start);
	
	start = push(T_crt(0xC93D3BF7A7C4AFE9,0x4B64E30C2CE39F4F),start);

	start = push(T_crt(0xD41D8CD98F00B204,0xE9800998ECF8427E),start);

	print_stack(start);

	start = free_st(start);

	print_stack(start);

    return 0;
}
