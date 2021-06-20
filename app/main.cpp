// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>


#include "exampleConfig.h"
#include "example.h"
#include "Vector3D.hh"
#include "Scena.hh"
#include "Dron.hh"
#include "../inc/lacze_do_gnuplota.hh"




int main() {

  Scena LotDrona;
  LotDrona.UzyjAktywnegoDrona();  

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
