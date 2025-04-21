#pragma once
#include "Event.h"
#pragma once
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Sertifikat : public Event {
private:
    string nomorSertifikat;
    string namaPenerima;
    string tanggalTerbit;

public:
    // Constructor
    Sertifikat(const string& nomor, const string& penerima,
        const string& namaEvent, const string& tanggalEvent,
        const string& tglTerbit);

    // Method untuk mencetak sertifikat
    void printSertifikat();

    // Getter methods
    string getNomorSertifikat() const;
    string getNamaPenerima() const;
    string getTanggalTerbit() const;
};
