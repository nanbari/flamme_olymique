#include "itineraireflamme.h"
#include<assert.h> 
#include <stdlib.h>

#define MAX_ETAPES 100

etape* creer_etape(region* r){
    assert(r!=NULL);
    etape* e = malloc(sizeof(etape));
    if(e==NULL)
        return NULL;
    e->value = r;
    e->next = NULL;

    return e;
}

struct itineraire_chaine_t{
    etape *premiere_case;
    unsigned int taille_itineraire;
};

itineraire_chaine* creer_itineraire_chaine(region* r1, region*r2){
    assert(r1 != NULL && r2 != NULL && r1 != r2);
    etape* e1 = creer_etape(r1);
    etape* e2 = creer_etape(r2);
    e1->next = e2;

    itineraire_chaine* i = malloc(sizeof(itineraire_chaine));
    if(i==NULL)
        return NULL;
    i->premiere_case= e1;
    i->taille_itineraire=2;

    return i;
}

unsigned int nb_total_habitants_chaine(itineraire_chaine* i){
    assert(i != NULL);
    etape* tmp = i->premiere_case;
    unsigned int res=0;
    while(tmp != NULL){
        res += get_nb_habitants(tmp->value);
        tmp = tmp->next;
    }
    return res;
}

etape* liste_ajout_fin(etape* e, region* r){
    assert(r != NULL);
    if(e != NULL){
        e->next = liste_ajout_fin(e->next,r);

    }else{
        return creer_etape(r);
    }
    return e;
}

void ajout_region_chaine(itineraire_chaine* i, region* r){
    assert(i != NULL && r != NULL);
    liste_ajout_fin(i->premiere_case, r);
    i->taille_itineraire++;

}

void liste_supprimer_fin(etape* e){
    assert(e != NULL);
    if(e->next->next == NULL){
        free(e->next);
        e->next = NULL;
    }else{
        liste_supprimer_fin(e->next);
    }
}

void supprime_region_chaine(itineraire_chaine* i){
    assert(i != NULL);
    liste_supprimer_fin(i->premiere_case);
    i->taille_itineraire--;
}




unsigned int nb_habitants_region_liste(itineraire_chaine* i, unsigned int j){
    assert(i != NULL);
    unsigned int cpt=0;
    etape* tmp = i->premiere_case;
    while(tmp != NULL){
        if (cpt == j){
            return get_nb_habitants(tmp->value);
        }
        tmp= tmp->next;
        cpt++;
    }
    return -1;

}
unsigned int nb_regions_chaine(itineraire_chaine* i){
    assert(i != NULL);
    return i->taille_itineraire;
}


int circuit_existe_chaine(itineraire_chaine* i){
    assert(i != NULL);
    for(etape* j=i->premiere_case; j->next != NULL; j=j->next){
        for(etape* k=i->premiere_case; k->next != NULL; k=k->next){
            if(j!=k && get_x(j->value) == get_x(k->value) && get_y(j->value) == get_y(k->value)){
                return 1;
            }

        }
    
    }
    
    return 0;
}
