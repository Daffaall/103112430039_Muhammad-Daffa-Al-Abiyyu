#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Linear {
private:
    Node* head;

public:
    Linear();
    void append(int value);
    Node* linearSearch(int key);
    void display();
};

#endif
