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