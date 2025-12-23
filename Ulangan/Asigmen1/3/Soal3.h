#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int pos, Mahasiswa M);
void View(StackMahasiswa &S);
float HitungNilaiAkhir(Mahasiswa M);
void SearchNilaiAkhir(StackMahasiswa &S, float minA, float maxA);
void MaxNilaiAkhir(StackMahasiswa &S);

#endif
