#include <iostream>
#include "Soal1.h"
using namespace std;

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Masukkan nama: ";
            cin >> nama;
            insertAkhir(nama);
            break;

        case 2:
            cout << "Masukkan nama untuk delete: ";
            cin >> nama;
            deleteNama(nama);
            break;

        case 3:
            view();
            break;

        case 4:
            hitungGenap();
            break;

        case 0:
            asalamualikum();
        }
    } while (menu != 0);

    return 0;
}
