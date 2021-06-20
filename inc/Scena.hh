#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include "Dron.hh"

class Scena{

private:

    Dron Drony[2];

    PzG::LaczeDoGNUPlota Lacze;

public:

    void Menu();

    void UzyjAktywnegoDrona();

    int WezAktywnegoDrona(int const AktywnyDron);

};

#endif