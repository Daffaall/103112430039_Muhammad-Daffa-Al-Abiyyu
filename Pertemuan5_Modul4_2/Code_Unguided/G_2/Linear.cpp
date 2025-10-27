#include "Linear.h"

Linear::Linear() {
    head = nullptr;
}

// Menambahkan node di akhir linked list
void Linear::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menampilkan isi linked list
void Linear::display() {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Linear Search
Node* Linear::linearSearch(int key) {
    Node* temp = head;
    int index = 1;
    bool found = false;

    cout << "\nProses Pencarian:" << endl;

    while (temp != nullptr) {
        cout << "Memeriksa node " << index << ": " << temp->data;
        if (temp->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            found = true;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next != nullptr)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL (node terakhir)" << endl;
            return temp;
        } else {
            cout << " (tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}
