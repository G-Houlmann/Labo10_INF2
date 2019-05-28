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


Bateaux port[CAPACITE];

Bateaux saisirBateau();

bool placerBateau(Bateaux b, unsigned place);

void libererPlace(const char** noPlaque);

void afficherDetails(const char** noPlaque);

void afficherPlace(unsigned place);

void Parcourt();

void afficherPort();

#endif /* GESTIONPORT_H */

