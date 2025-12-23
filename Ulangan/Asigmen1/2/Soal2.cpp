#include "Soal2.h"

Node* head = nullptr;
Node* tail = nullptr;

void insertAkhir(int nilai) {
    Node* baru = new Node{nilai, nullptr, nullptr};

    if (!head) {  
        head = tail = baru;
        return;
    }

    tail->next = baru;
    baru->prev = tail;
    tail = baru;
}

void deleteTerakhir() {
    if (!tail) return;

    Node* hapus = tail;

    if (head == tail) {
        head = tail = nullptr;
        delete hapus;
        return;
    }

    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void viewDepan() {
    if (!head) {
        cout << "List kosong" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nilai << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* curr = head;
    Node* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if (temp != nullptr)
        head = temp->prev;

    cout << "List setelah di-reverse: ";
    viewDepan();
}
void aslimalas() {
    printf("Asli malas banget ya bikin fungsi untuk keluarin list\n");
    printf("Yah sudahlah, yang penting selesai");
}
