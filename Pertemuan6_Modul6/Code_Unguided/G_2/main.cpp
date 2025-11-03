#include <iostream>
#include "Doublylist2.h"
using namespace std;

int main() {
    List2 L;
    createList2(L);

    infotype2 x;
    char lagi = 'y';

    while (lagi == 'y' || lagi == 'Y') {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (isDuplicate2(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address2 P = alokasi2(x);
            insertLast2(L, P);
        }

        cout << "masukkan data lagi? (y/n): ";
        cin >> lagi;
    }
    printInfo2(L);

    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari  : ";
    cin >> cari;

    address2 hasil = findElm2(L, cari);
    if (hasil != NULL) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nNomor Polisi tidak ditemukan." << endl;
    }

    return 0;
}
