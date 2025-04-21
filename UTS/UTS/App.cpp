#include "App.h"
void App::test() {
	//example
}
void App::invalid() {
    printf("Invalid input. Please try again.\n");
    system("pause>0");
}

int App::loginPage(Event& event, Peserta& peserta) {
    string select;

    while (true) {
        system("cls");

        cout << "=====================================\n";
        cout << "         SELAMAT DATANG DI APLIKASI  \n";
        cout << "=====================================\n";
        cout << "Silakan pilih menu:\n";
        cout << "1. Login\n";
        cout << "2. Daftar Peserta Baru\n";
        cout << "-------------------------------------\n";
        cout << "Pilihan Anda (1/2): ";
        getline(cin, select);

        if (select == "1") {
            cout << "\nMemasuki halaman login...\n";
            system("pause");
            return event.login(); // return ends the function
        }
        else if (select == "2") {
            peserta.tambahPeserta();
            // kembali ke menu login
        }
        else {
            invalid(); // akan menampilkan pesan error dan kembali ke menu
        }
    }
}



