#include "Soal4.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isFull(Queue Q) {
    return Q.tail == MAX - 1;
}

bool isEmpty(Queue Q) {
    return Q.head == -1;
}

void enQueue(Queue &Q, Paket P) {
    if (isFull(Q)) {
        cout << "Queue penuh\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.data[Q.tail] = P;
}

void deQueue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong\n";
        return;
    }

    for (int i = Q.head; i < Q.tail; i++) {
        Q.data[i] = Q.data[i + 1];
    }

    Q.tail--;
    if (Q.tail < Q.head) {
        Q.head = Q.tail = -1;
    }
}

void view(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.data[i].Resi << " | "
             << Q.data[i].Nama << " | "
             << Q.data[i].Tujuan << " | "
             << Q.data[i].Berat << "kg\n";
    }
}

int TotalBiaya(Queue Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        total += Q.data[i].Berat * 8250;
    }
    return total;
}
