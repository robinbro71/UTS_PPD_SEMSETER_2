#pragma once
#include "Event.h"
#include "peserta.h"
using namespace std;

class App :
    public Event
{public:
    void test();
    int loginPage(Event& event, Peserta& peserta);
    void invalid();
};

