#include <iostream>
#include "Soal4.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    int pilih;
    do {
        cout << "\n=== MENU QUEUE PENGIRIMAN ===\n";
        cout << "1. Input Data Pengiriman\n";
        cout << "2. Hapus Antrian (Dequeue)\n";
        cout << "3. Lihat Semua Data\n";
        cout << "4. Total Biaya Pengiriman\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Paket P;
            cout << "Masukkan Nomor Resi   : ";
            cin >> P.Resi;
            cout << "Masukkan Nama Pengirim: ";
            cin >> P.Nama;
            cout << "Masukkan Tujuan       : ";
            cin >> P.Tujuan;
            cout << "Masukkan Berat (kg)   : ";
            cin >> P.Berat;

            enQueue(Q, P);
        }

        else if (pilih == 2) {
            deQueue(Q);
        }

        else if (pilih == 3) {
            cout << "\n=== DATA ANTRIAN ===\n";
            view(Q);
        }

        else if (pilih == 4) {
            cout << "\nTotal Biaya Pengiriman: " << TotalBiaya(Q) << endl;
        }

    } while (pilih != 5);

    return 0;
}
