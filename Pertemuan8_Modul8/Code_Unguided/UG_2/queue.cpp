#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4 && Q.head == 0);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {

        // Jika kosong
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        }
        else if (Q.tail == 4) {
            // SHIFT KIRI jika tail mentok tapi ada ruang di depan
            int j = 0;
            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[j] = Q.info[i];
                j++;
            }
            Q.tail = j - 1;  
            Q.head = 0;
            Q.tail++; 
        }
        else {
            Q.tail++;
        }

        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;

    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head++;
        }
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << "\n";
    }
}
