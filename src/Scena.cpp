#include "Scena.hh"

void Scena::Menu()
{
    std::cout << "a - wybierz aktywnego drona" << std::endl;
    std::cout << "p - zadaj parametry przelotu" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
}

void Scena::UzyjAktywnegoDrona()
{
  Lacze.DodajNazwePliku("../bryly_wzorcowe/plaszczyzna.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron1_Korpus.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron1_Rotor1.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron1_Rotor2.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron1_Rotor3.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron1_Rotor4.dat");  
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron2_Korpus.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron2_Rotor1.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron2_Rotor2.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron2_Rotor3.dat");
  Lacze.DodajNazwePliku("../datasets/PlikWlasciwy_Dron2_Rotor4.dat");  
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);
  double KatDl, Dlug;
  Drony[0].KatObrotu = 0;
  Drony[0].Poloz = {20, 30, 2};
  Drony[0].Oblicz_i_zapisz_WspDrona(0);
  Drony[1].KatObrotu = 0;
  Drony[1].Poloz = {100, 70, 2};
  Drony[1].Oblicz_i_zapisz_WspDrona(1);
  Lacze.Rysuj();
  char WyborMenu = ' ';
  int AktywnyDron = 0;
  while (WyborMenu != 'k')
  {
    std::cout << "Polozenie Drona aktywnego (x, y):  " << Drony[AktywnyDron].Poloz[0] << " " << Drony[AktywnyDron].Poloz[1] << std::endl; 
    std::cout << "Twoj wybor <m - menu> ";
    std::cin >> WyborMenu;
    switch (WyborMenu)
    {
    case 'a':
        AktywnyDron = WezAktywnegoDrona(AktywnyDron);
        break;
    case 'p':
        std::cout << "Podaj kierunek lotu (kat w stopniach)>" << std::endl;
        std::cin >> KatDl;
        std::cout << "                   Podaj dlugosc lotu>" << std::endl;
        std::cin >> Dlug;
        std::cout << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << std::flush;
        std::cin.ignore(10000,'\n');
        Drony[AktywnyDron].DodajTrasePrzelotu(KatDl, Dlug, Lacze);
        Lacze.Rysuj();
        std::cout << "Nacisnij ENTER, aby wykonac animacje lotu drona" << std::flush;
        std::cin.ignore(10000,'\n');
        Drony[AktywnyDron].WykonajLot(Dlug, KatDl, Lacze, AktywnyDron);
        std::cout << std::endl << "Nacisnij ENTER, aby usunac sciezke ... " << std::flush;
        std::cin.ignore(10000,'\n');
        Lacze.UsunOstatniaNazwe();
        Lacze.Rysuj();
        break;
    case 'm':
        Menu();
        break;
    case 'k':
        std::cout << "Koniec dzialania programu" << std::endl;
        break;
    default:
        std::cout << "Nie ma takiej opcji!" << std::endl;
        break;
    }
  }

}

int Scena::WezAktywnegoDrona(int const AktywnyDron)
{
    std::cout << "Wybor aktywnego drona" << std::endl << std::endl;
    for (int i = 1; i <= 2; i++)
    {
        std::cout << i << " - Polozenie (x, y):  " << Drony[i-1].Poloz[0] << " " << Drony[i-1].Poloz[1];
        if  ((i-1) == AktywnyDron) {std::cout << " <-- Dron aktywny"; }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Wprowadz numer aktywnego drona> ";
    int adres;
    std::cin >> adres;
    std::cout << std::endl;
    return adres - 1;

}