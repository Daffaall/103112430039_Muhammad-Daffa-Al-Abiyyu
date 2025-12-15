# <h1 align="center">Laporan Praktikum Modul 13  -  Multy Linked List</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Multi Linked List adalah salah satu bentuk perluasan dari linked list yang digunakan untuk merepresentasikan struktur data dengan hubungan kompleks antar elemen, di mana sebuah node dapat memiliki lebih dari satu pointer sehingga dapat terhubung ke berbagai node lainnya dalam relasi satu-ke-banyak atau banyak-ke-banyak. Linked list sendiri adalah struktur data dinamis yang terdiri dari node-node yang saling terhubung melalui pointer, memungkinkan penyisipan dan penghapusan data secara fleksibel tanpa memerlukan alokasi memori berurutan seperti pada array, sehingga memudahkan pengelolaan data yang sering berubah dalam sistem informasi, seperti pengelolaan data mahasiswa dalam konteks akademik [1][2]. Dalam Multi Linked List, setiap node tidak hanya menyimpan informasi dan satu pointer, tetapi juga menyimpan lebih dari satu pointer untuk menghubungkan elemen terkait lain, sehingga struktur ini efektif dalam memodelkan hubungan hierarkis atau relasional yang lebih kompleks dibanding linked list sederhana [3].<br/>

## Dasar Pemrograman Multi Linked List
# # Dasar Pemrograman Multi Linked List

Dalam struktur data, Multi Linked List merupakan pengembangan dari linked list yang memungkinkan satu node memiliki lebih dari satu hubungan atau pointer. Konsep ini digunakan untuk merepresentasikan relasi data yang lebih kompleks, seperti hubungan satu-ke-banyak atau banyak-ke-banyak, sehingga sering diterapkan pada sistem akademik, basis data, dan sistem informasi.

## ## 1. Konsep Dasar Linked List

Linked list adalah struktur data dinamis yang terdiri dari kumpulan node yang saling terhubung menggunakan pointer. Setiap node umumnya memiliki dua bagian, yaitu data (info) dan pointer ke node berikutnya (next).

Contoh struktur node linked list:

```cpp
struct Node {
    int info;
    Node* next;
};
```

Linked list bersifat fleksibel karena tidak memerlukan alokasi memori secara berurutan seperti array.

## ## 2. Pengertian Multi Linked List

Multi Linked List adalah struktur data di mana setiap node dapat memiliki lebih dari satu pointer untuk menghubungkan node lain. Struktur ini memungkinkan pembentukan hubungan data yang lebih kompleks, misalnya satu mahasiswa yang memiliki banyak mata kuliah.

Multi linked list biasanya terdiri dari:

* Node utama (parent)
* Node relasi (child)

## ## 3. Struktur Data Multi Linked List

Pada Multi Linked List, satu node dapat memiliki pointer ke node lain selain pointer ke node berikutnya.

Contoh struktur data mahasiswa dan mata kuliah:

```cpp
struct MataKuliah {
    string namaMk;
    MataKuliah* nextMk;
};

struct Mahasiswa {
    string namaMhs;
    Mahasiswa* nextMhs;
    MataKuliah* firstMk;
};
```

## ## 4. Operasi Dasar Multi Linked List

Operasi dasar yang dapat dilakukan pada Multi Linked List meliputi:

* Pembuatan list kosong
* Alokasi node parent dan child
* Penyisipan data
* Penghapusan data
* Pencarian data
* Penelusuran seluruh isi list

Operasi-operasi tersebut umumnya diimplementasikan menggunakan pointer dan teknik pemrograman modular.

## ## 5. Contoh Pengimplementasian Multi Linked List

Contoh penggunaan Multi Linked List pada relasi mahasiswa dan mata kuliah:

```cpp
insertMhs(first, alokasiMhs("Andi"));
insertMk(mhsAndi, alokasiMk("Struktur Data"));
insertMk(mhsAndi, alokasiMk("Algoritma"));
```

Dengan implementasi ini, satu mahasiswa dapat memiliki lebih dari satu mata kuliah tanpa harus melakukan duplikasi data.

## ## 6. Kelebihan Multi Linked List

