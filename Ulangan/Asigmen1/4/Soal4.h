#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

const int MAX = 10;

struct Paket {
    string Resi;
    string Nama;
    string Tujuan;
    int Berat;
};

struct Queue {
    Paket data[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isFull(Queue Q);
bool isEmpty(Queue Q);

void enQueue(Queue &Q, Paket P);
void deQueue(Queue &Q);
void view(Queue Q);
int TotalBiaya(Queue Q);

#endif