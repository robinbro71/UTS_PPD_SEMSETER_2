#pragma once
#include "Event.h"
using namespace std;
class Registrasi :
    public Event
{   public: 
    void registrasiPage();
    void registrasi(int userIndex, string namaEvent);
};

