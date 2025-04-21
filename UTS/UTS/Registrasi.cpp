#include "Registrasi.h"
#include "Peserta.h"
#include <iostream>
#include <algorithm>
#include <sstream>

Registrasi::Registrasi() {
    muatPesertaDariFile();

    Registrasi::~Registrasi() {
        for (auto event : daftarEvent) {
            delete event;
        }
    }

void Registrasi::muatPesertaDariFile() {
    std::ifstream file("peserta.txt");
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nama, institusi, email;

        if (std::getline(iss, nama, ';') &&
            std::getline(iss, institusi, ';') &&
            std::getline(iss, email)) {
            daftarPeserta.emplace_back(nama, institusi, email);
        }
    }
    file.close();
}

void Registrasi::tampilkanDaftarEvent() const {
    std::cout << "\n=== DAFTAR EVENT TERSEDIA ===\n";
    for (size_t i = 0; i < daftarEvent.size(); ++i) {
        std::cout << "[" << i + 1 << "] ";
        daftarEvent[i]->tampilkanInfo();
        std::cout << "Kuota tersedia: "
            << daftarEvent[i]->kapasitas() - daftarEvent[i]
            << "/" << daftarEvent[i]->kapasitas() << "\n";
        std::cout << "---------------------------\n";
    }
}

Event* Registrasi::dapatkanEventByIndex(int index) const {
    if (index < 0 || index >= static_cast<int>(daftarEvent.size())) {
        return nullptr;
    }
    return daftarEvent[index];
}

// Fungsi untuk mendaftar ke event tertentu
bool Registrasi::daftarKeEvent(const std::string& email, const std::string& namaEvent) {
    // Cari peserta
    auto itPeserta = std::find_if(daftarPeserta.begin(), daftarPeserta.end(),
        [&email](const Peserta& p) { return p.email() == email; });

    if (itPeserta == daftarPeserta.end()) {
        std::cout << "Email tidak terdaftar.\n";
        return false;
    }

    // Cek kuota
    if (!(itEvent)->cekKuota()) {
        std::cout << "Kuota event sudah penuh.\n";
        return false;
    }

    // Tambah peserta ke event
    (*itEvent)->setPesertaTerdaftar((*itEvent)->getPesertaTerdaftar() + 1);
    std::cout << "Pendaftaran berhasil untuk event: " << namaEvent << "\n";
    return true;
}

void Registrasi::tampilkanDaftarPeserta() const {
    std::cout << "\n=== DAFTAR PESERTA TERDAFTAR ===\n";
    for (const auto& peserta : daftarPeserta) {
        std::cout << "Nama: " << peserta.nama() << "\n"
            << "Institusi: " << peserta.institusi() << "\n"
            << "Email: " << peserta.email() << "\n"
            << "-----------------------------\n";
    }
}