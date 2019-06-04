/* 
 * File:   main.c
 * Author: Gildas Houlmann & Delphine Scherler
 * Date : 06.06.2019
 * Summary : Laboratoire 10, le but étant d'organiser la gestion d'un port occupé par
 * des bateaux de différents types.
 */

#include <stdio.h>
#include <stdlib.h>
#include "gestionPort.h"

int main(void) {
   Bateaux b = {MOTEUR,{"12", 34}, .specType.moteur =
      {.nbMoteurs = 3, .puissanceTotale = 4}};
   placerBateau(&b);
   //afficherDetails("12");
   Bateaux* c = saisirBateau();
   libererPlace("12");
   afficherDetails("34");
   return (EXIT_SUCCESS);
}