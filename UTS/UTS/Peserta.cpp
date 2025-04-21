#include "Peserta.h"
#include <fstream>

void Peserta::tambahPeserta() {
    system("cls");

    string nama;
    string institusi;
    string email;
    string password;

    cout << "=====================================\n";
    cout << "           PENDAFTARAN PESERTA       \n";
    cout << "=====================================\n";

    cout << "Nama      : ";
    getline(cin, nama);
    cout << "Institusi : ";
    getline(cin, institusi);
    cout << "Email     : ";
    getline(cin, email);
    cout << "Password  : ";
    getline(cin, password);

    // Hitung jumlah peserta sebelumnya
    int jumlahPeserta = 0;
    ifstream inFile("peserta.txt");
    string line;
    while (getline(inFile, line)) {
        if (line.find('.') != string::npos && isdigit(line[0])) {
            jumlahPeserta++;
        }
    }
    inFile.close();

    // Tambahkan peserta baru dengan nomor urut
    ofstream myFile("peserta.txt", ios::app);
    if (myFile.is_open()) {
        myFile << (jumlahPeserta + 1) << "." << endl;
        myFile << nama << endl;
        myFile << institusi << endl;
        myFile << email << endl;
        myFile << password << endl;
        myFile.close();

        cout << "\nPendaftaran berhasil disimpan!\n";
    }
    else {
        cerr << "Gagal membuka file untuk menyimpan data.\n";
    }

    system("pause");
}
