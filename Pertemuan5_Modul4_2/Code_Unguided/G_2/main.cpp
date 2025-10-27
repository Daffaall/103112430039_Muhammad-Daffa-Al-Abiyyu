#include <iostream>
#include "Linear.h"
using namespace std;

int main() {
    Linear list;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // Membuat linked list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);

    list.display();

    // Input nilai yang ingin dicari
    int key;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> key;

    list.linearSearch(key);

    return 0;
}