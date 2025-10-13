#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi class Mahasiswa
struct Mahasiswa {
    char nim[10]; //atribut nim
    int nilai1,nilai2; /* data */
};

//Deklarasi fungsi
void inputMhs(Mahasiswa &m);
float rata2(Mahasiswa m);

#endif//fungsi untuk input data