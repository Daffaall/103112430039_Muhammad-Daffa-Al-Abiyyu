# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan turunan dari bahasa C yang mendukung paradigma prosedural sekaligus berorientasi objek, sehingga memungkinkan penyusunan program yang terstruktur, modular, dan efisien [1]. Konsep dasar seperti tipe data, operator, input-output, array, dan pointer membentuk fondasi bagi manipulasi data serta kontrol alur program [2]. Dalam konteks pendidikan di Indonesia, penelitian “Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik” menyatakan bahwa C++ efektif digunakan untuk memperlancar pemahaman mahasiswa terhadap konsep dasar pemrograman [3].

### A. Dasar Pemrograman C++<br/>

Setiap program komputer memiliki pola logika yang serupa; perbedaannya terletak pada cara penulisannya.  
Sebagai contoh, bahasa Go menggunakan `import "fmt"` untuk mengakses pustaka input-output, sedangkan C++ memakai `#include <iostream>`.  
Secara umum, sebuah program C++ terdiri atas tiga bagian utama berikut:

1. **Struktur Program C++**  
   Komponen penting dalam program C++ meliputi:

   * `#include <iostream>` → pustaka standar untuk melakukan input dan output  
   * `int main()` → fungsi utama yang akan dijalankan pertama kali  
   * `{ ... }` → blok tempat menuliskan perintah program  

Contoh:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

2. **Tipe Data**  
   a. `int` → bilangan bulat (contoh: 8, -2).  
   b. `float` / `double` → bilangan pecahan (contoh: 3.5, -7.2).  
   c. `char` → satu karakter tunggal (contoh: 'A').  
   d. `string` → kumpulan karakter atau teks (contoh: "Program C++").  
   e. `bool` → nilai logika benar atau salah (true / false).

3. **Operator Aritmatika**  
   Operator digunakan untuk menjalankan operasi perhitungan dasar layaknya kalkulator:  
   a. `+` → penjumlahan  
   b. `-` → pengurangan  
   c. `*` → perkalian  
   d. `/` → pembagian  
   e. `%` → sisa pembagian  

---

### B. Input & Output<br/>

1. **Fungsi `cin` (input)**  
   Digunakan untuk menerima data dari pengguna.

   ```cpp
   int angka;
   cin >> angka;
   ```

2. **Fungsi `cout` (output)**  
   Dipakai untuk menampilkan data ke layar.

   ```cpp
   cout << "Masukkan angka: ";
   cout << "Nilai: " << angka << endl;
   ```

3. **Kombinasi Input-Output**  
   Data yang dimasukkan dapat langsung diproses dan hasilnya ditampilkan.

   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       int angka1, angka2;
       cout << "Masukkan angka pertama: ";
       cin >> angka1;
       cout << "Masukkan angka kedua: ";
       cin >> angka2;

       cout << "Penjumlahan : " << angka1 + angka2 << endl;
       cout << "Pengurangan : " << angka1 - angka2 << endl;
       return 0;
   }
   ```

---

### C. Array<br/>

Array merupakan kumpulan elemen dengan tipe data yang sama, disimpan dalam satu variabel, dan diakses melalui indeks tertentu.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai index ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "Isi index ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```

---

### D. Pointer<br/>

Pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain.  
Dengan pointer, kita bisa mengakses maupun mengubah nilai variabel yang ditunjuk.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << "Alamat: " << (ptr + i) << " \t Nilai: " << *(ptr + i) << endl;
    }

    return 0;
}
```

---

### E. Fungsi<br/>

Fungsi adalah kumpulan perintah yang dapat dipanggil berulang kali untuk menjalankan tugas tertentu.  
Dengan fungsi, program menjadi lebih terstruktur dan mudah dibaca.

```cpp
#include <iostream>
using namespace std;

int tambah(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    cout << "Masukkan angka pertama: ";
    cin >> x;
    cout << "Masukkan angka kedua: ";
    cin >> y;

    cout << "Hasil penjumlahan: " << tambah(x, y) << endl;
    return 0;
}
```

## Guided 

### 1. array_dimensi

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++)
    { cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5)
    { cout << "isi indeks ke-" << j << " : "<< arr[j] << endl;
        j++;
    }
    return 0;
}

```
Array 1 Dimensi

