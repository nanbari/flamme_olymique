#ifndef __ITINERAIRE__
#define __ITINERAIRE__
#include "region.h"

typedef struct itineraire_chaine_t itineraire_chaine;

typedef struct etape_t{
    region *value;
    struct etape_t *next;
}etape;

typedef struct itineraire_tableau_t itineraire_tableau;
/*
 * @pre: r != NULL
 * @post: Création d'une étape de la liste chaînée
 */
etape* creer_etape(region* r);
/*
 * @pre: r != NULL 
 * @post: Une étape dont le champ value vaut la région r est rajoutée à la suite des étapes suivants e
 */
etape* liste_ajout_fin(etape* e, region* r);
/*
 * @pre: e != NULL
 * @post: Supprime la dernière étape des étapes suivants e
 */
void liste_supprimer_fin(etape* e);
/*
 * @pre: r1 != NULL && r2 != NULL && r1 != r2
 * @post: Création d'une liste chainée représentant l'itineraire, c'est à dire une suite de regions.
 */
itineraire_chaine* creer_itineraire_chaine(region* r1, region*r2);
/*
 * @pre: r1 != NULL && r2 != NULL && r1 != r2
 * @post: Création d'un tableau représentant l'itineraire, c'est à dire une suite de regions.
 */
itineraire_tableau* creer_itineraire_tableau(region* r1, region*r2);
/*
 * @pre: i != NULL 
 * @post: renvoie le nombre total d’habitants dans l’itinéraire 
 */
unsigned int nb_total_habitants_chaine(itineraire_chaine* i);
/*
 * @pre: i != NULL 
 * @post: renvoie le nombre total d’habitants dans l’itinéraire
 */
unsigned int nb_total_habitants_tableau(itineraire_tableau* i);
/*
 * @pre: i != NULL && r != NULL
 * @post: rajoute une region à la suite des region déjà existentes dans le tableau représentant l'itineraire 
 */
void ajout_region_tableau(itineraire_tableau* i, region* r);
/*
 * @pre: i != NULL && r != NULL
 * @post: rajoute une étape à la suite des étapes déjà existentes dans la liste chainée représentant l'itineraire 
 */
void ajout_region_chaine(itineraire_chaine* i, region* r);
/*
 * @pre: i != NULL
 * @post: supprime la dernière étape de la liste chainée représentant l'itineraire 
 */
void supprime_region_chaine(itineraire_chaine* i);
/*
 * @pre: i != NULL 
 * @post: supprime la dernière region du tableau représentant l'itineraire 
 */
void supprime_region_tableau(itineraire_tableau* i);

/*
 * @pre: i != NULL && indice >= 0 && indice<= taille_itineraire
 * @post: renvoie le nombre d'habitants de la region de la chaine compris dans la jème étape,
 * renvoie -1 si indice est supérieur à taille_itineraire.
 */
unsigned int nb_habitants_region_liste(itineraire_chaine* i, unsigned int j);
/*
 * @pre: i != NULL && indice >= 0 && indice <= taille_itineraire
 * @post: renvoie le nombre d'habitants de la region du tableau d'indice indice. 
 */
unsigned int nb_habitants_region_tab(itineraire_tableau* i, unsigned int indice);
/*
 * @pre: i != NULL 
 * @post: renvoie le nombre de régions de l'itineraire i  
 */
unsigned int nb_regions_chaine(itineraire_chaine* i);
/*
 * @pre: i != NULL 
 * @post: renvoie le nombre de régions de l'itineraire i  
 */
unsigned int nb_regions_tableau(itineraire_tableau*i);
/*
 * @pre: i != NULL
 * @post: renvoie 0 si un circuit n'existe pas et 1 si le circuit existe
 */
int circuit_existe_tableau(itineraire_tableau* i);
/*
 * @pre: i != NULL
 * @post: renvoie 0 si un circuit n'existe pas et 1 si le circuit existe
 */
int circuit_existe_chaine(itineraire_chaine* i);

#endif
