#include<iostream>
using namespace std;
 
int main(){
    int arr[]={10,20,30,40,50};
    int* ptr = arr; //deklarasi pointer ptr yang menunjuk ke array arr

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++)
    {
        cout << "Elemen ke-" << i+1 << "pointer"<<*(ptr + i) << endl; //menggunakan aritmatika pointer
    }

    //mengakses elemen array menggunakan indeks array
    for(int i = 0; i < 5; i++){
        cout << "Elemen ke-" << i+1 << "array" << arr[i] << endl; //mengunakan indeks array
    }

    return 0;
}
