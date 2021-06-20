#include "Rotor.hh"

void Rotor::ZmianaPolozTransl(double KatObr)
{
    double dlug = sqrt(Poloz[0] * Poloz[0] + Poloz[1] * Poloz[1]);
    double cosw = Poloz[0] / dlug;
    double sinw = Poloz[1] / dlug;
    double cosw_a = cosw * cos(KatObr) - sinw * sin(KatObr);
    double sinw_a = sinw * cos(KatObr) + cosw * sin(KatObr);
    PolozTransl[0] = sinw_a * dlug; PolozTransl[1] = cosw_a * dlug;
}