#include "Event.h"
#include <fstream>
#include <string>
#include <vector>

void Event::cekKuota()
{//menampilkna kapasitas suatu event
}

void Event::tampilkanInfo() 
{//menampilakn info event berupa namaevent, tanggal, lokasi kapasitas

}

int Event::login()
{
    system("cls");

    cout << "=====================================\n";
    cout << "             LOGIN PESERTA           \n";
    cout << "=====================================\n";

    string line;
    string nama, institusi, email, password;
    string nameInput, passwordInput;

    cout << "Nama     : ";
    getline(cin, nameInput);
    cout << "Password : ";
    getline(cin, passwordInput);

    // Admin login
    if (nameInput == "admin" && passwordInput == "admin123") {
        cout << "\nLogin sebagai Admin berhasil!\n";
        system("pause");
        return 0;
    }

    // Cek data peserta
    fstream myFile("peserta.txt");
    if (!myFile.is_open()) {
        cerr << "Gagal membuka file peserta.txt\n";
        system("pause");
        return -1;
    }

    while (getline(myFile, line)) {
        // Cek apakah ini baris penomoran peserta (misalnya: "1.", "2.", dst)
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            getline(myFile, nama);
            getline(myFile, institusi);
            getline(myFile, email);
            getline(myFile, password);

            if (nameInput == nama && passwordInput == password) {
                cout << "\nLogin sebagai Peserta berhasil!\n";
                system("pause");
                return 1;
            }
        }
    }

    cout << "\nLogin gagal. Nama atau password salah.\n";
    system("pause");
    return login(); // ulangi sampai login berhasil
}



void Event::adminPage() {
    while (true) {
        system("cls");
        cout << "=====================================\n";
        cout << "             ADMIN PAGE              \n";
        cout << "=====================================\n";
        cout << "1. Tambah Event Baru\n";
        cout << "2. Lihat Event\n";
        cout << "0. Kembali\n";
        cout << "Pilih opsi: ";

        string pilihan;
        getline(cin, pilihan);

        if (pilihan == "1") {
            tambahEvent();  // 🔁 Panggil fungsi yang telah dipisah
        }
        else if (pilihan == "2") {
            lihatEvent();
        }
        else if (pilihan == "0") {
            return; // Kembali ke login
        }
        else {
            cout << "\nOpsi tidak valid. Silakan coba lagi.\n";
            system("pause");
        }
    }
}

void Event::tambahEvent() {
    system("cls");
    string tahunStr, bulanStr, tanggalStr, kapasitasStr;
    string deskripsiEvent, deskripsiSeminar, deskripsiWorkshop, deskripsiKonferensi;

    cout << "=====================================\n";
    cout << "         FORM TAMBAH EVENT           \n";
    cout << "=====================================\n";

    cout << "Nama Event: ";
    getline(cin, namaEvent);

    cout << "Tempat: ";
    getline(cin, tempat);

    cout << "Tanggal (1-31): ";
    getline(cin, tanggalStr);
    tanggalEvent = stoi(tanggalStr);

    cout << "Bulan (1-12): ";
    getline(cin, bulanStr);
    bulanEvent = stoi(bulanStr);

    cout << "Tahun: ";
    getline(cin, tahunStr);
    tahunEvent = stoi(tahunStr);

    cout << "Kapasitas: ";
    getline(cin, kapasitasStr);
    kapasitas = stoi(kapasitasStr);

    cout << "Deskripsi Event         : ";
    getline(cin, deskripsiEvent);
    cout << "Deskripsi Seminar       : ";
    getline(cin, deskripsiSeminar);
    cout << "Deskripsi Workshop      : ";
    getline(cin, deskripsiWorkshop);
    cout << "Deskripsi Konferensi    : ";
    getline(cin, deskripsiKonferensi);

    // Hitung nomor event terakhir
    int nomor = 1;
    ifstream infile("event.txt");
    string line;
    while (getline(infile, line)) {
        if (!line.empty() && line.back() == '.') {
            nomor++;
        }
    }
    infile.close();

    // Tulis data ke file
    ofstream file("event.txt", ios::app);
    if (file.is_open()) {
        file << nomor << "." << endl;
        file << namaEvent << endl;
        file << tempat << endl;
        file << tanggalEvent << " " << bulanEvent << " " << tahunEvent << endl;
        file << kapasitas << endl;
        file << deskripsiEvent << endl;
        file << deskripsiSeminar << endl;
        file << deskripsiWorkshop << endl;
        file << deskripsiKonferensi << endl;
        file.close();
        cout << "\nEvent berhasil disimpan!\n";
    }
    else {
        cout << "\nGagal membuka file event.txt\n";
    }

    system("pause");
}



