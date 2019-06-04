
#include "gestionPort.h"
#include <string.h>
#include <stdbool.h>

const char* correspTypes[] = {"Moteur", "Rame", "Voile"};


void viderBuffer (void)
{    
  while ( getchar() != '\n' );
}


void saisirUnsigned(unsigned* ptr){
   bool success;
   do{
      success = scanf("%d", ptr);
   }while(!success);
}

void saisirFloat(float* ptr){
   bool success;
   do{
      success = scanf("%f", ptr);
   }while(!success);
}

void saisirString(char* ptr, unsigned size){
   bool success;
   char* str = malloc(size * sizeof(char));
   do{
      success = scanf("%s", str);
   }while(!success);
   ptr = str;
}

Bateaux* saisirBateau(){
   Bateaux* b = malloc(sizeof(Bateaux));
   
   //TODO vérifier les entrées et vider buffer
   printf("Veuillez entrer un numero de plaque : \n");
   saisirString((b->details.noPlaque), TAILLE_PLAQUE_MAX);
   printf("Veuillez entrer une longueur : \n");
   saisirFloat(&(b->details.longueur));
   printf("Bateau a moteur, rame ou voile? [0; 1; 2] : \n");
   saisirUnsigned(&(b->type));
   
   switch(b->type){
      case 0:
         printf("Veuillez entrer un nombre de moteurs : \n");
         saisirUnsigned(&(b->specType.moteur.nbMoteurs));
         printf("Veuillez entrer une puissance totale : \n");
         saisirFloat(&(b->specType.moteur.puissanceTotale));
         break;
      case 1:
         printf("Veuillez entrer un nombre de rames : \n");
         saisirUnsigned(&(b->specType.rame.nbRames));
         break;
      case 2:
         printf("Veuillez entrer une surface de voile : \n");
         saisirFloat(&(b->specType.voile.surfaceVoiles));
         break;
      default: printf("Type incorrect");
   }
   return b;
}

bool placerBateau(Bateaux* b){
   for(size_t i = 0; i < CAPACITE; ++i){
      if(port[i] == NULL){
         port[i] = b;
         return true;
      }
   }
   return false;
}

void libererPlace(const char* noPlaque){
   for(size_t i = 0; i < CAPACITE; ++i){
      if( port[i] != NULL && port[i]->details.noPlaque == noPlaque){
         free(port[i]);
         port[i] = NULL;
         break;
      }   
   }
}

void afficherDetails(const char* noPlaqueR){
   
   Bateaux* b;
   bool found = false;
   for(size_t i = 0; i < CAPACITE; ++i){
      if( port[i] != NULL && *(port[i]->details.noPlaque) == *noPlaqueR){
         b = port[i];
         found = true;
         break;
      }   
   }
   if(found){
      printf("Type de bateau : %s\n", correspTypes[b->type]);
      printf("no Plaque      : %s\n", b->details.noPlaque);
      printf("longueur       : %f\n", b->details.longueur);
      switch(b->type){
         case 0: 
            printf("Nombre de moteurs : %d\n", b->specType.moteur.nbMoteurs);
            printf("Puissance totale  : %f\n", b->specType.moteur.puissanceTotale);
            break;
         case 1:
            printf("Nombre de rames   : %d\n", b->specType.rame.nbRames);
            break;
         case 2:
            printf("Surface voiles  : %f\n", b->specType.voile.surfaceVoiles);
      }
   }
   else{
      printf("Bateau non trouve\n");
   }
   
}

void afficherPlace(unsigned place){
   if(place >= CAPACITE) return;
   if(port[place] == NULL){
      printf("-\n");
   }else{
      printf("no Plaque      : %s\n", port[place]->details.noPlaque);
      printf("Type de bateau : %s\n", correspTypes[port[place]->type]);
      printf("longueur       : %f\n", port[place]->details.longueur);
   }
}

void Parcourt(void (*f)()){
   for(size_t i = 0; i < CAPACITE; ++i){
      f(i);
   }
}

void afficherPort(){
   Parcourt(afficherPlace);
}