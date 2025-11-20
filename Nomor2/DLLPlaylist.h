#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil nullptr

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

typedef Song song;

typedef struct node *address;

struct node {
    song info;
    address prev;
    address next;
};

struct linkedlist {
    address head;
    address tail;
};

// utility
bool isEmpty(const linkedlist &L);
void createList(linkedlist &L);
address allocate(const song &S);
void deallocate(address &P);

// insert
void insertFirst(linkedlist &L, address newNode);
void insertLast(linkedlist &L, address newNode);
void insertAfter(linkedlist &L, address Q, address newNode);
void insertBefore(linkedlist &L, address Q, address newNode);

// delete
void deleteFirst(linkedlist &L, song &S);
void deleteLast(linkedlist &L, song &S);
void deleteAfter(linkedlist &L, address Q, song &S);
void deleteBefore(linkedlist &L, address Q, song &S);
void deleteNode(linkedlist &L, address target);

// update
void updateAtPosition(linkedlist &L, int posisi, const song &newData);
void updateBefore(linkedlist &L, address nodeNext);

// view/search
void viewList(const linkedlist &L);
void searchByPopularityRange(const linkedlist &L, float minScore, float maxScore);

// helpers
float popularityScore(const song &s);
address getNodeAtPosition(const linkedlist &L, int posisi);

#endif
