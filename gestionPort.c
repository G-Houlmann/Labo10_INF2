/* 
 * File:   gestionPort.c
 * Author: Gildas Houlmann & Delphine Scherler
 * Date : 06.06.2019
 */

#include "gestionPort.h"
#include <string.h>
#include <stdbool.h>

const char* correspTypes[] = {"Moteur", "Rame", "Voile"};

//Fonction pour vider le buffer

void viderBuffer(void) {
   while (getchar() != '\n');
}

//Fonction permettant de saisir un entier

void saisirUnsigned(unsigned* ptr) {
   bool success;
   do {
      success = scanf("%d", ptr);
      viderBuffer();
   } while (!success && printf(MSG_ERREUR_SAISIE));
}

void saisirType(unsigned* ptr) {
   bool success;
   do {
      success = scanf("%d", ptr);
      viderBuffer();
   } while ((!success || *ptr >= NB_TYPES) && printf(MSG_ERREUR_SAISIE));
}

//Fonction permettant de saisir un float

void saisirFloat(float* ptr) {
   bool success;
   printf(inviteSaisie);
   do {
      success = scanf("%f", ptr);
      viderBuffer();
   } while (!success && printf(MSG_ERREUR_SAISIE));
}
//Fonction permettant de saisir une string (sous forme char*)

void saisirString(char** ptr, unsigned size) {
   bool success;
   *ptr = malloc(size * sizeof (char));
   do {
      success = scanf("%s", *ptr);
      viderBuffer();
   } while ((!success || strlen(*ptr) != size) && printf(MSG_ERREUR_SAISIE));
}
//Permet la saisie de tous les détails d’un bateau qui sera retourné par la fonction.
//Les erreurs de saisie sont gérées.

Bateaux* saisirBateau() {
   Bateaux* b = malloc(sizeof (Bateaux));

   printf("Veuillez entrer un numero de plaque de %d caracteres : \n", 
           TAILLE_PLAQUE_MAX);
   saisirString(&(b->details.noPlaque), TAILLE_PLAQUE_MAX);
   printf("Veuillez entrer une longueur : \n");
   saisirFloat(&(b->details.longueur));
   printf("Bateau a moteur, rame ou voile? [0; 1; 2] : \n");
   saisirType(&(b->type));

   switch (b->type) {
      case 0: //Moteur
         printf("Veuillez entrer un nombre de moteurs : \n");
         saisirUnsigned(&(b->specType.moteur.nbMoteurs));
         printf("Veuillez entrer une puissance totale : \n");
         saisirFloat(&(b->specType.moteur.puissanceTotale));
         break;
      case 1: //Rames
         printf("Veuillez entrer un nombre de rames : \n");
         saisirUnsigned(&(b->specType.rame.nbRames));
         break;
      case 2: //Voiles
         printf("Veuillez entrer une surface de voile : \n");
         saisirFloat(&(b->specType.voile.surfaceVoiles));
         break;
      default: printf("Type incorrect");
   }
   return b;
}

//Ajoute un bateau dans la première place libre du port.

bool placerBateau(Bateaux* b) {
   for (size_t i = 0; i < CAPACITE; ++i) {
      if (port[i] == NULL) {
         port[i] = b;
         return true;
      }
   }
   
   return false;
}
//Libère le bateau identifié par no de plaque reçu en paramètre.

void libererPlace(const char* noPlaque) {
   for (size_t i = 0; i < CAPACITE; ++i) {
      if (port[i] != NULL && port[i]->details.noPlaque == noPlaque) {
         free(port[i]);
         port[i] = NULL;
         break;
      }
   }
}

//Affiche tous les détails d’un bateau dont le no de plaque est reçu en paramètre.

void afficherDetails(const char* noPlaqueR) {
   Bateaux* b;
   bool found = false;
   for (size_t i = 0; i < CAPACITE; ++i) {
      if (port[i] != NULL && !strcmp(port[i]->details.noPlaque, noPlaqueR)) {
         b = port[i];
         found = true;
         break;
      }
   }
   if (found) {
      printf("Type de bateau : %s\n", correspTypes[b->type]);
      printf("no Plaque      : %s\n", b->details.noPlaque);
      printf("longueur       : %f\n", b->details.longueur);
      switch (b->type) {
         case 0: //Moteur
            printf("Nombre de moteurs : %d\n", b->specType.moteur.nbMoteurs);
            printf("Puissance totale  : %f\n", b->specType.moteur.puissanceTotale);
            break;
         case 1: //Rames
            printf("Nombre de rames   : %d\n", b->specType.rame.nbRames);
            break;
         case 2: //Voiles
            printf("Surface voiles  : %f\n", b->specType.voile.surfaceVoiles);
      }
   } else {
      printf("Bateau non trouve\n");
   }
}

//Affiche une place du port en indiquant le no de plaque, le type de bateau et sa 
//longueur. Si la place est libre, affiche « - ».

void afficherPlace(unsigned place) {
   if (place >= CAPACITE){
      printf("Numero de place invalide\n");
      return;
   }
   printf("Place no %d :\n", place);
   if (port[place] == NULL) {
      printf("-\n");
   } else {
      printf("no Plaque      : %s\n", port[place]->details.noPlaque);
      printf("Type de bateau : %s\n", correspTypes[port[place]->type]);
      printf("longueur       : %f\n", port[place]->details.longueur);
   }
   printf("\n");
}
//Fonction permettant un traitement à chacune des places du port.

void Parcourt(void (*f)()) {
   for (size_t i = 0; i < CAPACITE; ++i) {
      f(i);
   }
}

//Lister toutes les places du port.

void afficherPort() {
   printf("Affichage du port complet : \n");
   Parcourt(afficherPlace);
}