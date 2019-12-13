#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "head.h"

typedef struct T
{
	unsigned long long l;
	unsigned long long r;
} T;


int main()
{
	void *libHandle = dlopen("./libhead.so", RTLD_LAZY);
	if (!libHandle)
	{
	    printf("%s\n", dlerror());
	    exit(EXIT_FAILURE);
	}

	T (*T_crt) (unsigned long long, unsigned long long) = dlsym(libHandle, "T_crt");
	if (!T_crt)
	{
	    printf("%s\n", dlerror());
	    exit(EXIT_FAILURE);
	}

	st* (*push) (T, st*) = dlsym(libHandle, "push");
	if (!push){
	    printf("%s\n", dlerror());
	    exit(EXIT_FAILURE);
	}
	st* (*pop) (st*) = dlsym(libHandle, "pop");
	if (!pop){
	    printf("%s\n", dlerror());
	    exit(EXIT_FAILURE);
	}
	void (*print_stack) (st*) = dlsym(libHandle, "print_stack");
	if (!print_stack){
	    printf("%s\n", dlerror());
	    exit(EXIT_FAILURE);
	}


	st *start = NULL;

	start = push(T_crt(0x1BC29B36F623BA82,0xAAF6724FD3B16718),start);
	start = push(T_crt(0xC93D3BF7A7C4AFE9,0x4B64E30C2CE39F4F),start);
	start = push(T_crt(0xD41D8CD98F00B204,0xE9800998ECF8427E),start);
	print_stack(start);

	start = pop(start);
	print_stack(start);

	while(start != NULL)
		start = pop(start);
	print_stack(start);

    return 0;
}
