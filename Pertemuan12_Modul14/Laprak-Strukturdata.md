# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Muhammad Daffa Al Abiyyu - 103112430039</p>

## Dasar Teori
Graph adalah struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar objek atau entitas melalui kumpulan simpul (vertex) dan sisi (edge), di mana simpul menyatakan objek/data dan sisi menunjukkan hubungan antara simpul satu dengan yang lain dalam berbagai bentuk seperti graph berarah (directed) atau tak berarah (undirected) serta dapat direpresentasikan dengan adjacency list atau adjacency matrix untuk menggambarkan koneksi antar simpul secara efisien [1][2]. Representasi graph dengan adjacency list cocok untuk graf yang lebih “sparse” karena hanya menyimpan tetangga yang terhubung, sedangkan adjacency matrix menggunakan matriks dua dimensi untuk memetakan hubungan antara semua pasangan simpul yang ada [3]. Traversal atau penelusuran graph, seperti Breadth-First Search (BFS) dan Depth-First Search (DFS), merupakan algoritma fundamental yang digunakan untuk menjelajahi seluruh simpul dalam graph berdasarkan tingkat kedalaman atau level hubungan tertentu, serta memiliki aplikasi luas dalam jejaring sosial, rute terpendek, dan analisis jaringan kompleks lainnya [4].<br/>

## Dasar Pemrograman Graph
# # Dasar Pemrograman Graph

Dalam pemrograman struktur data, graph digunakan untuk merepresentasikan hubungan antar data yang bersifat tidak linier. Graph terdiri dari simpul (*vertex*) dan sisi (*edge*) yang menghubungkan antar simpul, sehingga cocok digunakan untuk memodelkan permasalahan dunia nyata seperti jaringan komputer, peta rute, media sosial, dan sistem relasi data yang kompleks.

## ## 1. Konsep Dasar Graph

Graph adalah struktur data yang terdiri dari kumpulan simpul dan sisi. Simpul merepresentasikan objek atau data, sedangkan sisi menunjukkan hubungan antara dua simpul.

Contoh deklarasi simpul dan sisi secara sederhana:

```cpp
struct Edge {
    int tujuan;
};

struct Vertex {
    int info;
};
```

---

## ## 2. Jenis-Jenis Graph

Graph dapat diklasifikasikan menjadi beberapa jenis, antara lain:

* **Graph Berarah (Directed Graph)**: edge memiliki arah tertentu
* **Graph Tidak Berarah (Undirected Graph)**: edge tidak memiliki arah
* **Graph Berbobot (Weighted Graph)**: setiap edge memiliki nilai bobot

Jenis graph dipilih sesuai kebutuhan permasalahan yang akan diselesaikan.

---

## ## 3. Representasi Graph

Graph dapat direpresentasikan ke dalam program dengan beberapa cara, yaitu:

### a. Adjacency Matrix

Menggunakan matriks dua dimensi untuk menunjukkan hubungan antar simpul.

```cpp
int graph[5][5];
```

### b. Adjacency List (Multi Linked List)

Menggunakan linked list untuk menyimpan daftar simpul yang saling terhubung.

```cpp
struct Node {
    int tujuan;
    Node* next;
};
```

Representasi adjacency list lebih efisien untuk graph dengan jumlah edge yang sedikit.

---

## ## 4. Traversal Graph

Traversal graph adalah proses penelusuran seluruh simpul dalam graph. Dua metode traversal utama adalah:

* **Breadth First Search (BFS)**: menelusuri graph berdasarkan level
* **Depth First Search (DFS)**: menelusuri graph berdasarkan kedalaman

Traversal digunakan untuk pencarian data, analisis hubungan, dan pemrosesan struktur graph.

---

## ## 5. Penerapan Graph

Graph banyak digunakan dalam berbagai bidang, seperti:

* Jaringan komputer
* Sistem navigasi dan pencarian rute
* Jejaring sosial
* Penjadwalan dan optimasi

Dengan menggunakan graph, hubungan antar data dapat dimodelkan secara sistematis dan efisien.

---

## Guided 

### 1. Graph
1. **Data graph.h** 

```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode*adrNode;
typedef struct ElmEdge*adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge {
    adrNode node;
    adrEdge next;
};
struct Graph {
    adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

```

2. **Data graph_edge.cpp** 

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        else {
        P = P->next;
        }
    }
    return NULL;
}


void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge-> node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```

3. **Data graph_init.cpp** 

```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

4. **Data graph_print.cpp** 

```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << "Terhuung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

5. **Data Main.cpp** 

```C++
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

## Unguided 

### 1. 

