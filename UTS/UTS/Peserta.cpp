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

    fstream myFile("peserta.txt", ios::app); // Tambahkan ke akhir file
    if (myFile.is_open()) {
        myFile << "---" << endl;
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
