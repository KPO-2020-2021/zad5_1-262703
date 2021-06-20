#ifndef ROTOR_HH
#define ROTOR_HH

#include <iostream>
#include "BrylaWzorcowa.hh"

class Rotor: public BrylaGeometryczna
{

public:

    Vector3D Poloz;

    Vector3D PolozTransl;

    double KatObrotu;

    void TransfDoUkl(Vector3D const PolozDrona){Poloz[0] = PolozDrona[0] + PolozTransl[0];
                                                Poloz[1] = PolozDrona[1] + PolozTransl[1];
                                                Poloz[2] = PolozDrona[2] + PolozTransl[2] - 2;};
    
    void ZmianaPolozTransl(double KatObr);

};


#endif