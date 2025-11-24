# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Queue adalah struktur data linier yang menerapkan prinsip First In, First Out (FIFO), di mana elemen yang pertama masuk akan menjadi elemen pertama yang keluar, dengan operasi dasar seperti enqueue (menambahkan di belakang), dequeue (menghapus dari depan), serta pengecekan isEmpty dan isFull untuk versi statis [1]. Queue bisa diimplementasikan melalui array (termasuk sebagai circular queue untuk efisiensi memori) maupun linked list agar ukuran menjadi dinamis [2]. Selain queue sederhana, ada juga variasi seperti priority queue dan deque yang menyediakan fleksibilitas lebih dalam pengurutan dan operasi elemen [3]. Dalam sistem operasi, struktur data queue banyak digunakan untuk penjadwalan proses karena FIFO menjamin keadilan dan keteraturan dalam eksekusi tugas [4].<br/>

# # Dasar Pemrograman
Dalam pemrograman, pembuatan program dimulai dari pemahaman elemen-elemen dasar seperti struktur data, alur kontrol, serta cara menyusun instruksi agar dapat dijalankan oleh komputer. Konsep ini menjadi fondasi sebelum mengembangkan program yang lebih kompleks.

## ## 1. Variabel dan Tipe Data

Variabel digunakan untuk menyimpan nilai, sedangkan tipe data menentukan jenis nilai tersebut. Contohnya:

```cpp
int angka;
float nilai;
char huruf;
```

Tipe data harus disesuaikan dengan kebutuhan penyimpanan program.

## ## 2. Operator

Operator berfungsi untuk melakukan operasi pada nilai atau variabel. Operator umum dalam C++ meliputi:

* Operator aritmatika: `+ - * / %`
* Operator relasional: `== != < > <= >=`
* Operator logika: `&& || !`

## ## 3. Struktur Kontrol

Struktur kontrol mengatur alur eksekusi program.

**Percabangan (if–else):**

```cpp
if (nilai >= 60) {
    cout << "Lulus";
} else {
    cout << "Tidak lulus";
}
```

**Perulangan (for):**

```cpp
for (int i = 0; i < 5; i++) {
    cout << i;
}
```

## ## 4. Fungsi dan Prosedur

Fungsi memecah program menjadi bagian kecil yang dapat digunakan kembali.
Contoh fungsi sederhana:

```cpp
int tambah(int a, int b) {
    return a + b;
}
```

## ## 5. Array

Array digunakan untuk menyimpan banyak nilai dengan tipe yang sama.

```cpp
int data[10];
```

Array menjadi dasar untuk memahami struktur data yang lebih kompleks seperti stack dan queue.

## ## 6. Pointer

Pointer menyimpan alamat memori dan sering digunakan dalam pengelolaan memori dinamis.

```cpp
int *p;
p = &angka;
```

## ## 7. Struktur (struct) (struct)

Digunakan untuk membuat tipe data baru yang terdiri dari beberapa elemen.

```cpp
struct Mahasiswa {
    string nama;
    int usia;
};
```

## ## 8. Pemrograman Modular

Mengatur program menjadi modul kecil agar mudah dipahami, diuji, dan dikembangkan. Pada program berskala besar, pemrograman modular sangat penting untuk efisiensi.

# Dasar Pemrograman Queue

## 1. Queue dengan Pointer
Queue berbasis linked list menggunakan node dinamis dengan pointer `next`. Elemen baru ditambahkan melalui operasi *enqueue* pada bagian **Rear**, sedangkan penghapusan elemen dilakukan melalui *dequeue* pada bagian **Front**. Struktur queue pointer memiliki sifat dinamis sehingga ukurannya dapat berkembang sesuai ketersediaan memori.

```cpp
struct elmQueue {
    infotype info;
    address next;
};

struct Queue {
    address Front;
    address Rear;
};
```

Operasi utama:

* `createQueue()` – inisialisasi queue kosong (Front = Rear = NULL)
* `enqueue()` – menambahkan elemen di bagian Rear
* `dequeue()` – mengambil elemen dari bagian Front
* `isEmpty()` – memeriksa kondisi queue kosong

