#include "DLLPlaylist.h"
#include <iomanip>
#include <cmath>

bool isEmpty(const linkedlist &L) {
    return (L.head == Nil);
}

void createList(linkedlist &L) {
    L.head = Nil;
    L.tail = Nil;
}

address allocate(const song &S) {
    address P = new node;
    P->info = S;
    P->prev = Nil;
    P->next = Nil;
    return P;
}

void deallocate(address &P) {
    if (P == Nil) return;
    P->prev = Nil;
    P->next = Nil;
    delete P;
    P = Nil;
}

void insertFirst(linkedlist &L, address newNode) {
    if (newNode == Nil) return;
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

void insertLast(linkedlist &L, address newNode) {
    if (newNode == Nil) return;
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void insertAfter(linkedlist &L, address Q, address newNode) {
    if (Q == Nil || newNode == Nil) return;
    if (Q == L.tail) {
        insertLast(L, newNode);
    } else {
        newNode->next = Q->next;
        newNode->prev = Q;
        Q->next->prev = newNode;
        Q->next = newNode;
    }
}

void insertBefore(linkedlist &L, address Q, address newNode) {
    if (Q == Nil || newNode == Nil) return;
    if (Q == L.head) {
        insertFirst(L, newNode);
    } else {
        newNode->prev = Q->prev;
        newNode->next = Q;
        Q->prev->next = newNode;
        Q->prev = newNode;
    }
}

void deleteFirst(linkedlist &L, song &S) {
    if (isEmpty(L)) {
        cout << "List masih kosong, tidak ada node yang bisa dihapus.\n";
        return;
    }

    address P = L.head;
    S = P->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.head = P->next;
        if (L.head != Nil) L.head->prev = Nil;
    }

    cout << "Elemen \"" << S.Title << "\" telah dihapus dari awal list.\n";
    deallocate(P);
}

void deleteLast(linkedlist &L, song &S) {
    if (isEmpty(L)) {
        cout << "List masih kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    address P = L.tail;
    S = P->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.tail = P->prev;
        if (L.tail != Nil) L.tail->next = Nil;
    }

    cout << "Elemen \"" << S.Title << "\" dihapus dari bagian akhir list.\n";
    deallocate(P);
}

void deleteAfter(linkedlist &L, address Q, song &S) {
    if (isEmpty(L) || Q == Nil || Q->next == Nil) {
        cout << "Tidak dapat menghapus: referensi tidak valid atau list kosong.\n";
        return;
    }

    address P = Q->next;
    S = P->info;

    if (P == L.tail) {
        deleteLast(L, S);
        return;
    }

    Q->next = P->next;
    if (P->next != Nil) P->next->prev = Q;

    cout << "Node \"" << S.Title << "\" berhasil dihapus setelah \"" << Q->info.Title << "\".\n";
    deallocate(P);
}

void deleteBefore(linkedlist &L, address Q, song &S) {
    if (isEmpty(L) || Q == Nil || Q->prev == Nil) {
        cout << "Tidak dapat menghapus: referensi tidak valid atau list kosong.\n";
        return;
    }

    address P = Q->prev;
    S = P->info;

    if (P == L.head) {
        deleteFirst(L, S);
        return;
    }

    if (P->prev != Nil) P->prev->next = Q;
    Q->prev = P->prev;

    cout << "Node \"" << S.Title << "\" dihapus sebelum \"" << Q->info.Title << "\".\n";
    deallocate(P);
}

void deleteNode(linkedlist &L, address target) {
    if (isEmpty(L) || target == Nil) {
        cout << "List kosong atau node target tidak valid.\n";
        return;
    }

    if (target == L.head) {
        song tmp;
        deleteFirst(L, tmp);
    } else if (target == L.tail) {
        song tmp;
        deleteLast(L, tmp);
    } else {
        address Ls = target->prev;
        address Rs = target->next;
        if (Ls != Nil) Ls->next = Rs;
        if (Rs != Nil) Rs->prev = Ls;
        cout << "Node \"" << target->info.Title << "\" dihapus dari tengah list.\n";
        deallocate(target);
    }
}

void updateAtPosition(linkedlist &L, int posisi, const song &newData) {
    if (isEmpty(L)) {
        cout << "List masih kosong.\n";
        return;
    }
    if (posisi <= 0) {
        cout << "Posisi tidak valid!\n";
        return;
    }

    address P = getNodeAtPosition(L, posisi);
    if (P == Nil) {
        cout << "Tidak ditemukan node pada posisi " << posisi << ".\n";
        return;
    }

    P->info = newData;
    cout << "Data pada posisi " << posisi << " berhasil diperbarui.\n";
}

void updateBefore(linkedlist &L, address nodeNext) {
    if (isEmpty(L) || nodeNext == Nil || nodeNext->prev == Nil) {
        cout << "Node sebelumnya tidak valid atau list kosong.\n";
        return;
    }

    address P = nodeNext->prev;

    cout << "Update data node sebelum \"" << nodeNext->info.Title << "\":\n";

    cout << "Title : ";
    getline(cin, P->info.Title);
    cout << "Artist : ";
    getline(cin, P->info.Artist);

    cout << "DurationSec : ";
    cin >> P->info.DurationSec;
    cout << "PlayCount : ";
    cin >> P->info.PlayCount;
    cout << "Rating : ";
    cin >> P->info.Rating;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Data berhasil diperbarui!\n";
}

float popularityScore(const song &s) {
    return 0.8f * static_cast<float>(s.PlayCount) + 20.0f * s.Rating;
}

void viewList(const linkedlist &L) {
    if (isEmpty(L)) {
        cout << "List masih kosong.\n";
        return;
    }

    address P = L.head;
    int index = 1;

    cout << left
         << setw(4) << "No"
         << setw(30) << "Title"
         << setw(20) << "Artist"
         << setw(12) << "Duration"
         << setw(12) << "Plays"
         << setw(8) << "Rating"
         << setw(12) << "PopScore"
         << "\n";

    while (P != Nil) {
        cout << left
             << setw(4) << index
             << setw(30) << P->info.Title
             << setw(20) << P->info.Artist
             << setw(12) << P->info.DurationSec
             << setw(12) << P->info.PlayCount
             << setw(8) << fixed << setprecision(1) << P->info.Rating
             << setw(12) << fixed << setprecision(2) << popularityScore(P->info)
             << "\n";
        P = P->next;
        index++;
    }
}

void searchByPopularityRange(const linkedlist &L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;
    bool ada = false;

    while (P != Nil) {
        float score = popularityScore(P->info);
        if (score >= minScore && score <= maxScore) {
            if (!ada) {
                cout << "Lagu dengan Popularity Score antara [" << minScore << ", " << maxScore << "]:\n";
                cout << left << setw(4) << "No" << setw(30) << "Title" << setw(20) << "Artist" << setw(12) << "Score" << "\n";
            }
            cout << left << setw(4) << idx
                 << setw(30) << P->info.Title
                 << setw(20) << P->info.Artist
                 << setw(12) << fixed << setprecision(2) << score << "\n";
            ada = true;
        }
        P = P->next;
        idx++;
    }

    if (!ada) {
        cout << "Tidak ada lagu dalam rentang popularitas tersebut.\n";
    }
}

address getNodeAtPosition(const linkedlist &L, int posisi) {
    if (isEmpty(L) || posisi <= 0) return Nil;

    address P = L.head;
    int idx = 1;
    while (P != Nil) {
        if (idx == posisi) return P;
        P = P->next;
        idx++;
    }
    return Nil;
}
