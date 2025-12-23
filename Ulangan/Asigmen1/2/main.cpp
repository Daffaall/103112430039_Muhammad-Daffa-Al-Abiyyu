#include <iostream>
#include "Soal2.h"
using namespace std;

int main() {
    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertAkhir(nilai);
            break;

        case 2:
            deleteTerakhir();
            break;

        case 3:
            viewDepan();
            break;

        case 4:
            reverseList();
            break;
        case 0:
            aslimalas();
            break;
        }
    } while (menu != 0);

    return 0;
}
