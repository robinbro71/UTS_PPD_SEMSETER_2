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

    // Method untuk mencetak sertifikat
    void printSertifikat();

    // Getter methods
    string getNomorSertifikat() const;
    string getNamaPenerima() const;
    string getTanggalTerbit() const;
};
