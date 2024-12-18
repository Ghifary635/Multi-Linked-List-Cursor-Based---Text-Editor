#include "dll.h"
#include <iostream>

using namespace std;

//Buat List
void createList(List &L){
    L.first = NULL;
    L.last = NULL;
}

//Buat MultiLinkedList
void createMultiList(MultiList &ML, alamat &MLcursor){
    ML.first = NULL;
    ML.last = NULL;

    // Apply logic dibawah saat update data aja.
    alamat H = new elmMultiList;
    H->next = nullptr;
    H->prev = nullptr;
    H->cursor = nullptr;
    H->info.first = NULL;
    H->info.last = NULL;

    insertFirstML(ML,H);
    MLcursor = ML.first;
}

//Buat Elemen
address createElement(string teks){
    address P = new elmList;
    P -> info = teks;
    P ->next = NULL;
    P ->prev = NULL;
    return P;
}

void eksporMultiList(MultiList &ML, List L, address cursor, alamat &MLcursor){
    // Duplicate List child
    List newList;
    createList(newList);

    address q = L.first;
    while (q != NULL) {
        address temp = createElement(q->info);
        insertLast(newList, temp);
        q = q->next;
    }

    // Create new element multi list
    alamat H = new elmMultiList;
    H->next = nullptr;
    H->prev = nullptr;
    H->info = newList;

    // Create saved cursor
    q = H->info.first;
    while (q != nullptr && q->info != cursor->info) {
        q = q->next;
    }
    H->cursor = q;

    // Insert ke multi list
    if (ML.first == NULL) {
        insertFirstML(ML, H);
        MLcursor = H;
    } else {
        insertAfterML(ML, H, MLcursor);
        MLcursor = H;
    }
}

void imporMultiList(List &L, address &cursor, alamat MLcursor){
        createList(L);
        address P = MLcursor->info.first;
        while (P != NULL) {
            address newElement = createElement(P->info);
            insertLast(L, newElement);
            P = P->next;
        }

        P = L.first;
        while (P != nullptr && P->info != MLcursor->cursor->info){
            P = P->next;
        }
        cursor = P;
        show(L);

}

void insertFirst(List &L, address P){
    if(L.first == NULL && L.last == NULL){
        L.first = P;
        L.last = P;
    }else{
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    }
}

void insertFirstML(MultiList &ML, alamat P){
    if(ML.first == NULL && ML.last == NULL){
        ML.first = P;
        ML.last = P;
    }else{
        P -> next = ML.first;
        ML.first -> prev = P;
        ML.first = P;
    }
}

void insertLast(List &L, address P){
    if(L.first == NULL && L.last == NULL){
        L.first = P;
        L.last = P;
    }else{
        P -> prev = L.last;
        L.last -> next = P;
        L.last = P;
    }
}

