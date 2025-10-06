#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)     //pengulangan kolom 2 kali karena 2 dimensi
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
         {1,2},
         {3,4}
    };
    int arrB[2][2] = {
         {2,3},  
         {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // Penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan Matriks: " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // Perkalian matriks 2x2
    for (int i = 0; i < 2; i++)             //pengulangan baris matriks A
    {
        for (int j = 0; j < 2; j++)         //pengulangan kolom matriks B
        {
            for (int k = 0; k < 2; k++)     //perulangan kolom matriks A atau baris matriks B
            {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian Matriks: " << endl;
    tampilkanHasil(arrD);

    return 0;

}