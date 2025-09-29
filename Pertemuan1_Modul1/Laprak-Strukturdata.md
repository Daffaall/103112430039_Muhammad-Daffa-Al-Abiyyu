# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan pengembangan dari bahasa C yang mendukung pemrograman prosedural dan berorientasi objek, sehingga memudahkan pembuatan program yang terstruktur dan efisien [1]. Dalam proses pembelajaran, penggunaan Integrated Development Environment (IDE) sangat membantu karena menyediakan fasilitas penulisan, kompilasi, dan debugging dalam satu lingkungan [2].

## A. Dasar Pemrograman C++

1. **Susunan Program C++**
   Program C++ umumnya terdiri dari beberapa bagian utama:

   * `#include <iostream>` → pustaka standar untuk proses input dan output
   * `int main()` → fungsi awal yang akan dieksekusi saat program dijalankan
   * `{ ... }` → blok kode yang berisi perintah

   Contoh:

   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       cout << "Selamat Datang di C++!" << endl;
       return 0;
   }
   ```

2. **Jenis Tipe Data**

   * `int` → bilangan bulat, misalnya 42 atau -7
   * `float` / `double` → bilangan pecahan seperti 2.75 atau -1.5
   * `char` → satu karakter, misalnya 'B' atau 'x'
   * `string` → kumpulan karakter/teks seperti "Halo Dunia"
   * `bool` → nilai logika benar atau salah (true/false)

3. **Operator Matematika**

   * Penjumlahan (`+`)
   * Pengurangan (`-`)
   * Perkalian (`*`)
   * Pembagian (`/`)
   * Sisa hasil bagi (`%`)

---

## B. Masukan dan Keluaran

1. **Menggunakan `cin` (input)**
   Dipakai untuk membaca data yang dimasukkan pengguna.

   ```cpp
   int umur;
   cin >> umur;
   ```

2. **Menggunakan `cout` (output)**
   Digunakan untuk menampilkan informasi ke layar.

   ```cpp
   cout << "Umur Anda: " << umur << endl;
   ```

3. **Contoh Input dan Output Bersamaan**
   Nilai yang dimasukkan dapat langsung diproses dan ditampilkan.

   ```cpp
   int a, b;
   cin >> a >> b;
   cout << "Perkalian: " << a * b << endl;
   ```

---

## C. Percabangan (Pengambilan Keputusan)

1. **If–Else**
   Digunakan untuk memilih perintah sesuai kondisi.

   ```cpp
   if (a >= b) {
       cout << "a lebih besar atau sama dengan b" << endl;
   } else {
       cout << "b lebih besar dari a" << endl;
   }
   ```

2. **Switch–Case**
   Praktis jika ada beberapa pilihan menu.

   ```cpp
   int menu;
   cin >> menu;
   switch(menu) {
       case 1: cout << "Pilihan pertama"; break;
       case 2: cout << "Pilihan kedua"; break;
       default: cout << "Menu tidak ditemukan";
   }
   ```

---

## D. Perulangan (Looping)

1. **For Loop**
   Berguna ketika jumlah pengulangan sudah diketahui.

   ```cpp
   for (int i = 0; i < 4; i++) {
       cout << "Iterasi ke-" << i << endl;
   }
   ```

2. **While Loop**
   Dipakai bila perulangan berlangsung selama kondisi terpenuhi.

   ```cpp
   int hitung = 3;
   while (hitung >= 1) {
       cout << hitung << "!" << endl;
       hitung--;
   }
   ```

3. **Do–While Loop**
   Menjalankan blok perintah minimal satu kali sebelum memeriksa kondisi.

   ```cpp
   int k = 10;
   do {
       cout << "Nilai: " << k << endl;
       k -= 2;
   } while (k > 0);
   ```

## Guided 

### 1. Install dan- Praktek Hello World

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello World"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}

```
Literly type helo world

### 2. I/O

```C++
#include<iostream>
using namespace std;

int main()
{
    int angka;
    cout << "masukkan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Memasukan Dan mengeluarkan

### 3. Basic kalkulator

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
    cout << "Hasil modulus: " << angka1 % angka2 << endl;
    return 0;
    
}
```
Program sederhana aritmatika

