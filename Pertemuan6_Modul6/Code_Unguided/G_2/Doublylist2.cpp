#include "Doublylist2.h"
#include <iostream>
using namespace std;

void createList2(List2 &L) {
    L.first = NULL;
    L.last = NULL;
}

address2 alokasi2(infotype2 x) {
    address2 P = new ElmList2;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi2(address2 &P) {
    delete P;
    P = NULL;
}

bool isDuplicate2(List2 L, string nopol) {
    address2 P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol)
            return true;
        P = P->next;
    }
    return false;
}

void insertLast2(List2 &L, address2 P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo2(List2 L) {
    address2 P = L.last;
    int i = 1;
    if (L.first == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    cout << endl << "DATA LIST " << i++ << endl;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address2 findElm2(List2 L, string nopol) {
    address2 P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