Beberapa kelebihan Multi Linked List antara lain:

* Mampu merepresentasikan hubungan data yang kompleks
* Data lebih terstruktur dan fleksibel
* Efisien untuk sistem dengan banyak relasi

## Guided 

### 1. Multy Linked List
### multilist.h
```cpp
#ifndef MULTILIST_H
#define MULTILIST_H

#include <vector>
#include <string>
using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};
struct listAnak{
    NodeChild first;
    NodeChild last;
};
struct nodeParent{
    string idKategoriMakanan;
    string namaKategoriMakanan;
    listAnak daftarMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak ;
};
struct listInduk{
    NodeParent first;
    NodeParent last;
};
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void printStrukturMLL(listInduk &LInduk);

#endif
```
Program ini menunjukkan cara membuat dan menampilkan data menggunakan stack dalam C++.

## Guided 2

### 2. Data multilist
### multilist.cpp
```cpp
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

## Guided 3

### 2. Data multilist
### main.cppp
```cpp
#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl ;

    NodeChild M01 = alokasiNodeChild("M001", "Nasi Goreng");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M002", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    NodeChild S01 = alokasiNodeChild("S01", "Pudding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl ;

    printStrukturMLL(LInduk);
    cout << endl ;

    findChildByID(LInduk, "D01");
    cout << endl ;
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl ;
    deleteAfterParent(LInduk, K02);
    cout << endl ;  
    printStrukturMLL(LInduk);
    cout << endl ;
    return 0;
}
```

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”

```
Type Struct golonganHewan <
idGolongan : String
namaGolongan : String
>
Type Struct dataHewan <
idHewan : String
namaHewan : String
habitat : String
ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
bobot : float //dalam kg
>
typedef struct nodeParent *NodeParent; //alias pointer ke struct
nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct
nodeChild
Type Struct nodeChild <
isidata : dataHewan
next : NodeChild
prev : NodeChild
>
Type Struct listChild <
first : NodeChild
last : NodeChild
>
Type Struct nodeParent <
isidata : golonganHewan
next : NodeParent
prev : NodeParent
L_Child : listChild
>
Type Struct listParent <
first : NodeParent
last : NodeParent
>
Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
```
## File: `MultiLL.cpp`
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;


bool isEmptyParent(listParent &LParent) {
    return LParent.first == nullptr;
}

bool isEmptyChild(listChild &LChild) {
    return LChild.first == nullptr;
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = ekor;
    newNode->isidata.bobot = bobot;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != nullptr) {
        NParent->next = NParent->prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != nullptr) {
        NChild->next = NChild->prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent temp = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = nullptr;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = nullptr;
        }
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeParent temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(temp);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild temp = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = nullptr;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeChild temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        deallocNodeChild(temp);
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent tempParent = LParent.first;
    while (tempParent != nullptr) {
        cout << "=== Parent ===" << endl;
        cout << "ID Golongan: " << tempParent->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << tempParent->isidata.namaGolongan << endl;

        if (isEmptyChild(tempParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild tempChild = tempParent->L_Child.first;
            int childCount = 1;
            while (tempChild != nullptr) {
                cout << "  --> Child " << childCount++ << " :" << endl;
                cout << "      ID Hewan: " << tempChild->isidata.idHewan << endl;
                cout << "      Nama Hewan: " << tempChild->isidata.namaHewan << endl;
                cout << "      Habitat: " << tempChild->isidata.habitat << endl;
                cout << "      Ekor: " << (tempChild->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot: " << tempChild->isidata.bobot << endl;
                tempChild = tempChild->next;
            }
        }

        cout << "--------------------" << endl;
        tempParent = tempParent->next;
    }
}
```

## File: `MultiLL.h`
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

typedef struct golonganHewan {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; 
    float bobot; 
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);

#endif
```

## File: `main.cpp`
```C++
#include <iostream>
#include "MultiLL.h"

