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
   Bateaux b = {MOTEUR,{"VD123", 34}, .specType.moteur =
      {.nbMoteurs = 3, .puissanceTotale = 4}};
   placerBateau(&b);
   

   Bateaux c = {MOTEUR,{"VD124", 34}, .specType.moteur =
      {.nbMoteurs = 3, .puissanceTotale = 4}};
   placerBateau(&c);

   
   libererPlace("VD123");
   
   Bateaux d = {MOTEUR,{"VD125", 34}, .specType.moteur =
      {.nbMoteurs = 3, .puissanceTotale = 4}};
   placerBateau(&d);
   
   
   
   Bateaux* e = saisirBateau();
   placerBateau(e);   
   afficherDetails("VD456");
   //afficherPort();
   //libererPlace("VD123");
   //afficherPort();
   //afficherDetails("VD123");
           
   
   return (EXIT_SUCCESS);
}