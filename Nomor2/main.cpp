#include "DLLPlaylist.h"

int main() {
    linkedlist playlist;
    createList(playlist);

    // Data awal lagu
    song a;
    a.Title = "Senja di Kota";
    a.Artist = "Nona Band";
    a.DurationSec = 210;
    a.PlayCount = 150;
    a.Rating = 4.2f;

    song b;
    b.Title = "Langkahmu";
    b.Artist = "Delta";
    b.DurationSec = 185;
    b.PlayCount = 320;
    b.Rating = 4.8f;

    song c;
    c.Title = "Hujan Minggu";
    c.Artist = "Arka";
    c.DurationSec = 240;
    c.PlayCount = 90;
    c.Rating = 3.9f;

    // Insert awal
    insertLast(playlist, allocate(a));
    insertLast(playlist, allocate(b));
    insertLast(playlist, allocate(c));

    cout << "== Daftar Lagu Setelah Insert ==\n";
    viewList(playlist);
    cout << "\n";

    // delete last
    song temp;
    deleteLast(playlist, temp);
    cout << "\n";

    cout << "== Daftar Lagu Setelah deleteLast ==\n";
    viewList(playlist);
    cout << "\n";

    // Update data di posisi tertentu
    song updated;
    updated.Title = "Pelita";
    updated.Artist = "Luna";
    updated.DurationSec = 200;
    updated.PlayCount = 260;
    updated.Rating = 4.5f;

    updateAtPosition(playlist, 2, updated);
    cout << "\n";

    cout << "== Daftar Lagu Setelah Update Posisi ke-2 ==\n";
    viewList(playlist);
    cout << "\n";

    // Insert sebelum node tertentu
    address node2 = getNodeAtPosition(playlist, 2);
    song d;
    d.Title = "Senandung";
    d.Artist = "Mira";
    d.DurationSec = 175;
    d.PlayCount = 120;
    d.Rating = 4.0f;

    insertBefore(playlist, node2, allocate(d));
    cout << "== Daftar Lagu Setelah insertBefore Posisi ke-2 ==\n";
    viewList(playlist);
    cout << "\n";

    // Update node sebelum node posisi 2
    updateBefore(playlist, node2);
    cout << "\n";

    cout << "== Daftar Lagu Setelah updateBefore Node Posisi ke-2 ==\n";
    viewList(playlist);
    cout << "\n";

    // Delete node sebelum node posisi 3
    address node3 = getNodeAtPosition(playlist, 3);
    deleteBefore(playlist, node3, temp);
    cout << "\n";

    cout << "== Daftar Lagu Setelah deleteBefore Node Posisi ke-3 ==\n";
    viewList(playlist);
    cout << "\n";

    // Searching popularitas
    cout << "== Hasil Pencarian Popularity Score ==\n";
    searchByPopularityRange(playlist, 150.0f, 300.0f);
    cout << "\n";

    return 0;
}
