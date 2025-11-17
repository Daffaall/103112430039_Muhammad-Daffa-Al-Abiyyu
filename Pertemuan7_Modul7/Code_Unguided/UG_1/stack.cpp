#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotipe x) {
    if (S.top < MAX_STACK - 1) {
        S.top++;
        S.array[S.top] = x;
    }
}

infotipe pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.array[S.top];
        S.top--;
        return temp;
    }
    return -1; 
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.array[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// --------------------------------------------
// Tambahan: pushAscending
// Menyisipkan elemen sehingga stack tetap urut mengecil dari TOP
// --------------------------------------------
void pushAscending(Stack &S, infotipe x) {
    Stack temp;
    createStack(temp);

    // pindahkan elemen yang lebih kecil ke temp
    while (S.top >= 0 && S.array[S.top] < x) {
        push(temp, pop(S));
    }

    // masukkan elemen x
    push(S, x);

    // kembalikan elemen temp ke stack utama
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

// --------------------------------------------
// Tambahan: getInputStream
// Membaca input karakter sampai ENTER ditekan
// --------------------------------------------
void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;       // berhenti jika ENTER
        push(S, c - '0');           // konversi char → angka
    }
}
