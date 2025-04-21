// UTS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "Event.h"
#include "App.h"
#include "Konferensi.h"
#include "Workshop.h"
#include "Peserta.h"
#include "Registrasi.h"
#include "Seminar.h"
#include "Sertifikat.h"
using namespace std;



int main()
{
    int select;
    Event event;
    Peserta peserta;
    App app;
    //Sertifikat sertifikat;
    loginPage:
    if (app.loginPage(event, peserta) == 0) {
            event.adminPage();
            goto loginPage;
        }
        else {
            event.pesertaPage();
        }
    //sertifikat.printSertifikat();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
