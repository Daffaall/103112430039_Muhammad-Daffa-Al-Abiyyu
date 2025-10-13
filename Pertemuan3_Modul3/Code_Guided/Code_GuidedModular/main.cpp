#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    Mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata rata: " << rata2(mhs) << endl;

    system("pause");

    return 0;

}