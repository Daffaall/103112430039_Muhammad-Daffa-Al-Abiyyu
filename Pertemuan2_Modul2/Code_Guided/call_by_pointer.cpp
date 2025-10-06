#include<iostream>
using namespace std;
 
void ubahnilai(int *p){
    *p = 20; //mengubah nilai variabel yang ditunjuk pointer p
}

int main(){
    int x = 10;
    cout << "Nilai x sebelum diubah: " << x << endl;

    ubahnilai(&x); //mengirim alamat variabel x ke fungsi ubahnilai
    cout << "Nilai x setelah diubah: " << x << endl;

    return 0;
}