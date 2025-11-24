# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Queue adalah struktur data linier yang menerapkan prinsip First In, First Out (FIFO), di mana elemen yang pertama masuk akan menjadi elemen pertama yang keluar, dengan operasi dasar seperti enqueue (menambahkan di belakang), dequeue (menghapus dari depan), serta pengecekan isEmpty dan isFull untuk versi statis [1]. Queue bisa diimplementasikan melalui array (termasuk sebagai circular queue untuk efisiensi memori) maupun linked list agar ukuran menjadi dinamis [2]. Selain queue sederhana, ada juga variasi seperti priority queue dan deque yang menyediakan fleksibilitas lebih dalam pengurutan dan operasi elemen [3]. Dalam sistem operasi, struktur data queue banyak digunakan untuk penjadwalan proses karena FIFO menjamin keadilan dan keteraturan dalam eksekusi tugas [4].<br/>

## Dasar Pemrograman
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
```cpp

```

### queue.cpp
```cpp

```

### main.cpp
```cpp

```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan stack dalam C++.

## Guided 2

### 2. Queue

### queue.h
```cpp

```

### queue.cpp
```cpp

```

### main.cpp
```cpp

```

## Unguided 

### 1. 

## File: `queue.cpp`
```C++

```

## File: `queue.h`
```C

```

## File: `main.cpp`
```C++

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 8_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_1.png)



### 2. 
## File: `queue.cpp`
```C++

```

## File: `queue.h`
```C

```

## File: `main.cpp`
```C++

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 8_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_2.png)



### 3.

## File: `queue.cpp`
```C++

```

## File: `queue.h`
```C

```

## File: `main.cpp`
```C++

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 8_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan8_Modul8/Op/8_3.png)



## Kesimpulan


## Referensi
[1] Azura Trijayanti dkk., Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi. Jurnal Publikasi Teknik Informatika. <br/>
[2] Sirlia Sahid dkk., Implementasi Queue Berbasis Linked List pada Aplikasi Web Manajemen Antrian Print Mahasiswa. Jurnal Ilmu Komputer dan Informatika. <br/>
[3] Akbar Alif Haikal dkk., Implementasi Struktur Data Queue dan Stack Dalam Sistem Antrian Kasir Cafe Berbasis Web. Jurnal Publikasi Ilmu Komputer dan Multimedia. <br/>
[4] Efrans Christian dkk., Implementasi Algoritma FIFO dan Descending Priority Queue pada Sistem Antrian Pelayanan Kesehatan Puskesmas Buntok. Jurnal Teknologi Informasi. <br/>