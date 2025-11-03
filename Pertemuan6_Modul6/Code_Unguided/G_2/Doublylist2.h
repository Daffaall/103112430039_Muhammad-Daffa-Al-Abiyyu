#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H
#include <string>
using namespace std;


struct kendaraan2 {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan2 infotype2;

struct ElmList2;
typedef ElmList2* address2;

struct ElmList2 {
    infotype2 info;
    address2 next;
    address2 prev;
};

struct List2 {
    address2 first;
    address2 last;
};


void createList2(List2 &L);
address2 alokasi2(infotype2 x);
void dealokasi2(address2 &P);
void printInfo2(List2 L);
void insertLast2(List2 &L, address2 P);
bool isDuplicate2(List2 L, string nopol);
address2 findElm2(List2 L, string nopol);

#endif
