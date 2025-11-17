#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 20;
typedef int infotipe;

struct Stack {
    infotipe array[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotipe x);
infotipe pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Tambahan
void pushAscending(Stack &S, infotipe x);
void getInputStream(Stack &S);

#endif