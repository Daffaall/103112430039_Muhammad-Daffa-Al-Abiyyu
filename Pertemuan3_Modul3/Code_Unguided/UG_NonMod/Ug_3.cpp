#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}

void tukarArray(int A[N][N], int B[N][N], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int *p1, *p2;

    cout << "--- Array A ---" << endl;
    tampilArray(A);
    cout << "\n--- Array B ---" << endl;
    tampilArray(B);

    tukarArray(A, B, 1, 1);
    cout << "\nSetelah menukar elemen [1][1]:" << endl;
    cout << "Array A:" << endl; tampilArray(A);
    cout << "Array B:" << endl; tampilArray(B);

    int x = 10, y = 20;
    p1 = &x;
    p2 = &y;
    tukarPointer(p1, p2);

    cout << "\nSetelah menukar melalui pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
