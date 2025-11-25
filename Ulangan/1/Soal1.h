#ifndef SOAL1_H
#define SOAL1_H

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

// Deklarasi fungsi
void insertAkhir(string nama);
bool deleteNama(string target);
void view();
void hitungGenap();
void asalamualikum();

#endif
