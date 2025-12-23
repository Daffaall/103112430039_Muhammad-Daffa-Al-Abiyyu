#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    float beratBadan;
    string namaMember;
    string tierMember;
    Node* left;
    Node* right;

    Node(float berat, string nama, string tier) {
        beratBadan = berat;
        namaMember = nama;
        tierMember = tier;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, float berat, string nama, string tier);
    void inOrder(Node* node);
    Node* mostLeft(Node* node);
    Node* mostRight(Node* node);
    Node* searchByBeratBadan(Node* node, float berat);
    bool isEmpty(Node* node);

public:
    BST();
    void createTree();
    void insertNode(float berat, string nama, string tier);
    void inOrderTraversal();
    void mostLeftNode();
    void mostRightNode();
    void searchMemberByBeratBadan(float berat);
};

#endif