## 2. Queue dengan Array

Queue dengan array menggunakan indeks `Front` dan `Rear` untuk menentukan posisi elemen. Karena array bersifat statis, ukuran queue bergantung pada kapasitas awal.

```cpp
struct Queue {
    int info[20];
    int Front;
    int Rear;
};
```

Operasi dasar:

* `enqueue()` – `Rear = Rear + 1` untuk memasukkan elemen
* `dequeue()` – mengambil elemen dari posisi `Front`, kemudian `Front = Front + 1`

Agar ruang tidak cepat habis di bagian depan array, implementasi sering menggunakan **Circular Queue**. Array digunakan karena lebih sederhana dan tidak membutuhkan pointer, namun memiliki keterbatasan kapasitas statis.

## Guided 

### 1. Queue

### queue.h
```h
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int angka);

#endif
```

### queue.cpp
```cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
        return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "queue.h"
#include <iostream> 

using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);
    
    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah dequeue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    cout << endl;

    return 0;
}
```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan Queue dalam C++.

## Guided 2

### 2. Queue

### queue.h
```h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### queue.cpp
```cpp
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

### main.cpp
```cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

## Unguided 

### 1. 

## File: `queue.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head++;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  |  ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << "\n";
    }
}

```

## File: `queue.h`
```h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T\t|\tQueue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 8_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_1.png)

Alternatif 1 membuat head tetap di awal dan hanya tail yang bergerak, sehingga setelah beberapa dequeue ruang di depan tidak bisa dipakai lagi dan queue cepat dianggap penuh.

### 2. 
## File: `queue.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4 && Q.head == 0);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {

        // Jika kosong
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        }
        else if (Q.tail == 4) {
            // SHIFT KIRI jika tail mentok tapi ada ruang di depan
            int j = 0;
            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[j] = Q.info[i];
                j++;
            }
            Q.tail = j - 1;  
            Q.head = 0;
            Q.tail++; 
        }
        else {
            Q.tail++;
        }

        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;

    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head++;
        }
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << "\n";
    }
}

```

## File: `queue.h`
```h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T\t|\tQueue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 8_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_2.png)

Alternatif 2 membuat head dan tail sama-sama bergerak, dan bila tail mentok tetapi ada ruang di depan maka elemen digeser agar posisi head kembali ke awal.

### 3.

## File: `queue.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % 5;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % 5;
    }
    cout << "\n";
}

```

## File: `queue.h`
```h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H - T\t|\tQueue info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 8_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_3.png)

Alternatif 3 memakai sistem circular sehingga head dan tail dapat kembali ke indeks awal, membuat seluruh ruang array selalu bisa dipakai tanpa perlu shifting.

## Kesimpulan
Ketiga alternatif queue menunjukkan tingkat efisiensi yang berbeda, di mana Alternatif 1 paling sederhana namun paling boros ruang, Alternatif 2 lebih fleksibel tetapi memerlukan pergeseran elemen, dan Alternatif 3 paling efisien karena memanfaatkan seluruh ruang array tanpa perlu shifting. Secara keseluruhan, circular queue (Alternatif 3) adalah implementasi terbaik untuk penggunaan memori yang optimal dan kinerja yang lebih cepat.

## Referensi
[1] Azura Trijayanti dkk., Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi. Jurnal Publikasi Teknik Informatika. <br/>
[2] Sirlia Sahid dkk., Implementasi Queue Berbasis Linked List pada Aplikasi Web Manajemen Antrian Print Mahasiswa. Jurnal Ilmu Komputer dan Informatika. <br/>
[3] Akbar Alif Haikal dkk., Implementasi Struktur Data Queue dan Stack Dalam Sistem Antrian Kasir Cafe Berbasis Web. Jurnal Publikasi Ilmu Komputer dan Multimedia. <br/>
[4] Efrans Christian dkk., Implementasi Algoritma FIFO dan Descending Priority Queue pada Sistem Antrian Pelayanan Kesehatan Puskesmas Buntok. Jurnal Teknologi Informasi. <br/>