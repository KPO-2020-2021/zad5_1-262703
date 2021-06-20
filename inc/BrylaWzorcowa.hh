#ifndef BRYLAWZORCOWA_HH
#define BRYLAWZORCOWA_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Vector3D.hh"

class BrylaGeometryczna
{

public:

    std::string NazwaBrylaFinalna;

    std::string NazwaBrylaWzorc;

    Vector3D Skala;

    Vector3D Skaluj(Vector3D& Wierz, double KatObrotu, Vector3D VectorTransl);

    std::string& WezNazwePliku_Bryla(double KatObrotu, Vector3D VectorTransl);
};



#endif