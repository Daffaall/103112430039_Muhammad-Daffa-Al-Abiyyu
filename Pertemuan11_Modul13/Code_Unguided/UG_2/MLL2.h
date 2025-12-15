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