#include "graph.h"

// Membuat graph kosong
void CreateGraph(Graph &G) {
    G.first = NULL;
}

// Membuat node baru
adrNode CreateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Insert node ke graph
void InsertNode(Graph &G, infoGraph x) {
    adrNode P = CreateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

// Cari node
adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return NULL;
}

// Hubungkan dua node (tidak berarah)
void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

// Cetak graph
void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

// DFS (rekursif)
void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->node);
            E = E->next;
        }
    }
}

// BFS (queue manual)
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
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q[rear++] = E->node;
            }
            E = E->next;
        }
    }
}
