#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event
{
public:
    static int userIndex;
    string namaEvent;
    string tempat;
    int tahunEvent;
    int bulanEvent;
    int tanggalEvent;
    int kapasitas;
    //void tampilkanInfo();
    int cekKuota(int nomorIndex);
    void adminPage();
    void pesertaPage();
    int login();
    void tambahEvent();
    void tampilkanInfo();
    void tampilkanInfoPeserta();
    void editEvent(int indexToEdit);
    void invalid();
    //virtual void registrasiPage(); // <- tambahkan virtual agar bisa override
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
