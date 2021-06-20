#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "BrylaWzorcowa.hh"
#include "Korpus.hh"
#include "Rotor.hh"
#include <unistd.h>
#include "Vector3D.hh"
#include "lacze_do_gnuplota.hh"

class Dron
{

    Korpus Korp;

    Rotor Rotory[4];

public:
    
    Vector3D Poloz;

    double KatObrotu;

    bool Oblicz_i_zapisz_WspDrona(int adresDrona);

    bool Oblicz_i_zapisz_WspKorpusa(int adresDrona);

    bool Oblicz_i_zapisz_WspRotora(Rotor& Rot, int adres, int const adresDrona);

    bool DodajTrasePrzelotu(double KatObrotu, double Dlugosc, PzG::LaczeDoGNUPlota &Lacze);

    bool WykonajLot(double Dlug, double KatObr, PzG::LaczeDoGNUPlota &Lacze, int const adresDrona);
};

#endif