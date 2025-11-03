# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Linked list adalah struktur data yang terdiri dari simpul-simpul (node) yang saling terhubung melalui pointer, di mana setiap simpul berisi data dan alamat simpul berikutnya [1]. Berbeda dengan array yang bersifat statis, linked list memungkinkan ukuran data berubah secara dinamis tanpa perlu alokasi memori yang berurutan [2]. Struktur ini memudahkan proses penambahan dan penghapusan data karena tidak perlu menggeser elemen lain, meskipun akses ke elemen tertentu harus dilakukan secara berurutan dari awal [3]. Jenis-jenis linked list meliputi singly linked list, doubly linked list, dan circular linked list, yang masing-masing digunakan sesuai kebutuhan arah hubungan antar node [2].<br/>

## Dasar Pemrograman

Pemrograman *Doubly Linked List* dalam bahasa **C++** menggunakan konsep **struktur data dinamis** berbasis **pointer**. Setiap *node* dibuat menggunakan `struct` yang berisi data dan dua pointer (`next` dan `prev`).

Operasi dasar yang umum dilakukan meliputi:

1. **CreateList()** – Menginisialisasi list kosong dengan `head` bernilai `NULL` agar siap menampung data.
2. **Alokasi dan Dealokasi** – `alokasi()` membuat *node* baru menggunakan operator `new`, sedangkan `dealokasi()` membebaskan memori dengan `delete` agar tidak terjadi *memory leak*.
3. **Insert dan Delete** – Dapat dilakukan di awal (*first*), di akhir (*last*), maupun di tengah list. Karena terdapat dua pointer (`prev` dan `next`), hubungan antar-elemen dapat dipertahankan dengan mudah meskipun terjadi penghapusan atau penyisipan data.
4. **FindElm() / Search** – Menelusuri elemen berdasarkan data tertentu, misalnya nilai integer tertentu. Proses ini biasanya dilakukan secara linear.
5. **PrintInfo()** – Menampilkan isi list dari depan ke belakang atau sebaliknya.

Keunggulan utama *Doubly Linked List* dibanding *Singly Linked List* adalah kemampuannya untuk melakukan traversal dua arah dan kemudahan penghapusan elemen tanpa perlu mengetahui elemen sebelumnya secara eksplisit.

---

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode; // jika list kosong, tail juga menunjuk ke node baru
    }
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode; // jika list kosong, head juga menunjuk ke node baru
    }
    tail = newNode;
}

void printForward() {
    Node* temp = head;
    cout << "Data dari depan: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward() {
    Node* temp = tail;
    cout << "Data dari belakang: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    insertFirst(10);
    insertFirst(20);
    insertLast(5);

    printForward();
    printBackward();

    return 0;
}
```

---

### Penjelasan Program
1. **Struct Node** – Menyimpan data integer dan dua pointer (`prev` dan `next`).
2. **insertFirst()** – Menyisipkan data di awal list. Jika list kosong, `head` dan `tail` akan menunjuk ke node baru.
3. **insertLast()** – Menambahkan data di akhir list. Jika list kosong, `head` juga menunjuk ke node baru.
4. **printForward()** – Menampilkan isi list dari depan ke belakang.
5. **printBackward()** – Menampilkan isi list dari belakang ke depan.
6. **main()** – Menjalankan contoh penambahan dan penampilan data dari dua arah.

Program ini menggambarkan prinsip dasar *Doubly Linked List*, yaitu setiap node dapat diakses dari dua arah dengan menjaga konsistensi hubungan antar-node menggunakan pointer `prev` dan `next`.

---

## Guided 

### 1. Makan an

### listmakanan.h
```cpp
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### listmakanan.cpp
```cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan Doubly Linked List dalam C++.

## Guided 2 – Doublylist - Kendaraan

### Doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```

### Doublylist.cpp
```cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

### main.cpp
```cpp
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}

```

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu.

## File: `Doublylist.cpp`
```C++
#include "Doublylist.h"
#include <iostream>
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

bool isDuplicate(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol)
            return true;
        P = P->next;
    }
    return false;
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

void printInfo(List L) {
    address P = L.last;
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
```

## File: `Doublylist.h`
```C
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// ==== Deklarasi Prosedur dan Fungsi ====
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isDuplicate(List L, string nopol);

#endif
```

## File: `main.cpp`
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 6_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan6_Modul6/Op/6_1.png)

fokus utamanya adalah membangun struktur dasar Doubly Linked List dan mengimplementasikan operasi dasar seperti membuat list, mengalokasikan elemen, serta menampilkan data. Soal ini menegaskan pentingnya pemahaman konsep pointer dan hubungan dua arah antar elemen dalam list.

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu.

## File: `Doublylist2.cpp`
```C++
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
```

## File: `Doublylist2.h`
```C
#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H
#include <string>
using namespace std;


struct kendaraan2 {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan2 infotype2;

struct ElmList2;
typedef ElmList2* address2;

struct ElmList2 {
    infotype2 info;
    address2 next;
    address2 prev;
};

struct List2 {
    address2 first;
    address2 last;
};


void createList2(List2 &L);
address2 alokasi2(infotype2 x);
void dealokasi2(address2 &P);
void printInfo2(List2 L);
void insertLast2(List2 &L, address2 P);
bool isDuplicate2(List2 L, string nopol);
address2 findElm2(List2 L, string nopol);

#endif
```

## File: `main.cpp`
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 6_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan6_Modul6/Op/6_2.png)

Soal kedua mengembangkan konsep sebelumnya dengan menambahkan fitur pengecekan duplikasi data sebelum melakukan penyisipan. Hal ini menunjukkan penerapan logika kontrol dalam menjaga integritas data agar tidak terjadi data ganda pada list.

### 3. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu.

## File: `Doublylist3.cpp`
```C++
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
```

## File: `Doublylist3.h`
```C
#ifndef DOUBLYLIST3_H
#define DOUBLYLIST3_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address prec, address &P);
void deleteElm(List &L, string nopol);

#endif
```

## File: `main.cpp`
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 6_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan6_Modul6/Op/6_3.png)

Pada soal ketiga, fokusnya adalah pada proses penghapusan data, baik di awal, akhir, maupun tengah list. Soal ini memperlihatkan bagaimana pengelolaan pointer dilakukan secara hati-hati agar struktur list tetap konsisten setelah elemen dihapus.

## Kesimpulan
Secara keseluruhan, ketiga soal ini menggambarkan proses pembentukan dan pengelolaan Doubly Linked List secara menyeluruh—mulai dari pembuatan, penambahan, pencarian, hingga penghapusan elemen yang menjadi dasar penting dalam memahami konsep struktur data dinamis di pemrograman.

## Referensi
[1] Rumahcoding.co.id, Linked List: Pengertian dan Implementasi Dasar, 2021.<br/>  
[2] Terapan-TI Vokasi Unesa, Memahami Konsep dan Jenis-Jenis Linked List dalam Struktur Data, 2020.<br/>  
[3] Fikti UMSU, Pengertian Linked List: Struktur Data dalam Pemrograman, 2022.<br/>  