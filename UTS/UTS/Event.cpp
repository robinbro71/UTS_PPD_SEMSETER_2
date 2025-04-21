#include "Event.h"
#include <fstream>

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
    string nama, nameInput, institusi, email, password, passwordInput;

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
        if (line == "---") {
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
    return login(); // rekursif sampai login berhasil
}


void Event::adminPage() {
    while (true) {
        system("cls");
        cout << "=====================================\n";
        cout << "             ADMIN PAGE              \n";
        cout << "=====================================\n";
        cout << "1. Tambah Event Baru\n";
        cout << "2. Kembali ke Halaman Login\n";
        cout << "Pilih opsi: ";

        string pilihan;
        getline(cin, pilihan);

        if (pilihan == "1") {
            system("cls");
            string tahunStr, bulanStr, tanggalStr, kapasitasStr;

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

            ofstream file("event.txt", ios::app);
            if (file.is_open()) {
                file << "---" << endl;
                file << namaEvent << endl;
                file << tempat << endl;
                file << tanggalEvent << " " << bulanEvent << " " << tahunEvent << endl;
                file << kapasitas << endl;
                file.close();
                cout << "\n Event berhasil disimpan!\n";
            }
            else {
                cout << "\n Gagal membuka file event.txt\n";
            }

            system("pause");
        }
        else if (pilihan == "2") {
            return;// Kembali ke login
        }
        else {
            cout << "\nOpsi tidak valid. Silakan coba lagi.\n";
            system("pause"); 
        }
    }
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