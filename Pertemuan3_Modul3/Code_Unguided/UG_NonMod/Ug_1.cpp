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