### 2. array_dua_dimensi

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)     //pengulangan kolom 2 kali karena 2 dimensi
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
         {1,2},
         {3,4}
    };
    int arrB[2][2] = {
         {2,3},  
         {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // Penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan Matriks: " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // Perkalian matriks 2x2
    for (int i = 0; i < 2; i++)             //pengulangan baris matriks A
    {
        for (int j = 0; j < 2; j++)         //pengulangan kolom matriks B
        {
            for (int k = 0; k < 2; k++)     //perulangan kolom matriks A atau baris matriks B
            {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian Matriks: " << endl;
    tampilkanHasil(arrD);

    return 0;

}
```
Array 2D

### 3. array_pointer

```C++
#include<iostream>
using namespace std;
 
int main(){
    int arr[]={10,20,30,40,50};
    int* ptr = arr; //deklarasi pointer ptr yang menunjuk ke array arr

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++)
    {
        cout << "Elemen ke-" << i+1 << "pointer"<<*(ptr + i) << endl; //menggunakan aritmatika pointer
    }

    //mengakses elemen array menggunakan indeks array
    for(int i = 0; i < 5; i++){
        cout << "Elemen ke-" << i+1 << "array" << arr[i] << endl; //mengunakan indeks array
    }

    return 0;
}
```
Program sederhana array pointer

### 4. function_prosedur

```C++
#include<iostream>
using namespace std;

int cariMax(int arr[],int ukuran){
    int max = arr[0]; //inisialisasi nilai maksimum dengan elemen pertama array
    for (int i = 1; i < ukuran; i++)
    {
        if (arr[i] > max) //jika elemen array lebih besar dari nilai maksimum saat ini
        {
            max = arr[i]; //perbarui nilai maksimum
        }
    }
    return max; //kembalikan nilai maksimum
}

void oprasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++)
    {
        totalJumlah += arr[i]; //menjumlahkan semua elemen array
    }
    cout << "Total Jumlah: " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++)
    {
        totalKali *= arr[i]; //mengalikan semua elemen array
    }
    cout << "Total Kali: " << totalKali << endl;

}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i  <<": ";
        cin >> arr[i]; //memasukkan elemen array dari input pengguna
    }
    cout << endl;
    cout << "Nilai Terbesar dalam Array: " << cariMax(arr, ukuran) << endl; //memanggil fungsi cariMax dan menampilkan hasilnya
    oprasiAritmatika(arr, ukuran); //memanggil prosedur oprasiAritmatika untuk melakukan operasi aritmatika pada array
    return 0;
}
```
Melakukan function_prosedur

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

### 6. Addational--- Call By Pointer & Call By Reference

```C++
#include<iostream>
using namespace std;
 
void ubahnilai(int *p){
    *p = 20; //mengubah nilai variabel yang ditunjuk pointer p
}

int main(){
    int x = 10;
    cout << "Nilai x sebelum diubah: " << x << endl;

    ubahnilai(&x); //mengirim alamat variabel x ke fungsi ubahnilai
    cout << "Nilai x setelah diubah: " << x << endl;

    return 0;
}
```
```C++
#include<iostream>
using namespace std;
 
void ubahnilai(int& ref){
    ref = 20; //mengubah nilai variabel yang direferensikan oleh ref
}

int main(){
    int x = 10;
    cout << "Nilai x sebelum diubah: " << x << endl;

    ubahnilai(x); //mengirim variabel x ke fungsi ubahnilai
    cout << "Nilai x setelah diubah: " << x << endl;

    return 0;
}
```
Memanggil dengan pointer nya dan refrensi nya

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian.

```C++
#include <iostream>
using namespace std;

const int N = 3;

void jumlahMatriks(int A[N][N], int B[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = A[i][j] + B[i][j];
}

void kurangMatriks(int A[N][N], int B[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = A[i][j] - B[i][j];
}

void kaliMatriks(int A[N][N], int B[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < N; k++)
                hasil[i][j] += A[i][k] * B[k][j];
        }
    }
}

void tampilMatriks(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int matriksA[N][N] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[N][N] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int hasil[N][N];
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Penjumlahan Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Pengurangan Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Perkalian Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan2_Modul2/Op/2_1.png)

Program ini mengajarkan penggunaan fungsi, array dua dimensi, dan struktur kontrol switch-case untuk melakukan operasi aritmetika matriks. Dengan pemisahan fungsi, kode menjadi lebih terstruktur, efisien, dan mudah dibaca.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan2_Modul2/Op/2_2.png)

Program ini menunjukkan bagaimana pointer bekerja sebagai alat pengakses langsung memori pada variabel lain. Dengan pointer, program dapat melakukan perhitungan dan modifikasi nilai secara efisien tanpa harus menggunakan variabel tambahan, sekaligus memperkuat pemahaman dasar tentang manipulasi alamat memori dalam C++.

## Kesimpulan
Kedua program ini menunjukkan penerapan dasar konsep penting dalam C++, yaitu fungsi (prosedur) dan pointer.
Program pertama memperlihatkan bagaimana fungsi dan struktur kontrol seperti loop dan switch–case digunakan untuk memproses data dalam bentuk array dua dimensi (matriks) secara modular, sehingga program lebih mudah dibaca dan dikembangkan.
Program kedua menekankan penggunaan pointer untuk mengakses dan memanipulasi nilai variabel secara langsung melalui alamat memori, yang menjadi fondasi penting dalam pemrograman tingkat lanjut seperti pengelolaan data dinamis dan struktur data kompleks.

## Referensi
<br/>[1] Technokrat Publishing. (2021). Dasar-Dasar Pemrograman dengan Bahasa C++. https://publishing.teknokrat.ac.id/dasar-dasar-pemrograman-dengan-bahasa-c/ 
<br/>[2] Jurnal Pendidikan Teknik Informatika (JPTK). (2019). Media Pembelajaran Bahasa Pemrograman C++. Universitas Pendidikan Ganesha. https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94 
<br/>[3] Jurnal Majemuk. (2020). Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik. https://jurnalilmiah.org/journal/index.php/majemuk/article/download/664/483/1442

