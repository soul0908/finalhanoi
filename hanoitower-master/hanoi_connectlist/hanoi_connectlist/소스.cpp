#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ ��� ����ü
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// ����(ž) ����ü
typedef struct Stack {
	Node* top;
	char name; // ������ �̸��� �����ϱ� ���� �ʵ� �߰�
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* stack, char name) { // ���� �̸��� �ʱ�ȭ �Լ��� �߰�
	stack->top = NULL;
	stack->name = name; // ���� �̸� ����
}

// ���ÿ� ���Ҹ� �߰��ϴ� �Լ� (Push)
void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� �Լ� (Pop)
int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("Stack %c is empty\n", stack->name);
		return -1;
	}
	Node* temp = stack->top;
	int data = temp->data;
	stack->top = temp->next;
	free(temp);
	return data;
}

// �ϳ��� Ÿ�� ���� �ذ� �Լ�
void hanoi_tower(int n, Stack* from, Stack* tmp, Stack* to) {
	if (n == 1) {
		push(to, pop(from));
		printf("���� 1�� %c ���� %c���� �ű��.\n", from->name, to->name);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		push(to, pop(from));
		printf("���� %d�� %c ���� %c���� �ű��.\n", n, from->name, to->name);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

Stack stackA, stackB, stackC; // ���� ���� ����

int main(void) {
	initStack(&stackA, 'A'); // ���� �̸� ����
	initStack(&stackB, 'B');
	initStack(&stackC, 'C');

	// ���� A�� 3���� ������ �߰�
	push(&stackA, 3);
	push(&stackA, 2);
	push(&stackA, 1);

	// �ϳ��� Ÿ�� ���� �ذ� �Լ� ȣ��
	hanoi_tower(3, &stackA, &stackB, &stackC);

	return 0;
}
