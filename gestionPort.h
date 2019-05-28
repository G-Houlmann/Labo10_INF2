#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#define CAPACITE 40

enum Types {
   MOTEUR, RAME, VOILE
};

typedef struct {
   char* type;
} Bateaux;

union {
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

#endif /* GESTIONPORT_H */