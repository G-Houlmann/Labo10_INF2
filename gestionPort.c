
#include "gestionPort.h"
const char* correspTypes[] = {"Moteur", "Rame", "Voile"};
Bateaux saisirBateau(){
   printf("Veuillez entrer un numero de plaque : ");
}

bool placerBateau(Bateaux b, unsigned place){
   //TODO Verifier place dans range
   port[place] = b;
}

void libererPlace(const char** noPlaque){
   
}

void afficherDetails(const char* noPlaque){
   
   Bateaux b;
   for(size_t i = 0; i < CAPACITE; ++i){
      if(port[i].details.noPlaque == noPlaque)
         b = port[i];
   }
   printf("Type de bateau : %s\n", correspTypes[b.type]);
   printf("no Plaque      : %s\n", b.details.noPlaque);
   printf("longueur       : %f\n", b.details.longueur);
   printf("no Plaque : %s\n", b.details.noPlaque);
   
}

void afficherPlace(unsigned place){
   
}

void Parcourt(void (*f)(Bateaux)){
   
}

void afficherPort(){
   
}