void insertLastML(MultiList &ML, alamat P){
    if(ML.first == NULL && ML.last == NULL){
        ML.first = P;
        ML.last = P;
    }else{
        ML.last -> next = P;
        P -> prev = ML.last;
        ML.last = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec == L.last) {
        insertLast(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        (Prec->next)->prev = P;
        Prec->next = P;
    }
}

void insertAfterML(MultiList &ML, alamat P, alamat Prec) {
    if (Prec == ML.last) {
        insertLastML(ML, P);
    }
    else {
        Prec->next->prev = NULL;
        Prec->next = NULL;
        ML.last = Prec;
        insertLastML(ML, P);
    }
}

//Insert pada Text Editor
void insertTeks(MultiList &ML, List &L, address P, address &cursor, alamat &MLcursor){
    //Insert ke List
    if(L.first == NULL){
        insertFirst(L, P);
        cursor = P;
    }
    else{
        insertAfter(L, P, cursor);
        cursor = P;
    }

    eksporMultiList(ML, L, cursor, MLcursor);

}

void deleteFirst(List &L, address &P){
    if (L.first == NULL){
        P = NULL;
    }
    else if (L.last == L.first){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }
    else{
        P = L.first;
        L.first = L.first->next;
        P->next = NULL;
        L.first->prev = NULL;
    }
}

void deleteLast(List &L, address &P){
    if (L.last == NULL){
        P = NULL;
    }
    else if (L.last == L.first){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }
    else{
        P = L.last;
        L.last = L.last->prev;
        P->prev = NULL;
        L.last->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    P = Prec->next;
    if (P == L.last) {
        L.last = Prec;
        Prec->next = NULL;
    }
    else {
        Prec->next = P->next;
        P->next->prev = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

//Delete pada cursor yang ditunjuk
void deleteAtCursor(MultiList &ML, List &L, address &cursor, alamat &MLcursor){
    if (cursor == NULL || cursor == L.first){
        cout << "Cursor tidak menunjuk ke elemen manapun atau cursor sudah paling kiri" << endl;
    }
    else{
        address temp;
        cursor = cursor->prev;
        deleteAfter(L, cursor, temp);
    }

    eksporMultiList(ML, L, cursor, MLcursor);
}

//Geser cursor ke kiri
void moveLeft(MultiList &ML, List L, address &cursor, alamat &MLcursor){
    if(cursor != NULL){
        if(cursor != L.first){
            cursor = cursor -> prev;
            cout << "Kursor saat ini: " << cursor->info << endl;
        }
        else{
            cout<<"Cursor sudah paling Kiri"<<endl;
        }
    }
    else{
        cout<<"List Kosong"<<endl;
    }

    eksporMultiList(ML, L, cursor, MLcursor);
}

//Geser cursor ke kanan
void moveRight(MultiList &ML, List L, address &cursor, alamat &MLcursor){
    if(cursor != NULL){
        if(cursor != L.last){
            cursor = cursor -> next;
            cout << "Kursor saat ini: " << cursor->info << endl;
        }else{
            cout<<"Cursor sudah paling Kanan"<<endl;
        }
    }else{
        cout<<"List Kosong"<<endl;
    }

    eksporMultiList(ML, L, cursor, MLcursor);
}

//Edit teks yang ditunjuk cursor
void modifyCursorInfo(MultiList &ML, List &L, address &cursor, string newInfo, alamat &MLcursor) {
    if (cursor != NULL) {
        cursor->info = newInfo;
    }
    else {
         cout << "Cursor tidak menunjuk ke elemen manapun." << endl;
    }

    eksporMultiList(ML, L, cursor, MLcursor);
}

//Print isi list berdasarkan yang ditambahkan baru baru ini
void show(List L){
    address P;
    P = L.first;
    while(P != NULL){
        cout<<P->info<<" ";
        P = P -> next;

    }
    cout<<endl;
}

//Semua teks kapital di awal kata
void autoKapital(MultiList &ML, List &L, address cursor, alamat &MLcursor){
    address P = L.first;
    string Infonya;
    while (P != NULL){
        Infonya = P->info;
        if (Infonya[0] >= 'a' && Infonya[0] <= 'z'){
            Infonya[0] = Infonya[0] - 32;
            P->info = Infonya;
        }
        P = P->next;
    }

    eksporMultiList(ML, L, cursor, MLcursor);
}

//Print list terurut berdasarkan abjad
void printSorted(List L) {
    List Temp;
    createList(Temp);

    // Membuat salinan dari L ke Temp
    address P = L.first;
    while (P != NULL) {
        address newElement = createElement(P->info); // Asumsi createElement membuat node baru
        insertLast(Temp, newElement);
        P = P->next;
    }

    // Sorting Temp
    List Sorted;
    createList(Sorted);

    address Q, buatBandingkan;

    if (Temp.first != NULL) {
        if (Temp.first == Temp.last) {
            cout << Temp.first->info << endl;
        } else {
            P = Temp.first;
            while (P != NULL) {
                buatBandingkan = P;
                Q = P->next;
                while (Q != NULL) {
                    if (buatBandingkan->info > Q->info) {
                        buatBandingkan = Q;
                    }
                    Q = Q->next;
                }
                if (buatBandingkan == Temp.first) {
                    deleteFirst(Temp, buatBandingkan);
                    insertLast(Sorted, buatBandingkan);
                } else if (buatBandingkan == Temp.last) {
                    deleteLast(Temp, buatBandingkan);
                    insertLast(Sorted, buatBandingkan);
                } else {
                    address prec = buatBandingkan->prev;
                    deleteAfter(Temp, prec, buatBandingkan);
                    insertLast(Sorted, buatBandingkan);
                }
                P = Temp.first;
            }

            // Cetak elemen Sorted
            P = Sorted.first;
            while (P != NULL) {
                cout << P->info << " ";
                P = P->next;
            }
        }
    }
}


void Undo(MultiList &ML, List &L, address &cursor, alamat &MLcursor){
    if (MLcursor != nullptr && MLcursor -> prev != nullptr){
        MLcursor = MLcursor->prev;

        imporMultiList(L, cursor, MLcursor);
    }
    else{
        cout << "Udah paling ujung undonya" << endl;
        cout << "Isi list: ";
        show(L);
    }
}

void Redo(MultiList &ML, List &L, address &cursor, alamat &MLcursor){
    if (MLcursor != nullptr && MLcursor -> next != nullptr ){
        MLcursor = MLcursor->next;

        imporMultiList(L, cursor, MLcursor);
    }
    else{
        cout << "Udah paling ujung redonya" << endl;
        cout << "Isi list: ";
        show(L);
    }
}