### 4. Program Percabangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << " kurang dari " << endl;
    } else if (angka1 < angka2) {
        cout << " lebih dari " << endl;
    }

    if (angka1 == angka2) {
        cout << " sama dengan " << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " ;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
        cout << "penjumlahan: " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```
Pencabangan melanjutkan program sebelumnya

### 5. Perulangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;
    
    for (int i = 1; i <= angka1; i++) {
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--;
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    
}


```
perulangan tergantung inputan user

### 6. Program Nama dan Nilai Mahasiswa

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot Mahasiswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukan nama Mahasiswa : ";
        cin >> Mahasiswa[i].nama;
        cout << "masukan nilai Mahasiswa : ";
        cin >> Mahasiswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "Nama Mahasiswa : " << Mahasiswa[j].nama << ", Nilai : " << Mahasiswa[j].nilai << endl;
        j++;
    }
    return 0;
}

```
Struct, nama dan output inputan program

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main() {
    float a,b;
    cout << "Masukkan dua bilangan: ";
    cin >> a >> b;

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;
    if(b != 0)
        cout << "Pembagian: " << a / b << endl;
    else
        cout << "Pembagian: Tidak bisa (b=0)" << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan1_Modul1/Op/1_1.png)

Program ini meminta dua angka desimal, lalu menunjukan hasil tambah, kurang, kali, dan bagi.
Pembagian cuma jalan kalau angka kedua bukan nol. 

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima",
                   "enam","tujuh","delapan","sembilan"};
string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas",
                    "empat belas","lima belas","enam belas",
                    "tujuh belas","delapan belas","sembilan belas"};
string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh",
                    "lima puluh","enam puluh","tujuh puluh",
                    "delapan puluh","sembilan puluh"};

int main() {
    int n;
    cout << "Masukkan angka 0-100: ";
    cin >> n;
    cout << n << " : ";

    if(n < 10) cout << satuan[n];
    else if(n < 20) cout << belasan[n-10];
    else if(n < 100) {
        cout << puluhan[n/10];
        if(n%10 != 0) cout << " " << satuan[n%10];
    }
    else if(n == 100) cout << "seratus";
    else cout << "Di luar jangkauan";
    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan1_Modul1/Op/1_2.png)

Program ini meminta pengguna memasukkan satu bilangan bulat antara 0 sampai 100, lalu menampilkan angka tersebut dalam bentuk kata-kata bahasa Indonesia.
Program menggunakan array kata untuk satuan, belasan, dan puluhan, kemudian memanfaatkan percabangan if–else untuk menentukan cara penyebutannya (0–9 satuan, 10–19 belasan, 20–99 puluhan, dan 100 sebagai kasus khusus).

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        for (int j = i; j >= 1; j--) cout << j << " ";
        cout << "* ";
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan1_Modul1/Op/1_3.png)

Perulangan i dari n turun ke 1 menghasilkan baris yang semakin pendek,
dan baris terakhir hanya mencetak satu * sehingga terbentuk segitiga mengkerucut ke bawah.

## Kesimpulan
Ketiga program ini melatih dasar pemrograman C++ seperti menerima input, mengolah data, dan menampilkan output.
Program pertama melakukan operasi aritmatika pada dua bilangan, program kedua mengubah angka menjadi kata, dan program ketiga menampilkan pola segitiga menggunakan perulangan dan spasi.
Latihan ini membantu memahami penggunaan tipe data, percabangan, dan perulangan secara sederhana.

## Referensi
[1] Dewi, L. J. E. (2016). Media Pembelajaran Bahasa Pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan, Universitas Pendidikan Ganesha.
<br>[2] Prasetyo, A., & Anisa, N. (2017). Pengenalan Bahasa C++ dan IDE Code::Blocks. Academia.edu.
<br>[3] Modul Praktikum. (2020). Pengenalan Code::Blocks. Academia.edu.
