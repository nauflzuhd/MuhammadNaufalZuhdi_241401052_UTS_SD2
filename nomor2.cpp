#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    string namaBarang;
    int hargaBarang;
    int jumlahBarang;
    Node* next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(string nama, int harga, int jumlah) {
    Node *newNode = new Node;
    newNode -> namaBarang = nama;
    newNode -> hargaBarang = harga;
    newNode -> jumlahBarang = jumlah;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

void insertLast(string nama, int harga, int jumlah) {
    Node *newNode = new Node;
    newNode -> namaBarang = nama;
    newNode -> hargaBarang = harga;
    newNode -> jumlahBarang = jumlah;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAfter(string nama, int harga, int jumlah, string check) {
    if(head == NULL) {
        cout << "List kosong, insert di depan terlebih dahulu";
        return;
    } 

    Node *newNode = new Node;
    newNode -> namaBarang = nama;
    newNode -> hargaBarang = harga;
    newNode -> jumlahBarang = jumlah;
    newNode -> next = NULL;

    Node *p = head;
    while(p != NULL && p -> namaBarang != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan\n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail) {
            tail == newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteMiddle(string nama) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    if (head-> namaBarang == nama) {
        deleteFirst();
        return;
    }
    Node *p = head; //
    while (p->next != NULL && p->next->namaBarang != nama) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Node dengan nilai " << nama << " tidak ditemukan!\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

void printList() {
    Node *temp = head;
    int totalHarga = 0;
    int totalBarang = 0;
    while (temp != NULL) {
        cout << temp->namaBarang << " - " << "Rp" << temp->hargaBarang << " x" << temp->jumlahBarang << endl;
        totalBarang++;
        totalHarga += (temp->hargaBarang * temp->jumlahBarang);
        temp = temp->next;
    }
    cout << endl;
    cout << "Total barang: " << totalBarang << endl;
    if(totalHarga >= 1000) {
        cout << "Total harga: Rp" << (totalHarga / 1000) << "." << setfill('0') << setw(3) << (totalHarga % 1000) << endl;
     } else {
        cout << "Total harga: Rp" << totalHarga << endl;
     }
}

int main() {
    int n;
    cout << "Masukkan jumlah barang awal: ";
    cin >> n;
    cin.ignore();
    if(n <= 0) {
        cout << "Tidak valid!";
        return 0;
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        string nama;
        int harga, jumlah;

        cout << "Barang " << i + 1 << ": \n";
        cout << "Nama: ";
        getline(cin, nama);
        cout << "Harga: ";
        cin >> harga;
        cin.ignore();
        cout << "Jumlah: ";
        cin >> jumlah;
        cin.ignore();
        cout << endl;
        insertLast(nama, harga, jumlah);
    }

    char hapus;
    cout << "Apakah ingin menghapus barang? (y/n):";
    cin >> hapus;
    cin.ignore();
    if(hapus == 'y' || hapus == 'Y') {
        string namaHapus;
        cout << "Masukkan nama barang yang ingin anda dihapus: ";
        getline(cin, namaHapus);
        deleteMiddle(namaHapus);
    }

    cout << endl;
    printList();
}