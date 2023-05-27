#include "itineraireflamme.h"
#include <stdlib.h>
#include<assert.h>
#define MAX_ETAPES 100


struct itineraire_tableau_t{
    region* tableau_region[MAX_ETAPES];
    unsigned int taille_itineraire;

};

itineraire_tableau* creer_itineraire_tableau(region* r1, region*r2){
    assert(r1 != NULL && r2 != NULL && r1 != r2);
    itineraire_tableau* i = malloc(sizeof(itineraire_tableau));
    if(i==NULL)
        return NULL;
    i->tableau_region[0] = r1;
    i->tableau_region[1] = r2;
    i->taille_itineraire = 2;

    return i; 
}

unsigned int nb_total_habitants_tableau(itineraire_tableau* i){
    assert(i != NULL);
    unsigned int res = 0;
    for (unsigned int indice = 0; indice< i->taille_itineraire; indice++){
        res += get_nb_habitants(i->tableau_region[indice]);
    }
    return res;
}

unsigned int nb_regions_tableau(itineraire_tableau*i){
    assert(i != NULL);
    return i->taille_itineraire;
}

void ajout_region_tableau(itineraire_tableau* i, region* r){
    assert(i != NULL && r != NULL);
    i->tableau_region[i->taille_itineraire]=r;
    i->taille_itineraire++;
}

void supprime_region_tableau(itineraire_tableau* i){
    assert(i != NULL);
    i->taille_itineraire--;

}

unsigned int nb_habitants_region_tab(itineraire_tableau* i, unsigned int indice){
    assert(i != NULL && indice>0 && indice <= i->taille_itineraire );
    return get_nb_habitants(i->tableau_region[indice]);
}

int circuit_existe_tableau(itineraire_tableau* i){
    assert(i != NULL);
    for(unsigned int j=0; j<i->taille_itineraire; j++){
        for(unsigned int k=0; k<i->taille_itineraire; k++){
            if(j!=k && get_x(i->tableau_region[j]) == get_x(i->tableau_region[k]) && get_y(i->tableau_region[j]) == get_y(i->tableau_region[k])){
                return 1;
            }

        }
    
    }
    
    return 0;
}




