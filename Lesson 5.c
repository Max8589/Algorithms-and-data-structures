
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char

typedef struct Node {
    T data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int size;
} Stack;

int pushStack(Stack *st, T value) {
    Node *temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) return 0;
    
    temp->data = value;
    temp->next = st->head;
    
    st->head = temp;
    st->size++;
    return 1;
}

T popStack(Stack *st) {
    if (st->size == 0)
        return -1;
    
    Node* temp = st->head;
    T result = st->head->data;
    st->head = st->head->next;
    st->size--;
    free(temp);
    return result;
}

//1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
void decToBinStack(int numberDec, Stack *numberBin) {
    numberBin->size = 0;
    numberBin->head = NULL;
    while (numberDec != 0) {
        if (numberDec % 2)
            pushStack(numberBin, '1');
        else
            pushStack(numberBin, '0');
        numberDec /= 2;
    }
}

//2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(])
//для скобок [,(,{.
//Например: (2+(2*2)) или [2/{5*(4+7)}]
int checkBrackets(char exp[64]) {
    Stack s;
    s.size = 0;
    s.head = NULL;
    int i = 0;
    int count = 0;
    
    while (i < strlen(exp)) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            pushStack(&s, exp[i]);
        if (exp[i] == ')' && s.head->data == '(')
            popStack(&s);
        else if (exp[i] == ')' && s.head->data != '(')
            count += 1;
        if (exp[i] == '}' && s.head->data == '{')
            popStack(&s);
        else if (exp[i] == '}' && s.head->data != '{')
            count += 1;
        if (exp[i] == ']' && s.head->data == '[')
            popStack(&s);
        else if (exp[i] == ']' && s.head->data != '[')
            count += 1;
        i++;
    }
    
    if (s.head == NULL && count == 0)
        return 1;
     else
        return 0;
}

//3. Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного
//списка, без удаления первого списка).
void copyStack(Stack *x, Stack *y) {
    Stack z;
    z.size = 0;
    z.head = NULL;
    int temp;
    
    while (x->size > 0) {
        temp = popStack(x);
        pushStack(&z, temp);
    }
    while (z.size > 0) {
        temp = popStack(&z);
        pushStack(y, temp);
        pushStack(x, temp);
    }
}

//4. *Реализовать очередь.
typedef struct Qnode {
    T data;
    struct Qnode *next;
} Qnode;

typedef struct Qlist {
    Qnode *front;
    Qnode *rear;
    int size;
} Queue;

int enqueue(Queue *q, T value) {
    Qnode *temp = (Qnode*) malloc(sizeof(Qnode));
    if (temp == NULL) return 0;
    
    temp->data = value;
    temp->next = NULL;
    
    if (q->rear != NULL) {
        q->rear->next = temp;
        q->rear = temp;
    } else {
        q->front = q->rear = temp;
    }
    q->size++;
    return 1;
}

T dequeue(Queue *q) {
    if (q->size == 0)
        return -1;
    
    Qnode *temp = q->front;
    T result = q->front->data;
    q->front = q->front->next;
    q->size--;
    free(temp);
    return result;
}

int main(int argc, const char** argv) {
//1.
    Stack a;
    decToBinStack(334264324, &a);
    printf("DecToBinStack: ");
    while (a.size > 0)
        printf("%c ", popStack(&a));
    printf("\n");
//2.
    if (checkBrackets("[2/{5*(4+7)}]") == 1)
        printf("Right expression\n");
    else
        printf("Wrong expression\n");
//3.
    Stack x1;
    x1.size = 0;
    x1.head = NULL;
    
    Stack y1;
    y1.size = 0;
    y1.head = NULL;
    
    pushStack(&x1, 'a');
    pushStack(&x1, 'b');
    pushStack(&x1, 'c');
    pushStack(&x1, 'd');
    pushStack(&x1, 'e');
    pushStack(&x1, 'f');
    pushStack(&x1, 'g');
    
    copyStack(&x1, &y1);
    
    printf("Stack copy: ");
    while (y1.size > 0)
        printf("%c ", popStack(&y1));
    printf("\n");
    printf("Stack original: ");
    while (x1.size > 0)
        printf("%c ", popStack(&x1));
    printf("\n");
//4.
    Queue qu;
    qu.front = NULL;
    qu.rear = NULL;
    qu.size = 0;

    enqueue(&qu, 'a');
    enqueue(&qu, 'b');
    enqueue(&qu, 'c');
    enqueue(&qu, 'd');
    enqueue(&qu, 'e');
    enqueue(&qu, 'f');
    enqueue(&qu, 'g');
    printf("Dequeue: ");
    while (qu.size > 0)
        printf("%c ", dequeue(&qu));
    printf("\n");

    return 0;
}

