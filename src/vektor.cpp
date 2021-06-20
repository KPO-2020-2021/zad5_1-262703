#include "vector.hh"

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE>::Vector() {
    for (unsigned int index = 0; index < SIZE; ++index) {
        Wsp[index] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE>::Vector(const std::initializer_list<TYP> &rListaWsp): Vector() {
    assert(rListaWsp.size() <= SIZE);
    int index = -1;
    for (double Wsp_i: rListaWsp) Wsp[++index] = Wsp_i;
}


template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE>::~Vector()
{
    
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE> Vector<TYP, SIZE>::operator + (const Vector<TYP,SIZE> &v) const{
    Vector<TYP, SIZE> result;
    for (unsigned int index = 0; index < SIZE; ++index) 
    {
        result[index] = Wsp[index] + v[index]; 
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE> Vector<TYP, SIZE>::operator - (const Vector<TYP, SIZE> &v) const{
    Vector<TYP, SIZE> result;
    for (unsigned int index = 0; index < SIZE; ++index) 
    {
        result[index] = Wsp[index] - v[index]; 
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE> Vector<TYP, SIZE>::operator * (const double &tmp) const{
    Vector<TYP, SIZE> result;
    for (unsigned int index = 0; index < SIZE; ++index) 
    {
        result[index] = Wsp[index] * tmp; 
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE> Vector<TYP, SIZE>::operator / (const double &tmp) const{
    Vector<TYP, SIZE> result;
    if (tmp != 0){
        for (unsigned int index = 0; index < SIZE; ++index) 
        {
           result[index] = Wsp[index] / tmp; 
        }
    }
    else{
        std::cerr << "Blad! Dzielenie przez zero!" << std::endl;
    }
    return result;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template<typename TYP, unsigned int SIZE>
std::ostream &operator << (std::ostream &out, Vector<TYP, SIZE> const &WspO) {
    for (unsigned int index = 0; index < SIZE; ++index) {
        out << WspO[index] << " ";
    }
    std::cout << std::endl;
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template<typename TYP, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<TYP, SIZE> &WspI) {
    for (unsigned int index = 0; index < SIZE; ++index) {
        in >> WspI[index];
    }
    std::cout << std::endl;
    return in;
}

template<typename TYP, unsigned int SIZE>
Vector<TYP, SIZE> Vector<TYP, SIZE>::operator * (const Vector<TYP,SIZE> &v) const{
    Vector<TYP, SIZE> result;
    for (unsigned int index = 0; index < SIZE; ++index) 
    {
        result[index] = Wsp[index] * v[index]; 
    }
    return result;
}
