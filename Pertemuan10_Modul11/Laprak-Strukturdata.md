# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Rekursif adalah metode pemrograman di mana suatu fungsi memanggil dirinya sendiri untuk menyelesaikan masalah yang dapat dipecah menjadi submasalah yang lebih kecil, dengan syarat memiliki kondisi dasar (base case) sebagai penghenti agar tidak terjadi pemanggilan tak berujung [1]. Struktur data tree merupakan model hierarki yang tersusun atas node–node yang saling terhubung, dengan node akar sebagai pusat dan node lain sebagai parent maupun child yang membentuk hubungan bertingkat [2]. Salah satu bentuk tree adalah binary tree, yaitu struktur di mana setiap node memiliki maksimal dua child sehingga memudahkan proses traversal dan pemetaan data [3]. Binary Search Tree (BST) merupakan turunan binary tree dengan aturan bahwa nilai pada child kiri selalu lebih kecil dari parent dan nilai pada child kanan lebih besar, menjadikannya efisien untuk operasi pencarian dan pengurutan data [4].<br/>

## Dasar Pemrograman Rekursif & Tree

Dalam struktur data tingkat lanjut, rekursif dan tree adalah dua konsep dasar yang sangat penting. Rekursif digunakan untuk menyelesaikan masalah yang bersifat berulang, sedangkan tree digunakan untuk merepresentasikan data secara hierarki.

## 1. Rekursif (Recursive Function)
Rekursif adalah teknik pemrograman di mana suatu fungsi memanggil dirinya sendiri sampai mencapai kondisi tertentu.

Contoh fungsi rekursif:
```cpp
int faktorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * faktorial(n - 1);
}
```

## 2. Kriteria Rekursif
- Base Case → kondisi berhenti
- Recursive Call → pemanggilan fungsi kembali

```cpp
if (kondisi_berhenti) {
    // berhenti
} else {
    // panggil diri sendiri
}
```

## 3. Kekurangan Rekursif
- Menggunakan memori lebih banyak
- Lebih lambat pada kasus tertentu
- Risiko infinite recursion jika base case salah

## 4. Pengertian Tree
Tree adalah struktur data non-linear berupa hirarki.

```cpp
struct Node {
    int info;
    Node* left;
    Node* right;
};
```

### Istilah Penting
- Root
- Parent
- Child
- Leaf
- Sibling
- Degree
- Height

## 5. Jenis-Jenis Tree

### A. Ordered Tree
Tree dengan urutan anak yang penting.

### B. Binary Tree
Setiap node memiliki maksimal dua anak.

### C. Complete Binary Tree
Level tree terisi penuh dari kiri ke kanan.

### D. Extended Binary Tree
Node memiliki 0 atau 2 anak.

### E. Binary Search Tree (BST)
- Left Child < Parent
- Right Child > Parent

## 6. Operasi pada BST

### Insert
Menambahkan node sesuai aturan BST.

### Search
Mencari node berdasarkan nilai.

### Delete
Menghapus node (leaf, satu anak, atau dua anak).

### Most-Left & Most-Right
Node dengan nilai paling kecil & paling besar.

## 7. Traversal pada Tree

### Pre-order
Root → Left → Right

### In-order
Left → Root → Right

### Post-order
Left → Right → Root

### 1. Rekrusif

```C++
#include <iostream>
using namespace std;

int pangkat_2(int x) {
    // Basis
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x - 1);
    }
}
int main() {
    cout << "=====REKRUSIF PANGKAT 2=====" << endl;
    int x;
    cout << "Masukkax xilai x: ";
    cin >> x;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x) << endl;
    return 0;
}

```

### 2. Bstree 1
1. **Data BST1.h** 

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;
typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
#endif

```

2. **Data Queue.cpp** 

```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

3. **Data Main.cpp** 

```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

### 3. Bstree 2
1. **Data BST2.h** 

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;
typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
void searchByData(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
bool deleteNode(address &root, infotype x);
void deleteTree(address &root);
#endif
```

2. **Data Queue.cpp** 

```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

3. **Data Main.cpp** 

```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}

```
## Unguided 

### 1. (https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/soal1.png)

## File: `bstree.cpp`
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

address findNode(infotype x, address root) {
    if (root == NULL)
        return NULL;
    else if (x == root->info)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

```

