
#include "gestionPort.h"

const char* correspTypes[] = {"Moteur", "Rame", "Voile"};


void viderBuffer (void)
{    
  while ( getchar() != '\n' );
}


Bateaux* saisirBateau(){
   Bateaux* b = malloc(sizeof(Bateaux));
   
   //TODO vérifier les entrées et vider buffer
   printf("Veuillez entrer un numero de plaque : \n");
   viderBuffer();
   scanf("%s", &(b->details.noPlaque));
   viderBuffer();
   printf("Veuillez entrer une longueur : \n");
   scanf("%f", &(b->details.longueur));
   printf("Bateau a moteur, rame ou voile? [0; 1; 2] : \n");
   scanf("%d", &(b->type));
   
   switch(b->type){
      case 0:
         printf("Veuillez entrer un nombre de moteurs : \n");
         scanf("%d", &(b->specType.moteur.nbMoteurs));
         printf("Veuillez entrer une puissance totale : \n");
         scanf("%f", &(b->specType.moteur.puissanceTotale));
         break;
      case 1:
         printf("Veuillez entrer un nombre de rames : \n");
         scanf("%d", &(b->specType.rame.nbRames));
         break;
      case 2:
         printf("Veuillez entrer une surface de voile : \n");
         scanf("%d", &(b->specType.voile.surfaceVoiles));
         break;
      default: printf("Type incorrect");
   }
   return b;
}

bool placerBateau(Bateaux* b){
   for(size_t i = 0; i < CAPACITE; ++i){
      if(port[i] != NULL){
         port[i] = b;
         return true;
      }
   }
   return false;
}

void libererPlace(const char** noPlaque){
   
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
   
}

void Parcourt(void (*f)(Bateaux)){
   
}

void afficherPort(){
   
}