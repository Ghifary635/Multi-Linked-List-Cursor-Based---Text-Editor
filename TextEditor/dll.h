#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef string infotype;
typedef struct elmList *address;
typedef struct elmMultiList *alamat;

// LIST DATA
struct elmList{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

// MULTILINKED LIST (PARENT)
struct elmMultiList{
    alamat next;
    alamat prev;
    List info;
    address cursor;
};

struct MultiList{
    alamat first;
    alamat last;
};


void createList(List &L);

//Buat MultiLinkedList
void createMultiList(MultiList &ML, alamat &MLcursor);

//Buat Elemen
address createElement(string teks);

void eksporMultiList(MultiList &ML, List L, address cursor, alamat &MLcursor);

void imporMultiList(List &L, address &cursor, alamat MLcursor);

void insertFirst(List &L, address P);

void insertFirstML(MultiList &ML, alamat P);

void insertLast(List &L, address P);

void insertLastML(MultiList &ML, alamat P);

void insertAfter(List &L, address P, address Prec);

void insertAfterML(MultiList &ML, alamat P, alamat Prec);

//Insert pada Text Editor
void insertTeks(MultiList &ML, List &L, address P, address &cursor, alamat &MLcursor);

//Delete pada cursor yang ditunjuk
void deleteAtCursor(MultiList &ML, List &L, address &cursor, alamat &MLcursor);

//Geser cursor ke kiri
void moveLeft(MultiList &ML, List L, address &cursor, alamat &MLcursor);

//Geser cursor ke kanan
void moveRight(MultiList &ML, List L, address &cursor, alamat &MLcursor);

//Edit teks yang ditunjuk cursor
void modifyCursorInfo(MultiList &ML, List &L, address &cursor, string newInfo, alamat &MLcursor);

//Print isi list berdasarkan yang ditambahkan baru baru ini
void show(List L);

//Semua teks kapital di awal kata
void autoKapital(MultiList &ML, List &L, address cursor, alamat &MLcursor);


void deleteFirst(List &L, address &P);

void deleteLast(List &L, address &P);

void deleteAfter(List &L, address Prec, address &P);

//Print list terurut berdasarkan abjad
void printSorted(List L);

void Undo(MultiList &ML, List &L, address &cursor, alamat &MLcursor);

void Redo(MultiList &ML, List &L, address &cursor, alamat &MLcursor);


#endif // DLL_H_INCLUDED
