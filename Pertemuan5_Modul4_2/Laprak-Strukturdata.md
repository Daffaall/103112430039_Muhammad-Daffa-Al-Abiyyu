# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Kedua)</h1>
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

### 1. Bu Ah

#### File: `listBuah.h`
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```
#### File: `listBuah.cpp`
```cpp
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "
                 << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
#### File: `main.cpp`
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;


}
```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan Singly Linked List dalam C++.

### 2. Searching YGY
#### File: `linear.cpp`
```C++
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    
    Node* result = linearSearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```

---

#### File: `binary.cpp`
```C++
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) size++;
    Node* start = head;
    Node* end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        for (int i = 0; i < mid; ++i) midNode = midNode->next;

        if (midNode->data == key) return midNode;
        if (midNode->data < key) {
            start = midNode->next;
        }
        else {
            end = midNode;
        }
        size -= mid;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50);
    
    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program di atas merupakan pengembangan dari Guided 1 dengan penambahan fitur untuk menghapus node (delFirst, delLast, delAfter), menghitung jumlah node (nbList), dan menghapus seluruh list (deleteList).

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu.

## File: `Binary.cpp`
```C++
#include "Binary.h"

// Konstruktor: inisialisasi linked list kosong
Binary::Binary() {
    head = nullptr;
}

// Menambah node di akhir linked list
void Binary::append(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menghitung jumlah node
int Binary::getLength() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Mengambil node berdasarkan indeks
Node* Binary::getNodeAt(int index) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (count == index) return temp;
        count++;
        temp = temp->next;
    }
    return nullptr;
}

// Menampilkan isi linked list
void Binary::display() {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Binary Search pada Linked List
Node* Binary::binarySearch(int key) {
    int left = 0;
    int right = getLength() - 1;
    int iteration = 1;

    cout << "\nProses Pencarian:" << endl;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(mid);

        cout << "Iterasi " << iteration++ << ": Mid = "
             << midNode->data << " (indeks tengah = " << mid << ")";

        if (midNode->data == key) {
            cout << " -> DITEMUKAN!" << endl;

            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;

            if (midNode->next != nullptr)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL (node terakhir)" << endl;

            return midNode;
        }
        else if (midNode->data > key) {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
        else {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

```

## File: `Binary.h`
```C
#ifndef BINARY_H
#define BINARY_H

#include <iostream>
using namespace std;

// Struktur dasar Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Kelas Linked List dengan fungsi Binary Search
class Binary {
private:
    Node* head;

public:
    Binary();                 // Konstruktor
    void append(int value);   // Tambah node di akhir
    int getLength();          // Menghitung panjang list
    Node* getNodeAt(int index);  // Mengambil node berdasarkan indeks
    Node* binarySearch(int key); // Algoritma binary search
    void display();           // Menampilkan isi linked list
};

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "Binary.h"
using namespace std;

int main() {
    Binary list;

    // Membuat linked list terurut (ascending)
    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);
    list.append(25);

    cout << "=== Binary Search Linked List ===" << endl;
    list.display();

    int key;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> key;

    Node* result = list.binarySearch(key);

    if (result != nullptr)
        cout << "\nHasil: Data " << key << " ditemukan di alamat memori " << result << endl;
    else
        cout << "\nHasil: Data " << key << " tidak ditemukan." << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan4_Modul4_2/Op/5_1.png)

Program melakukan pencarian data pada linked list terurut menggunakan metode binary search, dengan membandingkan elemen tengah untuk menentukan arah pencarian hingga data ditemukan atau tidak ditemukan.

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu.

## File: `Linear.cpp`
```C++
#include "Linear.h"

Linear::Linear() {
    head = nullptr;
}

// Menambahkan node di akhir linked list
void Linear::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menampilkan isi linked list
void Linear::display() {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Linear Search
Node* Linear::linearSearch(int key) {
    Node* temp = head;
    int index = 1;
    bool found = false;

    cout << "\nProses Pencarian:" << endl;

    while (temp != nullptr) {
        cout << "Memeriksa node " << index << ": " << temp->data;
        if (temp->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            found = true;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next != nullptr)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL (node terakhir)" << endl;
            return temp;
        } else {
            cout << " (tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}
```

## File: `Linear.h`
```C
#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Linear {
private:
    Node* head;

public:
    Linear();
    void append(int value);
    Node* linearSearch(int key);
    void display();
};

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "Linear.h"
using namespace std;

int main() {
    Linear list;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // Membuat linked list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);

    list.display();

    // Input nilai yang ingin dicari
    int key;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> key;

    list.linearSearch(key);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan5_Modul4_2/Op/5_2.png)

Program mencari data pada linked list menggunakan metode linear search, dengan memeriksa setiap node secara berurutan mulai dari awal hingga data ditemukan atau tidak ditemukan.

## Kesimpulan
Kedua program menunjukkan perbedaan cara kerja algoritma pencarian, di mana binary search lebih efisien untuk data terurut, sedangkan linear search lebih sederhana namun memakan waktu lebih lama karena memeriksa semua elemen satu per satu.

## Referensi
[1] R. Munir. (2018). Struktur Data. Informatika Bandung.<br/>  
[2] A. Setiawan. (2020). Penerapan Struktur Data Linked List dalam Pemrograman C++. Jurnal Teknologi Informasi dan Ilmu Komputer, Universitas Brawijaya.<br/>  
[3] Technokrat Publishing. (2021). Modul Praktikum Struktur Data: Linked List.<br/>  