#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(SinglyList L) {
    return (L.head == NIL);
}

void createList(SinglyList &L) {
    L.head = NIL;
}

Pointer allocateNode(string nama, string sku, int qty, float hargaUnit, float diskon) {
    Pointer P = new Node;
    P->data.namaProduk = nama;
    P->data.kodeSKU = sku;
    P->data.stok = qty;
    P->data.hargaUnit = hargaUnit;
    P->data.persenDiskon = diskon;
    P->next = NIL;
    return P;
}

void deallocateNode(Pointer &P) {
    P->next = NIL;
    delete P;
}

// INSERT OPERATIONS

void insertAtFront(SinglyList &L, Pointer newNode) {
    newNode->next = L.head;
    L.head = newNode;
}

void insertAfterNode(SinglyList &L, Pointer newNode, Pointer prevNode) {
    if (prevNode != NIL) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertAtEnd(SinglyList &L, Pointer newNode) {
    if (isEmpty(L)) {
        L.head = newNode;
    } else {
        Pointer last = L.head;
        while (last->next != NIL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// DELETE OPERATIONS

void deleteFront(SinglyList &L, Pointer &deletedNode) {
    if (!isEmpty(L)) {
        deletedNode = L.head;
        L.head = L.head->next;
        deletedNode->next = NIL;
    } else {
        deletedNode = NIL;
        cout << "List kosong!" << endl;
    }
}

void deleteAfterNode(SinglyList &L, Pointer &deletedNode, Pointer prevNode) {
    if (prevNode != NIL && prevNode->next != NIL) {
        deletedNode = prevNode->next;
        prevNode->next = deletedNode->next;
        deletedNode->next = NIL;
    } else {
        deletedNode = NIL;
        cout << "Node sebelumnya tidak valid atau tidak ada node setelahnya!" << endl;
    }
}

void deleteEnd(SinglyList &L, Pointer &deletedNode) {
    if (!isEmpty(L)) {
        if (L.head->next == NIL) {
            deletedNode = L.head;
            L.head = NIL;
        } else {
            Pointer prev = NIL;
            Pointer curr = L.head;

            while (curr->next != NIL) {
                prev = curr;
                curr = curr->next;
            }

            deletedNode = curr;
            prev->next = NIL;
        }
    } else {
        deletedNode = NIL;
        cout << "List kosong!" << endl;
    }
}

// UPDATE + DISPLAY

void updateByPosition(SinglyList &L, int posisi, ItemProduct newData) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }

    Pointer curr = L.head;
    int index = 0;

    while (curr != NIL && index < posisi) {
        curr = curr->next;
        index++;
    }

    if (curr != NIL) {
        curr->data = newData;
    } else {
        cout << "Posisi tidak ditemukan." << endl;
    }
}

void showList(SinglyList L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    Pointer curr = L.head;
    int posisi = 1;

    while (curr != NIL) {
        cout << "Produk #" << posisi << endl;
        cout << "Nama        : " << curr->data.namaProduk << endl;
        cout << "SKU         : " << curr->data.kodeSKU << endl;
        cout << "Jumlah      : " << curr->data.stok << endl;
        cout << "Harga       : " << curr->data.hargaUnit << endl;
        cout << "Diskon      : " << curr->data.persenDiskon << "%" << endl;
        cout << "-----------------------------" << endl;
        curr = curr->next;
        posisi++;
    }
}

// SEARCH & ANALYSIS

void searchByPriceRange(SinglyList L, float minHarga, float maxHarga) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    Pointer curr = L.head;
    bool ketemu = false;

    while (curr != NIL) {
        float hargaAkhir = curr->data.hargaUnit * (1 - curr->data.persenDiskon / 100);

        if (hargaAkhir >= minHarga && hargaAkhir <= maxHarga) {
            cout << "Produk dalam rentang harga ditemukan:" << endl;
            cout << "Nama        : " << curr->data.namaProduk << endl;
            cout << "SKU         : " << curr->data.kodeSKU << endl;
            cout << "Jumlah      : " << curr->data.stok << endl;
            cout << "Harga       : " << curr->data.hargaUnit << endl;
            cout << "Diskon      : " << curr->data.persenDiskon << "%" << endl;
            cout << "Harga Akhir : " << hargaAkhir << endl;
            cout << "-----------------------------" << endl;
            ketemu = true;
        }

        curr = curr->next;
    }

    if (!ketemu) {
        cout << "Tidak ada produk dalam rentang harga tersebut." << endl;
    }
}

void findMaxFinalPrice(SinglyList L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    Pointer curr = L.head;
    Pointer maxNode = curr;

    float hargaMax = curr->data.hargaUnit * (1 - curr->data.persenDiskon / 100);

    curr = curr->next;

    while (curr != NIL) {
        float hargaTemp = curr->data.hargaUnit * (1 - curr->data.persenDiskon / 100);

        if (hargaTemp > hargaMax) {
            hargaMax = hargaTemp;
            maxNode = curr;
        }

        curr = curr->next;
    }

    cout << "Produk dengan harga akhir tertinggi:" << endl;
    cout << "Nama        : " << maxNode->data.namaProduk << endl;
    cout << "SKU         : " << maxNode->data.kodeSKU << endl;
    cout << "Jumlah      : " << maxNode->data.stok << endl;
    cout << "Harga       : " << maxNode->data.hargaUnit << endl;
    cout << "Diskon      : " << maxNode->data.persenDiskon << "%" << endl;
    cout << "Harga Akhir : " << hargaMax << endl;
}
