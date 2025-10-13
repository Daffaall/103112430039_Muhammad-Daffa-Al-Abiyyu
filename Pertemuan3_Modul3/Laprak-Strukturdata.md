# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan konsep dasar dalam ilmu komputer yang mendefinisikan tipe data berdasarkan perilaku dan operasinya, bukan pada cara penyimpanan atau implementasinya [1].<br/>
ADT digunakan untuk memisahkan antara definisi logis dari suatu tipe data dan detail implementasinya sehingga memungkinkan pengembangan program yang modular, fleksibel, dan mudah dipelihara [2].<br/>
Dalam bahasa C++, penerapan ADT umumnya diwujudkan melalui penggunaan class, struktur, serta fungsi-fungsi seperti konstruktor, selector, dan mutator untuk mengelola data secara terenkapsulasi [3].<br/>

### A. Abstract Data Type (ADT)

Setiap program komputer memiliki pola logika yang serupa; perbedaannya terletak pada cara penulisannya.  
Sebagai contoh, bahasa Go menggunakan `import "fmt"` untuk mengakses pustaka input-output, sedangkan C++ memakai `#include <iostream>`.  
Secara umum, sebuah program C++ terdiri atas tiga bagian utama berikut:

Dalam pemrograman C++, konsep Abstract Data Type (ADT) dapat dibangun dengan beberapa cara. Biasanya, ini melibatkan penggunaan `struct` atau `class` untuk menampung data, fungsi untuk mengolahnya, serta pemisahan kode antara file header (.h) dan file implementasi (.cpp).

#### Tujuan Utama ADT:
1. Memisahkan antara deklarasi dan implementasi agar kode lebih rapi dan mudah dipahami.
2. Membentuk sistem modular yang memungkinkan tiap bagian dikembangkan secara terpisah.
3. Menyediakan kemudahan penggunaan ulang (reusability) bagi fungsi atau struktur yang sama.
4. Menjadikan perawatan kode lebih efisien karena perubahan pada satu bagian tidak berdampak pada keseluruhan.

#### Ciri Khas ADT:
- Memiliki deskripsi tipe data (contoh: `struct Mahasiswa`).
- Menyediakan serangkaian operasi seperti input dan perhitungan data.
- Menyembunyikan detail implementasi agar pengguna hanya berinteraksi melalui antarmuka.

--------------------------------------------------
 Dasar Implementasi ADT di C++
--------------------------------------------------
Penerapan ADT di C++ dapat diibaratkan seperti membangun sebuah rumah, di mana setiap bagian memiliki perannya masing-masing:

| Komponen | Fungsi | Analogi |
|----------|---------|---------|
| Header (.h) | Menyediakan cetak biru struktur dan fungsi | Seperti denah rumah yang merancang tata letak dan desain |
| Implementasi (.cpp) | Berisi logika atau isi fungsi | Seperti proses konstruksi yang membangun rumah berdasarkan denah |
| Program utama (main.cpp) | Menjalankan fungsi dari ADT | Seperti penghuni rumah yang menggunakan dan menghidupkan rumah tersebut |

Dengan pembagian ini, kode menjadi lebih terorganisir, mudah dipahami, dan fleksibel untuk pengembangan lebih lanjut.

--------------------------------------------------
 Contoh Implementasi Program
--------------------------------------------------
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    float nilaiUTS;
    float nilaiUAS;
};

void isiData(Mahasiswa &m) {
    cout << "Masukkan NIM        : ";
    cin >> m.nim;
    cout << "Masukkan Nilai UTS  : ";
    cin >> m.nilaiUTS;
    cout << "Masukkan Nilai UAS  : ";
    cin >> m.nilaiUAS;
}

double hitungRata(const Mahasiswa &m) {
    return (m.nilaiUTS + m.nilaiUAS) / 2.0;
}

int main() {
    Mahasiswa data;
    isiData(data);
    cout << "Rata-rata Nilai Mahasiswa: " << hitungRata(data) << endl;
    return 0;
}
```
### Penjelasan

`struct Mahasiswa` berfungsi sebagai implementasi nyata dari Abstract Data Type (ADT) yang digunakan untuk menyimpan data mahasiswa. 

- **Fungsi `isiData()`**: Bertugas menangani input data dari pengguna.
- **Fungsi `hitungRata()`**: Melakukan perhitungan nilai rata-rata berdasarkan data yang dimasukkan.
- **Fungsi `main()`**: Hanya memanggil operasi yang telah disediakan tanpa perlu mengetahui detail prosesnya.

Konsep ini mencerminkan esensi dari ADT, yaitu memisahkan antara deklarasi dan implementasi, sehingga pengguna hanya berinteraksi melalui antarmuka yang telah ditentukan.


## Guided 

### 1. Pengenalan ADT (Modular)

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

// Realisasi dari fungsi inputMhs
void inputMhs(Mahasiswa &m) {
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

// Realisasi dari fungsi rata2
float rata2(Mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
```C
#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi class Mahasiswa
struct Mahasiswa {
    char nim[10]; //atribut nim
    int nilai1,nilai2; /* data */
};

