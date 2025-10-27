#ifndef BINARY_H
#define BINARY_H

#include <iostream>
using namespace std;

// Struktur dasar Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Kelas Linked List dengan fungsi Binary Search
class Binary {
private:
    Node* head;

public:
    Binary();                 // Konstruktor
    void append(int value);   // Tambah node di akhir
    int getLength();          // Menghitung panjang list
    Node* getNodeAt(int index);  // Mengambil node berdasarkan indeks
    Node* binarySearch(int key); // Algoritma binary search
    void display();           // Menampilkan isi linked list
};

#endif
