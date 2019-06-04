/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: gilda
 *
 * Created on 28. mai 2019, 16:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "gestionPort.h"
/*
 * 
 */
int main(int argc, char** argv) {

   Bateaux b = {MOTEUR, {"12", 34}, .specType.moteur = {.nbMoteurs = 3 , .puissanceTotale = 4}};
   placerBateau(&b);
   //afficherDetails("12");
   Bateaux* c = saisirBateau();
   libererPlace("12");
   afficherDetails("34");
   return (EXIT_SUCCESS);
}

