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
