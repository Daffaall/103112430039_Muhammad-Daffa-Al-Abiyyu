#include<iostream>
using namespace std;
 
void ubahnilai(int& ref){
    ref = 20; //mengubah nilai variabel yang direferensikan oleh ref
}

int main(){
    int x = 10;
    cout << "Nilai x sebelum diubah: " << x << endl;

    ubahnilai(x); //mengirim variabel x ke fungsi ubahnilai
    cout << "Nilai x setelah diubah: " << x << endl;

    return 0;
}