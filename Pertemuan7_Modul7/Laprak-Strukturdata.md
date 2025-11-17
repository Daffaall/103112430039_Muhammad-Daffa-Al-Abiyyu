# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Stack adalah struktur data linear yang bekerja dengan prinsip Last In, First Out (LIFO), di mana elemen terakhir yang masuk menjadi elemen pertama yang keluar. Struktur ini memiliki operasi dasar seperti push, pop, dan peek yang memungkinkan pengelolaan data secara teratur dan efisien [1]. Stack dapat diimplementasikan menggunakan array ataupun linked list, dengan array menawarkan kemudahan akses dan linked list memberikan fleksibilitas ukuran [2]. Sebagai Abstract Data Type (ADT), stack berfokus pada perilaku operasinya tanpa terikat pada bentuk implementasi tertentu [3]. Dalam penerapannya, stack digunakan dalam evaluasi ekspresi, mekanisme undo/redo, call stack pada proses rekursi, serta validasi sintaks dalam pemrograman [4].<br/>

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

## Guided 

### 1. Stack

### Stack.h
```cpp
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### Stack.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan stack dalam C++.

## Guided 2 – stack

### Doublylist.h
```cpp
#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### Doublylist.cpp
```cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

### main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY.

## File: `stack.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotipe x) {
    if (S.top < MAX_STACK - 1) {
        S.top++;
        S.array[S.top] = x;
    }
}

infotipe pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.array[S.top];
        S.top--;
        return temp;
    }
    return -1; 
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.array[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// --------------------------------------------
// Tambahan: pushAscending
// Menyisipkan elemen sehingga stack tetap urut mengecil dari TOP
// --------------------------------------------
void pushAscending(Stack &S, infotipe x) {
    Stack temp;
    createStack(temp);

    // pindahkan elemen yang lebih kecil ke temp
    while (S.top >= 0 && S.array[S.top] < x) {
        push(temp, pop(S));
    }

    // masukkan elemen x
    push(S, x);

    // kembalikan elemen temp ke stack utama
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

// --------------------------------------------
// Tambahan: getInputStream
// Membaca input karakter sampai ENTER ditekan
// --------------------------------------------
void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;       // berhenti jika ENTER
        push(S, c - '0');           // konversi char → angka
    }
}

```

## File: `stack.h`
```C
#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);      // buang 8
    push(S, 2);
    push(S, 3);
    pop(S);      // buang 3
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 6_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan7_Modul7/Op/7_1.png)

Program ini menguji operasi dasar stack seperti push, pop, dan membalik stack menggunakan array. Nilai dimasukkan dan dihapus sesuai urutan di soal, lalu hasil akhir ditampilkan sebelum dan sesudah dibalik agar sesuai dengan output contoh di modul.

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer).
## File: `stack.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotipe x) {
    if (S.top < MAX_STACK - 1) {
        S.top++;
        S.array[S.top] = x;
    }
}

infotipe pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.array[S.top];
        S.top--;
        return temp;
    }
    return -1; 
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.array[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// --------------------------------------------
// Tambahan: pushAscending
// Menyisipkan elemen sehingga stack tetap urut mengecil dari TOP
// --------------------------------------------
void pushAscending(Stack &S, infotipe x) {
    Stack temp;
    createStack(temp);

    // pindahkan elemen yang lebih kecil ke temp
    while (S.top >= 0 && S.array[S.top] < x) {
        push(temp, pop(S));
    }

    // masukkan elemen x
    push(S, x);

    // kembalikan elemen temp ke stack utama
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

// --------------------------------------------
// Tambahan: getInputStream
// Membaca input karakter sampai ENTER ditekan
// --------------------------------------------
void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;       // berhenti jika ENTER
        push(S, c - '0');           // konversi char → angka
    }
}

```

## File: `stack.h`
```C
#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 6_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan7_Modul7/Op/7_2.png)

Bagian ini menambahkan fungsi pushAscending yang memasukkan data secara terurut sehingga stack tetap dalam urutan menaik. Program menguji fungsi tersebut dengan beberapa nilai sehingga output akhirnya mengikuti urutan yang ditunjukkan pada modul. 

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ).

## File: `stack.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotipe x) {
    if (S.top < MAX_STACK - 1) {
        S.top++;
        S.array[S.top] = x;
    }
}

infotipe pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.array[S.top];
        S.top--;
        return temp;
    }
    return -1; 
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.array[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// --------------------------------------------
// Tambahan: pushAscending
// Menyisipkan elemen sehingga stack tetap urut mengecil dari TOP
// --------------------------------------------
void pushAscending(Stack &S, infotipe x) {
    Stack temp;
    createStack(temp);

    // pindahkan elemen yang lebih kecil ke temp
    while (S.top >= 0 && S.array[S.top] < x) {
        push(temp, pop(S));
    }

    // masukkan elemen x
    push(S, x);

    // kembalikan elemen temp ke stack utama
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

// --------------------------------------------
// Tambahan: getInputStream
// Membaca input karakter sampai ENTER ditekan
// --------------------------------------------
void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;       // berhenti jika ENTER
        push(S, c - '0');           // konversi char → angka
    }
}

```

## File: `stack.h`
```C
#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 6_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan7_Modul7/Op/7_3.png)

Pada bagian ini dibuat fungsi getInputStream yang membaca karakter sampai ENTER ditekan dan memasukkannya ke dalam stack sebagai angka. Isi stack kemudian ditampilkan dan dibalik, menghasilkan output yang sama seperti contoh pada modul.

## Kesimpulan
Dari seluruh percobaan, dapat disimpulkan bahwa ADT Stack berbasis array dapat diimplementasikan dengan baik untuk berbagai kebutuhan, mulai dari operasi dasar (push, pop, dan membalik stack), penyisipan data secara terurut menggunakan pushAscending, hingga pembacaan input pengguna melalui getInputStream. Setiap fungsi bekerja sesuai tujuan dan menghasilkan output yang sama seperti contoh pada modul, sehingga keseluruhan implementasi dapat dinyatakan berjalan dengan benar.

## Referensi
[1] Yuliana, “Struktur Data: Stack,” PENS.<br/>  
[2] Setiyawan, R. D., “Penggunaan Struktur Data Stack…,” JUTECH.<br/>  
[3] Rajasekaran, “Analysis of Stack and Queue…,” IGI Global.<br/>
[4] Amaylia, “Application of Stack Data Structure…,” JASIC.<br/>