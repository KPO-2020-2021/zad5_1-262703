#ifndef VECTOR_HH
#define VECTOR_HH

#include <iostream>
#include <cassert>
#include <initializer_list>

template <typename TYP, unsigned  int SIZE>
class Vector {

    TYP Wsp[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(const std::initializer_list<TYP> &rListaWsp);

    ~Vector();

    Vector<TYP, SIZE> operator + (const Vector<TYP, SIZE> &v) const;

    Vector<TYP, SIZE> operator - (const Vector<TYP, SIZE> &v) const;

    Vector<TYP, SIZE> operator * (const double &tmp) const;

    Vector<TYP, SIZE> operator * (const Vector<TYP,SIZE> &v) const;
 
    Vector<TYP, SIZE> operator / (const double &tmp) const;

    TYP  operator [] (unsigned int index) const {assert(index < SIZE); return Wsp[index];};

    TYP &operator [] (unsigned int index) {assert(index < SIZE); return Wsp[index];};

};

template <typename TYP, unsigned int SIZE>
std::ostream &operator << (std::ostream &out, Vector<TYP, SIZE> const &WspO);

template <typename TYP, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<TYP, SIZE> &WspI);



#endif