#include "DoublyList3.h"
using namespace std;

int main() {
    List L;
    createList(L);

    infotype x;
    address P;

    x = {"D001", "hitam", 90}; insertLast(L, alokasi(x));
    x = {"D003", "putih", 70}; insertLast(L, alokasi(x));
    x = {"D004", "kuning", 90}; insertLast(L, alokasi(x));

    string cari;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;
    cout << endl;

    deleteElm(L, cari);

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}