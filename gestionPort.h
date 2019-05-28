#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define CAPACITE 40
#define NB_TYPES 3

typedef enum  {
   MOTEUR, RAME, VOILE
} Types;




typedef struct {
   char* noPlaque;
   float longueur;
} Details;

typedef struct {
   unsigned nbMoteurs;
   float puissanceTotale;
} Moteur;

typedef struct {
   unsigned nbRames;
} Rame;

typedef struct {
   float surfaceVoiles;
} Voile;

typedef union {
   Moteur moteur;
   Rame rame;
   Voile voile;
} SpecType;

typedef struct {
   Types type;
   Details details;
   SpecType specType;
} Bateaux;


Bateaux port[CAPACITE];

Bateaux saisirBateau();

bool placerBateau(Bateaux b, unsigned place);

void libererPlace(const char** noPlaque);

void afficherDetails(const char* noPlaque);

void afficherPlace(unsigned place);

void Parcourt();

void afficherPort();

#endif /* GESTIONPORT_H */

