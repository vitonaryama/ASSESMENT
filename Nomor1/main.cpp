#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main() {
    SinglyList inventory;
    createList(inventory);

    // Data produk awal
    Product item1 = {"Pulpen", "A001", 20, 2500.0, 0.0};
    Product item2 = {"BukuTulis", "A002", 15, 5000.0, 10.0};
    Product item3 = {"Penghapus", "A003", 30, 1580.0, 0.0};

    // Alokasi node untuk setiap produk
    Pointer N1 = allocateNode(item1.namaProduk, item1.kodeSKU, item1.stok, item1.hargaUnit, item1.persenDiskon);

    Pointer N2 = allocateNode(item2.namaProduk, item2.kodeSKU, item2.stok, item2.hargaUnit, item2.persenDiskon);

    Pointer N3 = allocateNode(item3.namaProduk, item3.kodeSKU, item3.stok, item3.hargaUnit, item3.persenDiskon);

    // Menambahkan node ke dalam list
    insertAtEnd(inventory, N1);
    insertAtEnd(inventory, N2);
    insertAtEnd(inventory, N3);

    cout << "Daftar seluruh produk yang tersimpan:\n";
    showList(inventory);

    cout << "\nPencarian produk berdasarkan rentang harga akhir (2000 - 7000):\n";
    searchByPriceRange(inventory, 2000.0f, 7000.0f);

    cout << "\nMengubah data pada posisi kedua:\n";
    Product itemBaru = {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    updateByPosition(inventory, 1, itemBaru);
    showList(inventory);

    // Bagian B: mencari harga akhir tertinggi
    cout << "\nProduk dengan harga akhir paling tinggi:\n";
    findMaxFinalPrice(inventory);

    return 0;
}
