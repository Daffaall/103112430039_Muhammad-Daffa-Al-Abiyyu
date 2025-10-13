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