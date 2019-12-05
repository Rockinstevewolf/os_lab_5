#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct T T;
T T_crt(unsigned long long l, unsigned long long r);

typedef struct st st;

//Вставка элемента на верх стека
st* push(T val, st *stack);

//Удаление элемента сверху
st* pop(st *stack);

//Длина списка
int length(st *stack);

//Печать
void print_stack(st *stack);
