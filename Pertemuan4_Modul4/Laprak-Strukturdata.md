# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Linked list merupakan salah satu struktur data dinamis yang terdiri atas rangkaian node, di mana setiap node menyimpan data dan alamat memori ke node berikutnya [1].<br/>
Berbeda dengan array yang bersifat statis, linked list memungkinkan alokasi memori secara fleksibel sehingga ukuran data dapat bertambah atau berkurang sesuai kebutuhan [2].<br/>
Dalam implementasi menggunakan bahasa C++, linked list umumnya dibangun dengan memanfaatkan pointer untuk menghubungkan antar node serta operator -> untuk mengakses elemen data di dalamnya [3].<br/>

## Struktur Linked List
```c
[Data | Next] → [Data | Next] → [Data | NULL]
```
Contoh:
```c
Head → [10 | •] → [20 | •] → [30 | NULL]
```
Setiap node menyimpan data dan alamat node berikutnya. Node terakhir menunjuk ke `NULL` sebagai tanda akhir list.

---
## Singly Linked List
1. **Node**  
    Node adalah elemen fundamental dalam struktur linked list yang terdiri dari dua komponen utama:  
    - **Data** → digunakan untuk menyimpan nilai atau informasi dari elemen tersebut.  
    - **Pointer (next)** → menyimpan alamat dari node selanjutnya dalam urutan list.  

2. **Head (Pointer Awal)**  
    Head adalah pointer yang mengarah ke node pertama dalam list. Jika list kosong, maka nilai head akan diatur menjadi `NULL`.

3. **NULL Terminator**  
    Node terakhir dalam linked list akan menunjuk ke `NULL`, yang menandakan bahwa tidak ada node berikutnya setelahnya dan menjadi batas akhir dari list.

---

## Operasi Dasar
1. **Create (Membuat List Baru)**
Tahap awal dalam pembuatan linked list dilakukan dengan menetapkan pointer `head` pada kondisi `NULL`, yang berarti list belum memiliki elemen.
2. **Insert (Menambahkan Node)**
Proses penambahan node baru dapat dilakukan di beberapa bagian list:
- Di awal list (*insert first*),
- Setelah node tertentu (*insert after*),
- Di akhir list (*insert last*).
3. **Delete (Menghapus Node)**
Node dapat dihapus berdasarkan posisi tertentu atau nilai data yang sesuai dengan kriteria penghapusan.
4. **Traversal (Menelusuri Elemen List)**
Tahapan ini dilakukan untuk menampilkan seluruh isi list, dimulai dari node pertama (`head`) hingga mencapai node terakhir yang menunjuk ke `NULL`.
5. **Search (Pencarian Node)**
Melakukan penelusuran satu per satu untuk menemukan node yang berisi data tertentu di dalam list.
6. **Update (Memperbarui Data)**
Mengubah atau memperbarui isi data pada node yang telah ditemukan berdasarkan posisi atau kondisi tertentu.
---

## Kelebihan dan Kekurangan

| Kelebihan | Kekurangan |
|-----------|------------|
| Bersifat dinamis dengan ukuran fleksibel | Akses data tidak langsung (perlu traversal) |
| Operasi tambah/hapus data efisien | Membutuhkan ruang tambahan untuk pointer | 
| Tidak perlu realokasi memori | Implementasi dan debugging lebih kompleks |

---

## Contoh node
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;  // inisialisasi list kosong
    cout << "Linked list berhasil dibuat (masih kosong)" << endl;
    return 0;
}
```
Penjelasan:
Kode di atas mendefinisikan struktur `Node` dengan dua atribut: `data` untuk menyimpan nilai dan `next` untuk menunjuk ke node berikutnya. Pointer `head` berfungsi sebagai penunjuk node pertama dalam list, dan jika kosong akan diatur ke `NULL`.

---

## Alur Kerja Insert Node di Awal

1. Buat node baru (`newNode`).
2. Masukkan nilai ke dalam `newNode->data`.
3. Hubungkan `newNode->next` ke `head` (node lama).
4. Pindahkan `head` agar menunjuk ke `newNode`.

### Contoh Kode:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* newNode = new Node();

    newNode->data = 10;
    newNode->next = head;
    head = newNode;

    cout << "Node baru dengan data " << head->data << " berhasil ditambahkan di awal list." << endl;
    return 0;
}
```

