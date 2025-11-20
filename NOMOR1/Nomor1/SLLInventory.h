#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define NIL NULL

// Struktur untuk menyimpan informasi produk
struct Product {
    string namaProduk;
    string kodeSKU;
    int stok;
    float hargaUnit;
    float persenDiskon;
};

typedef Product ItemProduct;
typedef struct Node *Pointer;

// Node tunggal berisi data produk dan pointer ke node berikutnya
struct Node {
    ItemProduct data;
    Pointer next;
};

// Struktur list dengan pointer ke elemen pertama
struct SinglyList {
    Pointer head;
};

// Prototipe fungsi-fungsi list
bool isEmpty(SinglyList L);
void createList(SinglyList &L);
Pointer allocateNode(string nama, string sku, int qty, float harga, float diskon);
void deallocateNode(Pointer &P);
void printList(SinglyList L);

// Operasi insert
void insertAtFront(SinglyList &L, Pointer newNode);
void insertAfterNode(SinglyList &L, Pointer newNode, Pointer prevNode);
void insertAtEnd(SinglyList &L, Pointer newNode);

// Operasi delete
void deleteFront(SinglyList &L, Pointer &deletedNode);
void deleteAfterNode(SinglyList &L, Pointer &deletedNode, Pointer prevNode);
void deleteEnd(SinglyList &L, Pointer &deletedNode);

// Update dan tampilan data
void updateByPosition(SinglyList &L, int posisi, ItemProduct produkBaru);
void showList(SinglyList L);

// Fitur pencarian dan analisis harga
void searchByPriceRange(SinglyList L, float minHarga, float maxHarga);
void findMaxFinalPrice(SinglyList L); // Bagian B

#endif
