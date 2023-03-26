#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define Max_Size 10

typedef int ElemType;

typedef struct Stack {
	ElemType* data;
	int top;
}Stack;

void InitStack(Stack* p) {
	p->data = (ElemType*)malloc(sizeof(ElemType) * Max_Size);
	p->top = -1;
}
bool IsEmpty(Stack* p) {
	return p->top == -1;
}
bool IsFull(Stack* p) {
	return p->top == Max_Size - 1;
}
int Length(Stack* p) {
	return p->top + 1;
}
bool push(Stack* p, ElemType elem) {
	if (IsFull(p)) {
		perror("Õ»Âú£¡");
		return false;
	}
	p->data[++p->top] = elem;
	return true;
}
int pop(Stack* p) {
	if (IsEmpty(p)) {
		perror("Õ»¿Õ£¡");
	}
	return p->data[p->top--];
}
int main() {
	Stack stack;
	InitStack(&stack);
	assert(stack.top == -1);
	for (int i = 1; i <= 5; ++i) {
		push(&stack, i);
	}
	assert(Length(&stack) == 5);
	int popelem = pop(&stack);
	printf("µ¯³öÔªËØÎª%d\n", popelem);
}