using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent p1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, p1);
    NodeParent p2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, p2);
    NodeParent p3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, p3);
    NodeParent p4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, p4);
    NodeParent p5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, p5);

    NodeChild c1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(p1->L_Child, c1);
    NodeChild c2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(p1->L_Child, c2);

    NodeChild c3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(p2->L_Child, c3);
    NodeChild c4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(p2->L_Child, c4);
    NodeChild c5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(p2->L_Child, c5);

    NodeChild c6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(p4->L_Child, c6);

    printMLLStructure(LParent);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 8_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan11_Modul13/Op/13_1.png)

Program ini mengimplementasikan Multi Linked List (MLL) dengan konsep parent–child menggunakan Doubly Linked List pada bahasa C++. Struktur parent merepresentasikan golongan hewan, sedangkan child merepresentasikan data hewan yang berada di dalam setiap golongan. Program telah menyediakan operasi lengkap seperti pembuatan list, alokasi dan dealokasi node, penambahan serta penghapusan data pada parent dan child, serta penampilan struktur data secara hierarkis. Dengan desain ini, data menjadi lebih terorganisir, mudah dikembangkan, dan efektif untuk merepresentasikan hubungan satu-ke-banyak dalam kasus pengelompokan hewan.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
## File: `MLL2.cpp`
```C++
#include "MLL2.h"

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot){
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = ekor;
    C->isidata.bobot = bobot;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &L, NodeParent P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild C){
    if(L.first == NULL){
        L.first = C;
        L.last = C;
    }else{
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void printMLLStructure(listParent L){
    NodeParent P = L.first;
    while(P != NULL){
        cout << "Golongan : " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while(C != NULL){
            cout << "  - " << C->isidata.namaHewan << endl;
            C = C->next;
        }
        P = P->next;
    }
}

/* ===== SEARCH HEWAN EKOR = FALSE ===== */
void searchHewanByEkor(listParent L, bool tail){
    NodeParent P = L.first;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while(C != NULL){
            if(C->isidata.ekor == tail){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->isidata.idGolongan << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "--------------------------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
    }
}
```

## File: `MLL2.h`
```C++
#ifndef MLL2_H
#define MLL2_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild C);

void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);

#endif
```

## File: `main.cpp`
```C++
#include "MLL2.h"

int main(){
    listParent L;
    createListParent(L);

    NodeParent G001 = allocNodeParent("G001","Aves");
    NodeParent G002 = allocNodeParent("G002","Mamalia");
    NodeParent G003 = allocNodeParent("G003","Pisces");
    NodeParent G004 = allocNodeParent("G004","Amfibi");
    NodeParent G005 = allocNodeParent("G005","Reptil");

    insertLastParent(L, G001);
    insertLastParent(L, G002);
    insertLastParent(L, G003);
    insertLastParent(L, G004);
    insertLastParent(L, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    printMLLStructure(L);

    cout << endl;
    searchHewanByEkor(L, false);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 8_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan11_Modul13/Op/13_2.png)

Berdasarkan program yang dibuat, dapat disimpulkan bahwa struktur Multi Linked List (MLL) efektif digunakan untuk merepresentasikan hubungan hierarkis antara golongan hewan (parent) dan data hewan (child). Implementasi double linked list pada parent dan child memungkinkan proses penambahan data, penelusuran, serta pencarian berjalan dengan terstruktur dan efisien. Program ini berhasil menampilkan seluruh data golongan beserta hewannya dan melakukan pencarian hewan berdasarkan atribut tertentu (ekor), sehingga menunjukkan bahwa konsep MLL dapat diterapkan dengan baik untuk mengelola data yang memiliki relasi satu-ke-banyak.

### 3.Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure().

## File: `MultiLL.cpp`
```C++
#include <iostream>
#include "MultiLL.h"

using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent p1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, p1);
    NodeParent p2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, p2);
    NodeParent p3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, p3);
    NodeParent p4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, p4);
    NodeParent p5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, p5);

    NodeChild c1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(p1->L_Child, c1);
    NodeChild c2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(p1->L_Child, c2);

    NodeChild c3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(p2->L_Child, c3);
    NodeChild c4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(p2->L_Child, c4);
    NodeChild c5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(p2->L_Child, c5);

    NodeChild c6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(p4->L_Child, c6);

    printMLLStructure(LParent);

    deleteNodeParent(LParent, "G002");
    printMLLStructure(LParent);

    return 0;
}
```

## File: `MultiLL.h`
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

typedef struct golonganHewan {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);

void deleteNodeParent(listParent &LParent, string idGol);

#endif
```

