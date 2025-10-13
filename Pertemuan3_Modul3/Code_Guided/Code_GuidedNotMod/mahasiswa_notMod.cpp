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