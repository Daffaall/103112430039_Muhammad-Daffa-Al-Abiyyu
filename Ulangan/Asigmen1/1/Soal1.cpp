#include "Soal1.h"

Node* head = nullptr;

void insertAkhir(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (!head) {
        head = baru;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = baru;
}

bool deleteNama(string target) {
    if (!head) return false;

    Node* temp = head;
    Node* prev = nullptr;

    if (temp->nama == target) {
        head = temp->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->nama != target) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return false;

    prev->next = temp->next;
    delete temp;
    return true;
}

void view() {
    if (!head) {
        cout << "List kosong" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hitungGenap() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->nama.length() % 2 == 0)
            count++;
        temp = temp->next;
    }

    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

void asalamualikum() {
    printf("Asalamualaikum warahmatullahi wabarakatuh\n");
    printf("Saya Muhammad Daffa Al Abiyyu\n");
    printf("NIM 103112430039\n");
}