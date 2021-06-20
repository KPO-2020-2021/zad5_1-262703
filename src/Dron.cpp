#include "Dron.hh"

bool Dron::Oblicz_i_zapisz_WspDrona(int const adresDrona)
{
    static double KatObrotuRotora = 0;
    Rotory[0].PolozTransl = {5, 4, 5};
    Rotory[1].PolozTransl = {5, -4, 5};
    Rotory[2].PolozTransl = {-5, 4, 5};
    Rotory[3].PolozTransl = {-5, -4, 5};
    Rotory[0].KatObrotu = -KatObrotuRotora;
    Rotory[1].KatObrotu = KatObrotuRotora;
    Rotory[2].KatObrotu = KatObrotuRotora;
    Rotory[3].KatObrotu = -KatObrotuRotora;
    if (!Oblicz_i_zapisz_WspKorpusa(adresDrona)) return false;
    for (int adres = 0; adres < 4; ++adres)
    {
        //Rotory[adres].ZmianaPolozTransl(KatObr);
        if (!Oblicz_i_zapisz_WspRotora(Rotory[adres], adres, adresDrona)) return false;

    }
    KatObrotuRotora += 10;
    return true;
}

bool Dron::Oblicz_i_zapisz_WspKorpusa(int adresDrona)
{
    Korp.Skala = {10, 8, 4};
    Korp.NazwaBrylaWzorc = "../bryly_wzorcowe/szescian.dat";
    Korp.NazwaBrylaFinalna = "../datasets/PlikWlasciwy_Dron" + std::to_string(adresDrona + 1) + "_Korpus.dat";
    Korp.TransfDoUkl(Poloz, KatObrotu);
    Korp.NazwaBrylaFinalna = Korp.WezNazwePliku_Bryla(Korp.KatObrotu, Korp.Poloz);
    return true;
}

bool Dron::Oblicz_i_zapisz_WspRotora(Rotor& Rot, int adres, int adresDrona)
{
    Rot.Skala = {8, 8, 2};
    Rot.NazwaBrylaWzorc = "../bryly_wzorcowe/graniastoslup6.dat";
    Rot.NazwaBrylaFinalna = "../datasets/PlikWlasciwy_Dron" + std::to_string(adresDrona + 1) +"_Rotor" + std::to_string(adres+1) + ".dat";
    Rot.TransfDoUkl(Poloz);
    Rot.NazwaBrylaFinalna = Rot.WezNazwePliku_Bryla(Rot.KatObrotu, Rot.Poloz);
    return true;
}

bool Dron::DodajTrasePrzelotu(double KatObrot, double Dlugosc, PzG::LaczeDoGNUPlota &Lacze)
{
    std::ofstream StrmWyj("../datasets/trasa_przelotu.dat");

    if (!StrmWyj.is_open())
    {
        std::cerr << std::endl << "Nie mozna otworzyc do zapisu pliku: ../datasets/trasa_przelotu.dat" << std::endl << std::endl;
        return false;
    }
    KatObrot += KatObrotu;
    KatObrot *= M_PI/180;
    Vector3D PolozKonc = {Dlugosc * cos(KatObrot) + Poloz[0], Dlugosc * sin(KatObrot) + Poloz[1], Poloz[2]};
    StrmWyj << Poloz << std::endl << Poloz[0] << " " << Poloz[1] << " 80" << std::endl
            << PolozKonc[0] << " " << PolozKonc[1] << " 80" << std::endl << PolozKonc <<std::endl;
    Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat");
    return !StrmWyj.fail();
}

bool Dron::WykonajLot(double Dlug, double KatObr, PzG::LaczeDoGNUPlota &Lacze, int const adresDrona)
{
    
    std::cout << std::endl << "Wznoszenie ... " << std::endl;
    for(; Poloz[2] <= 80; Poloz[2] += 2)
    {
        if (!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
        usleep(100000);
        Lacze.Rysuj();
    }

    std::cout << "Lot do przodu ... " << std::endl;
    double x, y, a1, b;
    KatObr *= M_PI / 180;
    x = Dlug * cos(KatObr) + Poloz[0];
    y = Dlug * sin(KatObr) + Poloz[1];
    if (x != Poloz[0]){
        a1 = (x - Poloz[0]) / abs(x - Poloz[0]);
    }
    else {a1 = 0;}
    if (y != Poloz[2]){
        b = (y - Poloz[1]) / abs(x - Poloz[0]);
    }
    else {b = 0;}
    if (a1 > 0)
    {
        for (; Poloz[0] <= x; Poloz[0] += a1, Poloz[1] +=b)
        {
            if(!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
            usleep(100000);
            Lacze.Rysuj();
        }
    }
    if (a1 < 0)
    {
        for (; Poloz[0] >= x; Poloz[0] += a1, Poloz[1] +=b)
        {
            if(!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
            usleep(100000);
            Lacze.Rysuj();
        }
    }
    if (a1 == 0) 
    {
        if(y > Poloz[1])
        {
            b = 1;
            for (; Poloz[1] <= y; Poloz[1] +=b)
            {
                if(!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
                usleep(100000);
                Lacze.Rysuj();
            }
        }
        if(y < Poloz[1])
        {
            b = -1;
            for (; Poloz[1] >= y; Poloz[1] +=b)
            {
                if(!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
                usleep(100000);
                Lacze.Rysuj();
            }
        }
    }
    Poloz[0] = x; Poloz[1] = y;

    std::cout << "Opadanie ... " << std::endl;
    for (; Poloz[2] >= 2; Poloz[2] -= 2)
    {
        if (!Oblicz_i_zapisz_WspDrona(adresDrona)) return false;
        usleep(100000);
        Lacze.Rysuj();
    }
    return true;
}