//Deklarasi fungsi
void inputMhs(Mahasiswa &m);
float rata2(Mahasiswa m);

#endif//fungsi untuk input data
```
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    Mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata rata: " << rata2(mhs) << endl;

    system("pause");

    return 0;

}
```
Penggunaan Modular 

### 2. Pengenalan ADT (TanpaModular)

```C++
#include <iostream>
using namespace std;

struct nahasiswa {
    string nim;
    int nilai1;
    int nilai2;
};

void inputMhs(nahasiswa &m) {
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(nahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}

int main() {
    nahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan prosedur
    cout << "Rata rata: " << rata2(mhs) << endl;
    return 0;
}
```
Tanpa Modular

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus:

0.3 * uts + 0.4 * uas + 0.3 * tugas

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * tugas) + (0.4 * uas) + (0.3 * uts);
}

int main() {
    Mahasiswa mahasiswa[10];
    int jumlahMahasiswa;

    cout << "Masukkan mahasiswa (maksimal 10): ";
    cin >> jumlahMahasiswa;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM   : ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    cout << "\n--- Data Nilai Akhir Mahasiswa ---\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama: " << mahasiswa[i].nama 
             << " | NIM: " << mahasiswa[i].nim 
             << " | Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan3_Modul3/Op/3_1.png)

Program ini menyimpan data mahasiswa dalam array of struct, lalu menghitung nilai akhir melalui fungsi hitungNilaiAkhir(). Konsep yang dilatih: array, struct, dan fungsi dengan return value.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:

tipe pelajaran <
 namaMapel : string
 kodeMapel : string

Function create_pelajaran(namapel : string, kodepel : string) → pelajaran
Procedure tampil_pelajaran(input pel : pelajaran)

Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
Cobalah hasil implementasi ADT pada file “main.cpp”

## File: `pelajaran.cpp`
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

## File: `pelajaran.h`
```C
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan3_Modul3/Op/3_2.png)

Bagian ini melatih konsep ADT (Abstract Data Type) dan pemrograman modular. Fungsi dan tipe data dipisah dalam file header (.h) dan implementasi (.cpp), seperti cara kerja library dalam C++.

## 3. Buatlah program dengan ketentuan:

2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer

Fungsi/prosedur yang menampilkan isi sebuah array integer 2D

Fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu

Fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}

void tukarArray(int A[N][N], int B[N][N], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int *p1, *p2;

    cout << "--- Array A ---" << endl;
    tampilArray(A);
    cout << "\n--- Array B ---" << endl;
    tampilArray(B);

    tukarArray(A, B, 1, 1);
    cout << "\nSetelah menukar elemen [1][1]:" << endl;
    cout << "Array A:" << endl; tampilArray(A);
    cout << "Array B:" << endl; tampilArray(B);

    int x = 10, y = 20;
    p1 = &x;
    p2 = &y;
    tukarPointer(p1, p2);

    cout << "\nSetelah menukar melalui pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan3_Modul3/Op/3_3.png)

Program ini menampilkan dua array 2D, menukar salah satu elemen antar-array, lalu menunjukkan penggunaan pointer untuk menukar dua variabel integer. Konsep utama: pointer, array 2D, dan fungsi void dengan parameter referensi memori.

## Kesimpulan
Latihan 3.2 secara keseluruhan melatih pemahaman mahasiswa terhadap tiga konsep penting dalam pemrograman C++, yaitu penggunaan array dan fungsi untuk mengolah data, penerapan ADT serta modular programming melalui pemisahan file header dan implementasi, serta pemahaman pointer dan manipulasi array dua dimensi untuk pertukaran data langsung di memori. Dengan mengerjakan ketiga bagian tersebut, mahasiswa dapat membangun dasar yang kuat dalam menyusun program yang terstruktur, efisien, dan mudah dikembangkan ke tahap yang lebih kompleks.

## Referensi
[1] R. Munir. (2018). Struktur Data. Informatika Bandung. https://informatika.stei.itb.ac.id/~rinaldi.munir/StrukturData/<br/>  
[2] W. Nugroho. (2020). Konsep Abstract Data Type (ADT) dalam Pemrograman Terstruktur. Jurnal Teknologi Informasi dan Komunikasi. https://ejournal.unsri.ac.id/index.php/jtik/article/view/5482<br/>  
[3] Technokrat Publishing. (2021). Modul Praktikum Struktur Data: Implementasi ADT dengan C++. https://publishing.teknokrat.ac.id/struktur-data-modul-adt/<br/>  