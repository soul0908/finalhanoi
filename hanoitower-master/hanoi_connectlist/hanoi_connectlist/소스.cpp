#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 노드 구조체
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 스택(탑) 구조체
typedef struct Stack {
	Node* top;
	char name; // 스택의 이름을 저장하기 위한 필드 추가
} Stack;

// 스택 초기화 함수
void initStack(Stack* stack, char name) { // 스택 이름을 초기화 함수에 추가
	stack->top = NULL;
	stack->name = name; // 스택 이름 설정
}

// 스택에 원소를 추가하는 함수 (Push)
void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

// 스택에서 원소를 제거하고 반환하는 함수 (Pop)
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

// 하노이 타워 문제 해결 함수
void hanoi_tower(int n, Stack* from, Stack* tmp, Stack* to) {
	if (n == 1) {
		push(to, pop(from));
		printf("원판 1을 %c 에서 %c으로 옮긴다.\n", from->name, to->name);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		push(to, pop(from));
		printf("원판 %d을 %c 에서 %c으로 옮긴다.\n", n, from->name, to->name);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

Stack stackA, stackB, stackC; // 전역 스택 선언

int main(void) {
	initStack(&stackA, 'A'); // 스택 이름 설정
	initStack(&stackB, 'B');
	initStack(&stackC, 'C');

	// 스택 A에 3개의 원판을 추가
	push(&stackA, 3);
	push(&stackA, 2);
	push(&stackA, 1);

	// 하노이 타워 문제 해결 함수 호출
	hanoi_tower(3, &stackA, &stackB, &stackC);

	return 0;
}
