#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST tree;

    tree.createTree();
    tree.insertNode(60, "Rizkina Azizah", "Basic");
    tree.insertNode(50, "Hakan Ismail", "Bronze");
    tree.insertNode(65, "Olivia Saevali", "Silver");
    tree.insertNode(47, "Felix Pedrosa", "Gold");
    tree.insertNode(56, "Gamel Al Ghifari", "Platinum");
    tree.insertNode(70, "Hanif Al Faiz", "Basic");
    tree.insertNode(52, "Mutiara Fauziah", "Bronze");
    tree.insertNode(68, "Davi Ilyas", "Silver");
    tree.insertNode(81, "Abdad Mubarak", "Gold");

    float berat;
    cout << "Masukkan Berat Badan yang ingin dicari: ";
    cin >> berat;

    tree.searchMemberByBeratBadan(berat);

    tree.inOrderTraversal();

    tree.mostLeftNode();

    tree.mostRightNode();

    return 0;
}
