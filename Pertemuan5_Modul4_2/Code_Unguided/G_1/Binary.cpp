#include "Binary.h"

// Konstruktor: inisialisasi linked list kosong
Binary::Binary() {
    head = nullptr;
}

// Menambah node di akhir linked list
void Binary::append(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menghitung jumlah node
int Binary::getLength() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Mengambil node berdasarkan indeks
Node* Binary::getNodeAt(int index) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (count == index) return temp;
        count++;
        temp = temp->next;
    }
    return nullptr;
}

// Menampilkan isi linked list
void Binary::display() {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Binary Search pada Linked List
Node* Binary::binarySearch(int key) {
    int left = 0;
    int right = getLength() - 1;
    int iteration = 1;

    cout << "\nProses Pencarian:" << endl;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(mid);

        cout << "Iterasi " << iteration++ << ": Mid = "
             << midNode->data << " (indeks tengah = " << mid << ")";

        if (midNode->data == key) {
            cout << " -> DITEMUKAN!" << endl;

            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;

            if (midNode->next != nullptr)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL (node terakhir)" << endl;

            return midNode;
        }
        else if (midNode->data > key) {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
        else {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}
