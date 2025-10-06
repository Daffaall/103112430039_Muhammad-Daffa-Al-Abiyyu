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