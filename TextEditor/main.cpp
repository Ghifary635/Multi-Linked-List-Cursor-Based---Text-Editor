#include <iostream>
#include "dll.h"

using namespace std;

int main() {
    List l;
    MultiList ml;
    address p, cursor = NULL;
    alamat mlcursor = NULL;
    string masukan, modify, input_string;
    int jumlah;

    createList(l);
    createMultiList(ml, mlcursor);

    cout << "Masukkan jumlah kata yang diinput: ";
    cin >> jumlah;
    cout << endl;

    cout << "Masukkan kata: ";
    for (int i = 0; i < jumlah; ++i) {
        cin >> masukan;
        p = createElement(masukan);
        insertTeks(ml, l, p, cursor, mlcursor);
    }
    cout<<endl;

    cout << endl << "Isi list: ";
    show(l);
    cout << endl;

    while (input_string != "stop") {
        cout << "Menu:\n"
             << "   1. Delete pada cursor\n"
             << "   2. Modifikasi cursor\n"
             << "   3. Geser cursor ke kiri\n"
             << "   4. Geser cursor ke kanan\n"
             << "   5. Auto kapital\n"
             << "   6. Teks terurut\n"
             << "   7. Undo\n"
             << "   8. Redo\n"
             << "   9. Cursor saat ini\n"
             << "   10. Tambahkan Frasa\n"
             << "Ketik 'stop' untuk keluar.\n"
             << "Masukkan pilihan: ";
        cin >> input_string;
        cout << endl;

        if (input_string == "1") {
            deleteAtCursor(ml, l, cursor, mlcursor);
            cout << "Setelah delete: ";
            show(l);
            cout << endl;
        } else if (input_string == "2") {
            cout << "Masukkan teks baru: ";
            cin >> modify;
            modifyCursorInfo(ml, l, cursor, modify, mlcursor);
            cout << "Setelah modifikasi: ";
            show(l);
            cout << endl;
        } else if (input_string == "3") {
            moveLeft(ml, l, cursor, mlcursor);
            cout << "Cursor digeser ke kiri." << endl;
            show(l);
            cout << endl;
        } else if (input_string == "4") {
            moveRight(ml, l, cursor, mlcursor);
            cout << "Cursor digeser ke kanan." << endl;
            cout << "Isi list: ";
            show(l);
            cout << endl;
        } else if (input_string == "5") {
            autoKapital(ml, l, cursor, mlcursor);
            cout << "Setelah auto kapital: ";
            cout << "Isi list: ";
            show(l);
            cout << endl;
        } else if (input_string == "6") {
            cout << "List terurut abjad: ";
            printSorted(l);
            cout << endl;
        } else if (input_string == "7"){
            cout << "Setelah undo: ";
            Undo(ml, l, cursor, mlcursor);
            cout << endl;
        } else if (input_string == "8"){
            cout << "Setelah redo: ";
            Redo(ml, l, cursor, mlcursor);
            cout << endl;
        }else if(input_string == "9"){
            if (cursor == NULL){
                cout << "List kosong, cursor tidak menunjuk elemen apapun" << endl;
            }
            else{
                cout << "Cursor saat ini: " << cursor->info << endl;
                cout << "Isi list: ";
                show(l);
                cout << endl;
            }
        }else if (input_string == "10"){
            cout << "Masukkan kata: ";
            cin >> masukan;
            p = createElement(masukan);
            insertTeks(ml, l, p, cursor, mlcursor);
            cout<<endl;
            cout << endl << "Isi list: ";
            show(l);
            cout << endl;
        }else {
            cout << endl;
        }
    }

    return 0;
}
