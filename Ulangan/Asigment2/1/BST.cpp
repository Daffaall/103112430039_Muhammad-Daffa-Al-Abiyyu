#include "BST.h"

BST::BST() {
    root = nullptr;
}

Node* BST::insertNode(Node* node, float berat, string nama, string tier) {
    if (node == nullptr) {
        return new Node(berat, nama, tier);
    }


    if (berat < node->beratBadan) {
        node->left = insertNode(node->left, berat, nama, tier);
    } else {
        node->right = insertNode(node->right, berat, nama, tier);
    }

    return node;
}

void BST::insertNode(float berat, string nama, string tier) {
    root = insertNode(root, berat, nama, tier);
}

void BST::inOrder(Node* node) {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << node->beratBadan << " - ";
    inOrder(node->right);
}

void BST::inOrderTraversal() {
    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl;
}

Node* BST::mostLeft(Node* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BST::mostRight(Node* node) {
    while (node && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* BST::searchByBeratBadan(Node* node, float berat) {
    if (node == nullptr || node->beratBadan == berat) {
        return node;
    }

    if (berat < node->beratBadan) {
        return searchByBeratBadan(node->left, berat);
    }

    return searchByBeratBadan(node->right, berat);
}

void BST::searchMemberByBeratBadan(float berat) {
    Node* result = searchByBeratBadan(root, berat);
    if (result) {
        cout << "Data ditemukan dalam BST!" << endl;
        cout << "--- Data Node Yang Ditemukan ---" << endl;
        cout << "Nama Member: " << result->namaMember << endl;
        cout << "Berat Badan: " << result->beratBadan << endl;
        cout << "Tier Member: " << result->tierMember << endl;
        cout << "------------------------------" << endl;

        if (result != root) {
            Node* parent = searchByBeratBadan(root, result->beratBadan);
            cout << "--- Data Parent ---" << endl;
            cout << "Nama Member: " << parent->namaMember << endl;
            cout << "Berat Badan: " << parent->beratBadan << endl;
            cout << "Tier Member: " << parent->tierMember << endl;
            cout << "------------------------------" << endl;
        } else {
            cout << "Tidak Memiliki Parent (Root)" << endl;
        }

        cout << "--- Data Child Kiri ---" << endl;
        if (result->left) {
            cout << "Nama Member: " << result->left->namaMember << endl;
            cout << "Berat Badan: " << result->left->beratBadan << endl;
            cout << "Tier Member: " << result->left->tierMember << endl;
        } else {
            cout << "Tidak Memiliki Child Kiri" << endl;
        }
        cout << "------------------------------" << endl;

        cout << "--- Data Child Kanan ---" << endl;
        if (result->right) {
            cout << "Nama Member: " << result->right->namaMember << endl;
            cout << "Berat Badan: " << result->right->beratBadan << endl;
            cout << "Tier Member: " << result->right->tierMember << endl;
        } else {
            cout << "Tidak Memiliki Child Kanan" << endl;
        }
        cout << "------------------------------" << endl;
    } else {
        cout << "Data Tidak Ditemukan!" << endl;
    }
}

bool BST::isEmpty(Node* node) {
    return node == nullptr;
}

void BST::createTree() {
    root = nullptr;
}

void BST::mostLeftNode() {
    Node* left = mostLeft(root);
    if (left) {
        cout << "Node Most Left: " << left->beratBadan << endl;
    }
}

void BST::mostRightNode() {
    Node* right = mostRight(root);
    if (right) {
        cout << "Node Most Right: " << right->beratBadan << endl;
    }
}
