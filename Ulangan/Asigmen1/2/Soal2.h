#ifndef SOAL2_H
#define SOAL2_H

#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
    Node* prev;
};

// Deklarasi fungsi
void insertAkhir(int nilai);
void deleteTerakhir();
void viewDepan();
void reverseList();
void aslimalas();

#endif
