#include "Sertifikat.h"
#include <fstream>

void Sertifikat::printSertifikat() {
    // Ambil nama peserta berdasarkan userIndex
    string namaUser = "Tidak ditemukan";
    ifstream filePeserta("peserta.txt");
    if (!filePeserta.is_open()) {
        cerr << "Gagal membuka file peserta.txt\n";
        system("pause");
        return;
    }

    string line;
    int index = 0;
    while (getline(filePeserta, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            string nama, institusi, email, password;
            getline(filePeserta, nama);
            getline(filePeserta, institusi);
            getline(filePeserta, email);
            getline(filePeserta, password);

            if (index == Event::userIndex) {
                namaUser = nama;
                break;
            }
            index++;
        }
    }
    filePeserta.close();

    // Baca event yang telah diregistrasi oleh user
    const int MAX_EVENT = 100;
    string daftarEvent[MAX_EVENT];
    int totalEvent = 0;

    ifstream fileReg("registrasi.txt");
    if (!fileReg.is_open()) {
        cerr << "Gagal membuka file registrasi.txt\n";
        system("pause");
        return;
    }

    while (getline(fileReg, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            string nama, indexStr, namaEvent;
            getline(fileReg, nama);
            getline(fileReg, indexStr);
            getline(fileReg, namaEvent);

            if (stoi(indexStr) == Event::userIndex && nama == namaUser) {
                if (totalEvent < MAX_EVENT) {
                    daftarEvent[totalEvent++] = namaEvent;
                }
            }
        }
    }
    fileReg.close();

    if (totalEvent == 0) {
        cout << "\nKamu belum mendaftar ke event manapun.\n";
        system("pause");
        return;
    }

    // Tampilkan daftar event yang telah didaftarkan
    system("cls");
    cout << "===== CETAK SERTIFIKAT =====\n";
    cout << "Peserta: " << namaUser << "\n\n";
    for (int i = 0; i < totalEvent; ++i) {
        cout << i + 1 << ". " << daftarEvent[i] << endl;
    }

    cout << "\nPilih nomor event untuk cetak sertifikat: ";
    string input;
    getline(cin, input);
    int pilihan = stoi(input);

    if (pilihan >= 1 && pilihan <= totalEvent) {
        string eventDipilih = daftarEvent[pilihan - 1];

        // Ambil detail event dari event.txt
        ifstream fileEvent("event.txt");
        if (!fileEvent.is_open()) {
            cerr << "Gagal membuka file event.txt\n";
            system("pause");
            return;
        }

        string judul, institusi, tanggal, kuota;
        bool found = false;

        while (getline(fileEvent, line)) {
            if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
                getline(fileEvent, judul);
                getline(fileEvent, institusi);
                getline(fileEvent, tanggal);
                getline(fileEvent, kuota);

                // Lewati deskripsi
                for (int i = 0; i < 4; ++i) getline(fileEvent, line);

                if (judul == eventDipilih) {
                    found = true;
                    break;
                }
            }
        }
        fileEvent.close();

        if (found) {
            cout << "\n===== SERTIFIKAT =====\n";
            cout << "Nama Peserta : " << namaUser << endl;
            cout << "Event        : " << judul << endl;
            cout << "Institusi    : " << institusi << endl;
            cout << "Tanggal      : " << tanggal << endl;
            cout << "========================\n";
        }
        else {
            cout << "Event tidak ditemukan dalam file event.txt\n";
        }
    }
    else {
        cout << "Pilihan tidak valid.\n";
    }

    system("pause");
}



// Getter implementations
string Sertifikat::getNomorSertifikat() const {
    return nomorSertifikat;
}

string Sertifikat::getNamaPenerima() const {
    return namaPenerima;
}

string Sertifikat::getTanggalTerbit() const {
    return tanggalTerbit;
}