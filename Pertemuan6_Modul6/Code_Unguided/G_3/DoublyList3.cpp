#include "DoublyList3.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.last != NULL) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = P->prev;
            L.last->next = NULL;
        }
        P->prev = NULL;
    }
}

void deleteAfter(List &L, address prec, address &P) {
    if (prec != NULL && prec->next != NULL) {
        P = prec->next;
        prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prec;
        } else {
            L.last = prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteElm(List &L, string nopol) {
    address P, prec;
    P = findElm(L, nopol);

    if (P != NULL) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            prec = P->prev;
            deleteAfter(L, prec, P);
        }
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n\n";
        dealokasi(P);
    } else {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n\n";
    }
}