## File: `bstree.h`
```C
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 8_1](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/11_1.png)

Nomor 1 meminta pembuatan struktur data Binary Search Tree (BST) menggunakan pointer, di mana setiap node memiliki nilai serta pointer ke anak kiri dan kanan, dengan aturan bahwa nilai lebih kecil ditempatkan pada subtree kiri dan nilai lebih besar pada subtree kanan. Fungsi yang dibuat meliputi alokasi untuk membuat node baru, insertNode untuk menyisipkan nilai sesuai aturan BST, findNode untuk mencari nilai tertentu, dan InOrder untuk mencetak seluruh isi tree secara terurut dari kecil ke besar.

### 2. (https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/soal2.png)
    (https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/soal2_2.png)
## File: `bstree.cpp`
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return max(kiri, kanan);
}

```

## File: `bstree.h`
```C
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 8_2](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/11_2.png)

Nomor 2 menambahkan tiga fungsi rekursif untuk melakukan perhitungan terhadap tree, yaitu hitungJumlahNode untuk menghitung total node yang ada dalam BST, hitungTotalInfo untuk menjumlahkan seluruh nilai (info) di dalam tree, dan hitungKedalaman untuk menentukan kedalaman atau tinggi tree berdasarkan jalur terpanjang dari root ke leaf. Ketiga fungsi ini memanfaatkan sifat rekursif tree yang terbentuk dari struktur bercabang kiri dan kanan.

### 3.(https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/soa3.png)

## File: `bstree.cpp`
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void PreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " - ";
    }
}

```

## File: `bstree.h`
```C
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);

void PreOrder(address root);
void PostOrder(address root);

#endif

```

## File: `main.cpp`
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;

    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);

    cout << "PreOrder : ";
    PreOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;

    return 0;
}
a
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 8_3](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan10_Modul11/Op/11_3.png)

Nomor 3 meminta implementasi dua jenis traversal tambahan pada BST, yaitu PreOrder yang mencetak nilai dengan urutan Root–Left–Right dan PostOrder yang mencetak dengan urutan Left–Right–Root. Kedua traversal ini digunakan untuk berbagai kebutuhan seperti penelusuran struktur tree, pemrosesan node secara hierarkis, dan pengujian bentuk pohon, serta melengkapi traversal InOrder yang sudah dibuat pada nomor sebelumnya.

## Kesimpulan
Melalui tiga tahapan tugas ini, dapat disimpulkan bahwa Binary Search Tree (BST) merupakan struktur data hierarkis yang efektif untuk penyimpanan dan pencarian data secara terurut. Implementasi dasar pada nomor 1 menunjukkan bagaimana node dibuat dan disisipkan sesuai aturan BST, sehingga data dapat diakses melalui traversal InOrder. Pada nomor 2, berbagai fungsi rekursif diterapkan untuk menghitung karakteristik pohon seperti jumlah node, total nilai, dan kedalaman tree, yang menggambarkan sifat rekursif dari struktur tree. Nomor 3 melengkapi pemahaman dengan menambahkan traversal PreOrder dan PostOrder, yang masing-masing digunakan untuk menelusuri tree berdasarkan pola tertentu. Secara keseluruhan, tugas ini memperkuat pemahaman tentang konsep BST dan penerapannya dalam pemrograman menggunakan C++.

## Referensi
[1] L.J.E. Dewi, “Media Pembelajaran Bahasa Pemrograman C++,” Jurnal Pendidikan Teknologi dan Kejuruan, Universitas Pendidikan Ganesha, 2016.<br/>
[2] R. Primadani, “Struktur Data Tree dalam Implementasi Sistem Informasi,” Jurnal Teknologi Informasi dan Pendidikan, 2019.<br/>
[3] R. Rismayati, “Analisis Struktur Data Binary Tree pada Pengembangan Sistem,” Jurnal Ilmiah Komputer dan Informatika (KOMPUTA), 2018.<br/>
[4] S. Supriyanto, “Penerapan Binary Search Tree pada Proses Pencarian Data,” Jurnal Teknologi dan Sistem Informasi, 2020.<br/>