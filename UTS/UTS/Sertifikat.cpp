#include "Sertifikat.h"


// Constructor
Sertifikat::Sertifikat(const string& nomor, const string& penerima,
    const string& namaEvent, const string& tanggalEvent,
    const string& tglTerbit)
    : Event(namaEvent, tanggalEvent),
    nomorSertifikat(nomor),
    namaPenerima(penerima),
    tanggalTerbit(tglTerbit) {
}

void Sertifikat::printSertifikat() {
    //cout << "\n=== SERTIFIKAT ===" << endl;
    //cout << "Nomor: " << nomorSertifikat << endl;
    //cout << "Diberikan kepada: " << namaPenerima << endl;
    //cout << "Untuk partisipasi dalam: " << getNamaEvent() << endl;
    //cout << "Tanggal Event: " << getTanggalEvent() << endl;
    //cout << "Tanggal Terbit: " << tanggalTerbit << endl;
    //cout << "=================\n" << endl;
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