void Event::lihatEvent() {
    system("cls");
    ifstream file("event.txt");

    if (!file.is_open()) {
        cout << "Gagal membuka file event.txt\n";
        system("pause");
        return;
    }

    vector<string> daftarNamaEvent;
    vector<streampos> posisiEvent;
    string line;

    while (getline(file, line)) {
        if (!line.empty() && isdigit(line[0]) && line.back() == '.') {
            posisiEvent.push_back(file.tellg()); // Simpan posisi setelah nomor
            string nama;
            getline(file, nama);
            daftarNamaEvent.push_back(nama);

            // Lewati 7 baris sisa
            for (int i = 0; i < 7; ++i) getline(file, line);
        }
    }

    if (daftarNamaEvent.empty()) {
        cout << "Belum ada event yang ditambahkan.\n";
        system("pause");
        return;
    }

    // Tampilkan daftar nama event
    cout << "========== DAFTAR EVENT ==========\n";
    for (size_t i = 0; i < daftarNamaEvent.size(); ++i) {
        cout << i + 1 << ". " << daftarNamaEvent[i] << "\n";
    }
    cout << "0. Kembali\n";
    cout << "Pilih nomor event untuk melihat detail: ";

    string pilihan;
    getline(cin, pilihan);
    int index = stoi(pilihan);

    if (index == 0) return;
    if (index < 1 || index > daftarNamaEvent.size()) {
        cout << "Pilihan tidak valid.\n";
        system("pause");
        return;
    }

    // Buka ulang dan lompat ke posisi event yang dipilih
    file.clear();
    file.seekg(posisiEvent[index - 1]);

    string nama, tempat, tanggal, kapasitasStr;
    string deskripsiEvent, deskripsiSeminar, deskripsiWorkshop, deskripsiKonferensi;

    getline(file, nama);
    getline(file, tempat);
    getline(file, tanggal);
    getline(file, kapasitasStr);
    getline(file, deskripsiEvent);
    getline(file, deskripsiSeminar);
    getline(file, deskripsiWorkshop);
    getline(file, deskripsiKonferensi);

    cout << "\n========== DETAIL EVENT ==========\n";
    cout << "Nama Event           : " << nama << "\n";
    cout << "Tempat               : " << tempat << "\n";
    cout << "Tanggal              : " << tanggal << "\n";
    cout << "Kapasitas            : " << kapasitasStr << "\n";
    cout << "Deskripsi Event      : " << deskripsiEvent << "\n";
    cout << "Deskripsi Seminar    : " << deskripsiSeminar << "\n";
    cout << "Deskripsi Workshop   : " << deskripsiWorkshop << "\n";
    cout << "Deskripsi Konferensi : " << deskripsiKonferensi << "\n";
    cout << "==================================\n";

    cout << "Apakah ingin mengedit event ini? (y/n): ";
    string konfirmasi;
    getline(cin, konfirmasi);
    if (konfirmasi == "y" || konfirmasi == "Y") {
        editEvent(index); // Index berdasarkan nomor event
    }

    system("pause");
}

void Event::editEvent(int nomorEvent) {
    ifstream file("event.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file event.txt\n";
        system("pause");
        return;
    }

    vector<string> allEvents;
    string line;

    while (getline(file, line)) {
        allEvents.push_back(line);
    }
    file.close();

    // Temukan baris yang sesuai dengan nomor event (misalnya "2.")
    string targetHeader = to_string(nomorEvent) + ".";
    int targetIndex = -1;

    for (size_t i = 0; i < allEvents.size(); ++i) {
        if (allEvents[i] == targetHeader) {
            targetIndex = i;
            break;
        }
    }

    // Pastikan ada cukup baris untuk semua data (1 header + 8 data)
    if (targetIndex == -1 || targetIndex + 8 >= allEvents.size()) {
        cout << "Event tidak ditemukan atau format file rusak.\n";
        system("pause");
        return;
    }

    // Ambil input baru dari admin
    string namaBaru, tempatBaru, tanggalBaru, kapasitasBaru;
    string deskripsiEvent, deskripsiSeminar, deskripsiWorkshop, deskripsiKonferensi;

    system("cls");
    cout << "===== EDIT EVENT =====\n";
    cout << "Nama Event Baru           : ";
    getline(cin, namaBaru);
    cout << "Tempat Baru               : ";
    getline(cin, tempatBaru);
    cout << "Tanggal Baru (dd mm yyyy) : ";
    getline(cin, tanggalBaru);
    cout << "Kapasitas Baru            : ";
    getline(cin, kapasitasBaru);
    cout << "Deskripsi Event Baru      : ";
    getline(cin, deskripsiEvent);
    cout << "Deskripsi Seminar Baru    : ";
    getline(cin, deskripsiSeminar);
    cout << "Deskripsi Workshop Baru   : ";
    getline(cin, deskripsiWorkshop);
    cout << "Deskripsi Konferensi Baru : ";
    getline(cin, deskripsiKonferensi);

    // Update semua bagian di array
    allEvents[targetIndex + 1] = namaBaru;
    allEvents[targetIndex + 2] = tempatBaru;
    allEvents[targetIndex + 3] = tanggalBaru;
    allEvents[targetIndex + 4] = kapasitasBaru;
    allEvents[targetIndex + 5] = deskripsiEvent;
    allEvents[targetIndex + 6] = deskripsiSeminar;
    allEvents[targetIndex + 7] = deskripsiWorkshop;
    allEvents[targetIndex + 8] = deskripsiKonferensi;

    // Simpan kembali ke file
    ofstream outFile("event.txt", ios::trunc);
    for (const string& baris : allEvents) {
        outFile << baris << endl;
    }
    outFile.close();

    cout << "\nEvent berhasil diedit!\n";
    system("pause");
}


void Event::pesertaPage() {
	system("cls");
	printf("you are in peserta page");
	system("pause>0");
}

void Event::invalid() {
	printf("name or password wrong, Please try again.\n");
	system("pause>0");
}