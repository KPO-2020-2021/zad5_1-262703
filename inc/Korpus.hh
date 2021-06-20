#ifndef KORPUS_HH
#define KORPUS_HH

#include <iostream>
#include "BrylaWzorcowa.hh"

class Korpus: public BrylaGeometryczna
{

public:

    Vector3D Poloz;

    double KatObrotu;

    void TransfDoUkl(Vector3D const PolozDrona, double const KatObrotaDrona){Poloz = PolozDrona; KatObrotu = KatObrotaDrona;};

};


#endif