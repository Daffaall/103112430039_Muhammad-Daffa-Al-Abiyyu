#include "Soal3.h"

bool isEmpty(StackMahasiswa &S) {
    return S.top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) return;
    S.top++;
    S.data[S.top] = M;
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) return;
    S.top--;
}

void Update(StackMahasiswa &S, int pos, Mahasiswa M) {
    if (pos < 0 || pos > S.top) return;
    S.data[pos] = M;
}

float HitungNilaiAkhir(Mahasiswa M) {
    return 0.2*M.NilaiTugas + 0.4*M.NilaiUTS + 0.4*M.NilaiUAS;
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "\nIsi Stack:\n";
    for (int i = S.top; i >= 0; i--) {
        cout << i << ". " 
             << S.data[i].Nama << " | " 
             << S.data[i].NIM << " | "
             << HitungNilaiAkhir(S.data[i]) << "\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float minA, float maxA) {
    for (int i = 0; i <= S.top; i++) {
        float NA = HitungNilaiAkhir(S.data[i]);
        if (NA >= minA && NA <= maxA) {
            cout << "Posisi " << i << ": " << S.data[i].Nama 
                 << " (" << NA << ")\n";
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) return;
    float maxNA = HitungNilaiAkhir(S.data[0]);
    int pos = 0;
    for (int i = 1; i <= S.top; i++) {
        float NA = HitungNilaiAkhir(S.data[i]);
        if (NA > maxNA) {
            maxNA = NA;
            pos = i;
        }
    }
    cout << "\nNilai akhir terbesar:\n";
    cout << S.data[pos].Nama << " | " << S.data[pos].NIM 
         << " | " << maxNA << "\n";
}
