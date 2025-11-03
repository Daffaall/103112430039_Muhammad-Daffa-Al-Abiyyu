#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    infotype x;
    char lagi = 'y';

    while (lagi == 'y' || lagi == 'Y') {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (isDuplicate(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
        }

        cout << "masukkan data lagi? (y/n): ";
        cin >> lagi;
    }

    printInfo(L);

    return 0;
}