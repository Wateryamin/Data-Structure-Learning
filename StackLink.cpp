#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;

typedef struct LinkStack {
	Node* top;
	int size;
}LinkStack;

void InitLinkStack(LinkStack* p) {
	p->top = NULL;
	p->size = 0;
}

bool IsEmpty(LinkStack p) {
	return p.size == 0;	
}

bool push(LinkStack* p,ElemType elem) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = elem;
	newnode->next = p->top;
	p->top = newnode;
	p->size++;
	return true;
}

ElemType pop(LinkStack* p) {
	if (p->size == 0) {
		perror("Õ»¿Õ!");
	}
	ElemType cur = p->top->data;
	p->top = p->top->next;
	p->size--;
	return cur;
}
void print(LinkStack stack){
	while (stack.top != NULL) {
		printf("%d ", stack.top->data);
		stack.top = stack.top->next;
	}
	printf("\n");
}
int main() {
	LinkStack Stack;
	InitLinkStack(&Stack);
	assert(IsEmpty(Stack) == 1);
	for (int i = 1; i <= 5; ++i) {
		push(&Stack, i);
	}
	print(Stack);
	int cur = pop(&Stack);
	print(Stack);
	return 0;
}
