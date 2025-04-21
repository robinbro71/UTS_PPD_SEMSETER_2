#ifndef REGISTRASI_H
#define REGISTRASI_H

#include "Event.h"
#include "Peserta.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Registrasi {
private:
    std::vector<Peserta> daftarPeserta;
    std::vector<Event*> daftarEvent;

public:
    Registrasi();
    ~Registrasi();

    void muatPesertaDariFile();
    
    // Manajemen Event
    void tampilkanDaftarEvent() const;
    Event* dapatkanEventByIndex(int index) const;
    
    // Manajemen Peserta
    bool daftarKeEvent(const std::string& email, const std::string& namaEvent);  // Baru: Pendaftaran event
    void tampilkanDaftarPeserta() const;
   
};

#endif