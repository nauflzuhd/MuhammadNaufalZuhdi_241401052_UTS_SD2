#include <iostream>
using namespace std;

struct Pesanan {
    string namaHewan;
    string menuPesanan;
    int statusVIP;
};

string toUpper(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

int main() {
    int n;
    cout << "Masukkan jumlah pesanan: ";
    cin >> n;

    if(n <= 0) {
        cout << "Tidak ada pesanan" << endl;
        return 0;
    }

    Pesanan* antrian = new Pesanan[n];
    int currentSize = 0;

    for(int i = 0; i < n; i++) {
        Pesanan p;
        cout << "Pesanan " << (i + 1) << ":" << endl;
        cout << "Nama hewan: ";
        cin.ignore();
        getline(cin, p.namaHewan);
        cout << "Menu pesanan: ";
        getline(cin, p.menuPesanan);
        cout << "Status VIP (1=biasa, 2=VIP): ";
        cin >> p.statusVIP;

        antrian[currentSize] = p;
        currentSize++;
        cout << endl;
        }
    

    int nomor = 1;
    for(int i = 0; i < n; i++) {
       if(antrian[i].statusVIP == 2) {
        cout << nomor << ". " << toUpper(antrian[i].namaHewan) << " - " << antrian[i].menuPesanan << " [VIP]" << endl;
        nomor++;
       }
    }
    for(int i = 0; i < n; i++) {
        if(antrian[i].statusVIP == 1) {
        cout << nomor << ". " << toUpper(antrian[i].namaHewan) << " - " << antrian[i].menuPesanan << endl;
        nomor++;
        }
    }
    
    delete[] antrian;
    return 0;
}