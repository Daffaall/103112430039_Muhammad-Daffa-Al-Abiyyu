#include <iostream>
#include "Binary.h"
using namespace std;

int main() {
    Binary list;

    // Membuat linked list terurut (ascending)
    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);
    list.append(25);

    cout << "=== Binary Search Linked List ===" << endl;
    list.display();

    int key;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> key;

    Node* result = list.binarySearch(key);

    if (result != nullptr)
        cout << "\nHasil: Data " << key << " ditemukan di alamat memori " << result << endl;
    else
        cout << "\nHasil: Data " << key << " tidak ditemukan." << endl;

    return 0;
}
