#include "region.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define TAILLE_REGION 50
#define TAILLE_CHEF_LIEU 50
#define TAILLE_SPECIALITE 50

struct region_t{
    float x;
    float y;
    int nb_habitants;
    char nom_region[TAILLE_REGION] ;
    char chef_lieu[TAILLE_CHEF_LIEU];
    char specialite[TAILLE_SPECIALITE];
};

region * creer_region( float x, float y, char nom[]){
    assert(x>=0 && y>=0);
    region* reg = malloc(sizeof(region));
    if(reg==NULL)
        return NULL;
    reg->x = x;
    reg->y = y;
    int i;
    for(i =0; nom[i] != '\0'; i++){
        reg->nom_region[i]= nom[i];
    }
    reg->nom_region[i]='\0';
    reg->nb_habitants = 0;
    return reg;
}

float get_x(region* reg){
    assert(reg != NULL);
    return reg->x;
}

float get_y(region* reg){
    assert(reg != NULL);
    return reg->y;
}

char* get_nom_region(region* reg){
    assert(reg != NULL);
    return reg->nom_region;
}

char* get_chef_lieu(region* reg){
    assert(reg != NULL);
    return reg->chef_lieu;
    
}

int get_nb_habitants (region* reg){
    return reg->nb_habitants;
}
void set_nb_habitants(region* reg, int nb_hab){
    assert(reg != NULL && nb_hab >=0 );
    reg->nb_habitants=nb_hab;
}


float calcul_distance(region* r1, region* r2){
    assert(r1 != NULL && r2 !=NULL);
    return sqrt(pow(get_x(r2)-get_x(r1),2)+pow(get_y(r2)-get_y(r1),2));
}