Penjelasan:
Setelah kode dijalankan, `newNode` akan menjadi elemen pertama dan `head` kini menunjuk ke node tersebut.

---

## Alur Kerja Menghapus Node di Awal

1. Periksa apakah list dalam keadaan kosong (`head == NULL`).
2. Simpan node pertama ke dalam pointer sementara.
3. Pindahkan `head` untuk menunjuk ke node berikutnya (`head = head->next`).
4. Hapus node yang telah disimpan dalam pointer sementara menggunakan `delete`.

### Contoh Kode:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    head->data = 10;
    head->next = NULL;

    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node pertama berhasil dihapus." << endl;
    } else {
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }

    return 0;
}
```

Penjelasan:
Kode di atas memeriksa apakah list berisi node. Jika ada, maka node pertama dihapus dan memori dikembalikan.

---

## Aplikasi Singly Linked List

Singly Linked List banyak digunakan dalam berbagai bidang pemrograman, di antaranya:

* **Sistem antrian pelanggan** (*queue sederhana*).
* **Fitur undo/redo** pada aplikasi pengolah teks atau gambar.
* **Implementasi struktur data lain**, seperti *stack*, *graph*, atau *hash table*.
* **Navigasi data dinamis**, misalnya pada game atau sistem basis data yang membutuhkan aliran data berurutan.

---

## Kesimpulan

Singly Linked List adalah struktur data yang memungkinkan pengelolaan elemen secara **dinamis dan efisien**, khususnya dalam operasi **penambahan dan penghapusan node** tanpa perlu menggeser elemen seperti pada array. Konsep **pointer** menjadi inti penghubung antar-node dalam list, menjadikannya salah satu dasar terpenting dalam pemrograman berbasis struktur data modern.

## Guided 

### 1. Data Masukkan

#### File: `list.h`
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

```
#### File: `list.cpp`
```cpp
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### File: `main.cpp`
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan Singly Linked List dalam C++. Setiap node menyimpan informasi mahasiswa (nama, NIM, umur) dan terhubung melalui pointer next.

### 2. Penambahan fitur delete
#### File: `list.h`
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```
#### File: `list.cpp`
```C++
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

---
```

#### File: `main.cpp`
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas merupakan pengembangan dari Guided 1 dengan penambahan fitur untuk menghapus node (delFirst, delLast, delAfter), menghitung jumlah node (nbList), dan menghapus seluruh list (deleteList).

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp”

## File: `Singlylist.cpp`
```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

## File: `Singlylist.h`
```C
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

## File: `main.cpp`
```C++
##include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
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

    printInfo(L); 
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan4_Modul4/Op/4_1.png)

Pada soal pertama, dibuat ADT Singly Linked List dengan operasi dasar seperti menambah, menghapus, dan menampilkan node. Dari hasil implementasi, dapat disimpulkan bahwa linked list memungkinkan pengelolaan data secara dinamis dan lebih fleksibel dibanding array.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

## File: `main.cpp`
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel;
    createList(L);

    // ===== Linked List Awal =====
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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan4_Modul4/Op/4_2.png)

Pada soal kedua, fungsi-fungsi ADT digunakan untuk menghapus node tertentu, menghitung jumlah elemen, dan mengosongkan list. Hasilnya menunjukkan bahwa setiap operasi berjalan sesuai logika, sehingga mahasiswa memahami cara kerja manipulasi data dalam linked list.

## Kesimpulan
Secara keseluruhan, Singly Linked List memberi pemahaman tentang pengelolaan data dinamis dan penerapan ADT yang membuat program lebih terstruktur, efisien, serta mudah dikembangkan dalam bahasa C++.

## Referensi
[1] R. Munir. (2018). Struktur Data. Informatika Bandung. https://informatika.stei.itb.ac.id/~rinaldi.munir/StrukturData/<br/>  
[2] A. Setiawan. (2020). Penerapan Struktur Data Linked List dalam Pemrograman C++. Jurnal Teknologi Informasi dan Ilmu Komputer, Universitas Brawijaya. https://jtiik.ub.ac.id/index.php/jtiik/article/view/3149<br/>  
[3] Technokrat Publishing. (2021). Modul Praktikum Struktur Data: Linked List. https://publishing.teknokrat.ac.id/struktur-data-modul-linkedlist/<br/>  