#include "Registrasi.h"
#include <fstream>
#include <string>
#include <vector>

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void Registrasi::registrasi(int userIndex, string namaEvent) {
    // Ambil nama peserta dari file peserta.txt berdasarkan index
    ifstream filePeserta("peserta.txt");
    if (!filePeserta.is_open()) {
        cerr << "Gagal membuka file peserta.txt" << endl;
        system("pause");
        return;
    }

    string line, nama, institusi, email, password;
    int index = 0;
    bool ditemukan = false;

    while (getline(filePeserta, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            getline(filePeserta, nama);
            getline(filePeserta, institusi);
            getline(filePeserta, email);
            getline(filePeserta, password);

            if (index == userIndex) {
                ditemukan = true;
                break;
            }
            index++;
        }
    }

    filePeserta.close();

    if (!ditemukan) {
        cout << "User dengan index " << userIndex << " tidak ditemukan!" << endl;
        system("pause");
        return;
    }

    // Hitung jumlah registrasi yang sudah ada
    ifstream fileHitung("registrasi.txt");
    int count = 0;
    while (getline(fileHitung, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            count++;
        }
    }
    fileHitung.close();

    int nomorBaru = count + 1;

    // Tambahkan data baru ke file registrasi.txt
    ofstream fileReg("registrasi.txt", ios::app);
    if (!fileReg.is_open()) {
        cerr << "Gagal membuka file registrasi.txt" << endl;
        system("pause");
        return;
    }

    fileReg << nomorBaru << "." << endl;
    fileReg << nama << endl;
    fileReg << userIndex << endl;
    fileReg << namaEvent << endl;

    fileReg.close();

    cout << "\nRegistrasi berhasil untuk event: " << namaEvent << endl;
    system("pause");
}


void Registrasi::registrasiPage() {
    ifstream file("event.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file event.txt" << endl;
        system("pause");
        return;
    }

    const int MAX_EVENT = 100;
    string judulEvent[MAX_EVENT]; // array untuk menyimpan judul
    int totalEvent = 0;
    string line;

    // Baca file dan ambil judul event
    while (getline(file, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            string judul;
            getline(file, judul); // baris judul
            judulEvent[totalEvent] = judul;
            totalEvent++;

            // Lewati 7 baris sisanya
            for (int i = 0; i < 7; ++i) getline(file, line);

            // Cegah overflow array
            if (totalEvent >= MAX_EVENT) break;
        }
    }

    file.close();

    // Tampilkan daftar judul event
    system("cls");
    cout << "===== DAFTAR EVENT =====" << endl;
    for (int i = 0; i < totalEvent; ++i) {
        cout << (i + 1) << ". " << judulEvent[i] << endl;
    }

    // Minta input pilihan user
    cout << "\nPilih nomor event untuk registrasi: ";
    string input;
    getline(cin, input);
    int pilihan = stoi(input);

    if (pilihan > 0 && pilihan <= totalEvent) {
        string namaEvent = judulEvent[pilihan - 1];
        cout << "Anda memilih: " << namaEvent << endl;
        system("pause");

        // Jalankan fungsi registrasi dengan userIndex dan nama event
        registrasi(Event::userIndex, namaEvent);
    }
    else {
        cout << "Pilihan tidak valid." << endl;
        system("pause");
    }
}
