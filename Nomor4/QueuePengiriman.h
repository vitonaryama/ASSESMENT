#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan informasi satu paket
typedef struct {
    string KodeResi;       // Nomor resi paket
    string NamaPengirirm;  // Nama pengirim (tetap, tidak diubah strukturnya)
    int BeratBarang;       // Bobot paket dalam satuan tertentu
    string Tujuan;         // Lokasi tujuan pengiriman
} Paket;

const int MAX = 5; // kapasitas maksimal antrian

// Struktur antrian untuk mengelola daftar paket yang akan dikirim
typedef struct {
    Paket dataPaket[MAX];  // Array penyimpanan paket
    int Head;              // Penanda elemen terdepan
    int Tail;              // Penanda elemen terakhir
} QueueEkspedisi;

// Inisialisasi antrian agar siap digunakan
void createQueue(QueueEkspedisi &Q);

// Mengecek apakah antrian sedang kosong
bool isEmpty(QueueEkspedisi Q);

// Mengecek apakah antrian sudah penuh
bool isFull(QueueEkspedisi Q);

// Menambahkan paket baru ke dalam antrian
void enQueue(QueueEkspedisi &Q, Paket data);

// Menghapus paket paling depan dari antrian
void deQueue(QueueEkspedisi &Q);

// Menampilkan seluruh paket dalam antrian
void viewQueue(QueueEkspedisi Q);

// Menghitung total biaya pengiriman seluruh paket
int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