## File: `main.cpp`
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return LParent.first == nullptr;
}

bool isEmptyChild(listChild &LChild) {
    return LChild.first == nullptr;
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = ekor;
    newNode->isidata.bobot = bobot;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != nullptr) {
        NParent->next = NParent->prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != nullptr) {
        NChild->next = NChild->prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent temp = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = nullptr;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = nullptr;
        }
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeParent temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(temp);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild temp = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = nullptr;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeChild temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        deallocNodeChild(temp);
    }
}

void deleteNodeParent(listParent &LParent, string idGol) {
    NodeParent temp = LParent.first;
    while (temp != nullptr) {
        if (temp->isidata.idGolongan == idGol) {
          
            NodeChild tempChild = temp->L_Child.first;
            while (tempChild != nullptr) {
                NodeChild toDelete = tempChild;
                tempChild = tempChild->next;
                deallocNodeChild(toDelete);
            }
            deleteAfterParent(LParent, temp); 
            break;
        }
        temp = temp->next;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent tempParent = LParent.first;
    while (tempParent != nullptr) {
        cout << "=== Parent ===" << endl;
        cout << "ID Golongan: " << tempParent->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << tempParent->isidata.namaGolongan << endl;

        if (isEmptyChild(tempParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild tempChild = tempParent->L_Child.first;
            int childCount = 1;
            while (tempChild != nullptr) {
                cout << "  --> Child " << childCount++ << " :" << endl;
                cout << "      ID Hewan: " << tempChild->isidata.idHewan << endl;
                cout << "      Nama Hewan: " << tempChild->isidata.namaHewan << endl;
                cout << "      Habitat: " << tempChild->isidata.habitat << endl;
                cout << "      Ekor: " << (tempChild->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot: " << tempChild->isidata.bobot << endl;
                tempChild = tempChild->next;
            }
        }

        cout << "--------------------" << endl;
        tempParent = tempParent->next;
    }
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 8_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan11_Modul13/Op/13_3.png)

Program ini menunjukkan penerapan Multi Linked List (MLL) yang lebih lengkap dengan operasi penambahan, penampilan, dan penghapusan node parent beserta relasinya terhadap node child. Setiap golongan hewan direpresentasikan sebagai node parent yang memiliki list child berisi data hewan, sehingga hubungan satu-ke-banyak dapat dimodelkan dengan jelas. Fitur penghapusan node parent berdasarkan ID golongan membuktikan bahwa struktur MLL mampu menangani perubahan data secara dinamis tanpa merusak keterkaitan antar node lainnya. Dengan demikian, MLL sangat sesuai digunakan untuk pengelolaan data hierarkis yang kompleks dan saling berelasi.

## Kesimpulan
Berdasarkan keseluruhan implementasi yang dibuat, dapat disimpulkan bahwa penggunaan Multi Linked List (MLL) sangat tepat untuk mengelola data yang memiliki hubungan hierarkis satu-ke-banyak. Struktur ini memungkinkan penyimpanan data induk dan data turunan secara terorganisir, serta mendukung berbagai operasi penting seperti penambahan data, penelusuran seluruh struktur, pencarian data berdasarkan kriteria tertentu, dan penghapusan data secara dinamis. Dengan adanya keterkaitan yang jelas antara setiap elemen, MLL mampu menjaga konsistensi data dan mempermudah pengelolaan informasi yang saling berelasi dalam suatu sistem.

## Referensi
[1] Maria Triani Mbejo dkk., “Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa,” Jurnal Sains Informatika Terapan, 2025. <br/>
[2] “Linked List adalah struktur data linier berbentuk rantai simpul di mana setiap node berisi data dan pointer ke node berikutnya,” Trivusi, 2022. <br/>
[3] “Multiple Linked List merupakan linked list yang memiliki lebih dari dua pointer untuk setiap node,” Makalah Struktur Data Variasi Linked List. <br/>