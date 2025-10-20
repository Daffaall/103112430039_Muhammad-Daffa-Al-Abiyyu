// #include "Singlylist.h"

// int main() {
//     List L;
//     address P1, P2, P3, P4, P5;
//     createList(L);

//     P1 = alokasi(2);
//     insertFirst(L, P1);

//     P2 = alokasi(0);
//     insertFirst(L, P2);

//     P3 = alokasi(8);
//     insertFirst(L, P3);

//     P4 = alokasi(12);
//     insertFirst(L, P4);

//     P5 = alokasi(9);
//     insertFirst(L, P5);

//     printInfo(L); 
//     return 0;
// }

//No 2
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, Pdel);      // hapus node 9
    dealokasi(Pdel);

    deleteLast(L, Pdel);       // hapus node 2
    dealokasi(Pdel);

    deleteAfter(L.first, Pdel); // hapus node setelah 12 (yaitu 8)
    dealokasi(Pdel);

    printInfo(L); // Output: 12 0
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