## File: `graph.cpp`
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode alokasiNode(infoGraph x) {
    adrNode p = new ElmNode;
    p->info = x;
    p->visited = 0;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

adrEdge alokasiEdge(adrNode p) {
    adrEdge e = new ElmEdge;
    e->node = p;
    e->next = NULL;
    return e;
}

void InsertNode(Graph &G, infoGraph x) {
    adrNode p = alokasiNode(x);
    if (G.first == NULL)
        G.first = p;
    else {
        adrNode q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

adrNode FindNode(Graph G, infoGraph x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

// graph tidak berarah
void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge e1 = alokasiEdge(N2);
    e1->next = N1->firstEdge;
    N1->firstEdge = e1;

    adrEdge e2 = alokasiEdge(N1);
    e2->next = N2->firstEdge;
    N2->firstEdge = e2;
}

void PrintInfoGraph(Graph G) {
    adrNode p = G.first;
    while (p != NULL) {
        cout << p->info << " -> ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}

```

## File: `graph.h`
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

// node graph
struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

// edge graph
struct ElmEdge {
    adrNode node;
    adrEdge next;
};

// graph
struct Graph {
    adrNode first;
};

// ADT
void CreateGraph(Graph &G);
adrNode alokasiNode(infoGraph x);
adrEdge alokasiEdge(adrNode p);

void InsertNode(Graph &G, infoGraph x);
adrNode FindNode(Graph G, infoGraph x);

void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif

```

## File: `main.cpp`
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, D);

    PrintInfoGraph(G);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided ](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan12_Modul14/Op/14_1.png)

Soal ini membahas pembuatan ADT Graph tidak berarah menggunakan adjacency list sebagai struktur dasar untuk merepresentasikan hubungan antar node.

### 2. 

## File: `graph.cpp`
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode CreateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph x) {
    adrNode P = CreateNode(x);
    if (G.first == NULL)
        G.first = P;
    else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge{N2, N1->firstEdge};
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge{N1, N2->firstEdge};
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// DFS
void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->Node);
            E = E->Next;
        }
    }
}

```

## File: `graph.h`
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

// ADT Graph
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph x);
adrNode FindNode(Graph G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

// DFS
void PrintDFS(Graph G, adrNode N);

#endif

```

## File: `main.cpp`
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));

    cout << "DFS: ";
    PrintDFS(G, FindNode(G,'A'));

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided ](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan12_Modul14/Op/14_2.png)

Soal ini menambahkan algoritma DFS pada ADT Graph untuk menelusuri node secara mendalam dari satu node ke node lainnya menggunakan metode rekursif.

### 3.


## File: `graph.cpp`
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode CreateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph x) {
    adrNode P = CreateNode(x);
    if (G.first == NULL)
        G.first = P;
    else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge{N2, N1->firstEdge};
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge{N1, N2->firstEdge};
    N2->firstEdge = E2;
}

// BFS
void PrintBFS(Graph G, adrNode N) {
    adrNode Q[50];
    int front = 0, rear = 0;

    N->visited = 1;
    Q[rear++] = N;

    while (front < rear) {
        adrNode P = Q[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q[rear++] = E->Node;
            }
            E = E->Next;
        }
    }
}

```

## File: `graph.h`
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

// ADT Graph
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph x);
adrNode FindNode(Graph G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

// BFS
void PrintBFS(Graph G, adrNode N);

#endif

```

## File: `main.cpp`
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));

    cout << "BFS: ";
    PrintBFS(G, FindNode(G,'A'));

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided ](https://github.com/Daffaall/103112430039_Muhammad-Daffa-Al-Abiyyu/blob/main/Pertemuan12_Modul14/Op/14_3.png)

Soal ini menambahkan algoritma BFS pada ADT Graph untuk menelusuri node berdasarkan level menggunakan struktur data queue.

## Kesimpulan
Pada praktikum ini dibuat ADT Graph tidak berarah sebagai dasar representasi hubungan antar node menggunakan adjacency list. Selanjutnya, graph tersebut dikembangkan dengan algoritma penelusuran DFS untuk menelusuri node secara mendalam dan BFS untuk menelusuri node berdasarkan level. Kedua metode penelusuran memanfaatkan penanda visited agar setiap node hanya dikunjungi satu kali, sehingga struktur dan alur penelusuran graph dapat dipahami dengan baik.

## Referensi
[1] Pengertian Struktur Data Graph: Jenis dan Kegunaannya – Trivusi. <br/>
[2] Mengenal Struktur Data Graph: Definisi dan Manfaat – BIF Telkom University. <br/>
[3] Adjacency Matrix dan Adjacency List – Scribd. <br/>
[4] Praktikum Struktur Data: Graph – Medium. <br/>