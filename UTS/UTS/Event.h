#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event
{
public:
    string namaEvent;
    string tempat;
    int tahunEvent;
    int bulanEvent;
    int tanggalEvent;
    int kapasitas;
    void tampilkanInfo();
    void cekKuota();
    void adminPage();
    void pesertaPage();
    int login();
    void invalid();
    //string deskripsi;
    //string pembicara;
    //string namaPenyelenggara;
    //string statusEvent;
    //string linkPendaftaran;
    //string kategoriEvent;
    //string linkEvent;
    //bool isOnline;
    //double biayaPendaftaran;
    //int IDEvent;
    //int jumlahPeserta;
    //struct jadwalKegiatan {
    //    int jam;
    //    int menit;
    //};
    //struct date {
    //    int tahun;
    //    int bulan;
    //    int hari;
    //};
};
