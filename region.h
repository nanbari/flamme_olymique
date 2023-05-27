#ifndef __REGION__
#define __REGION__

typedef struct region_t region;
/*
 * @pre: x>=0 && y>=0 
 * @post: une région de coordonées x et y et dont le nom est celui passé en paramètre  est crée 
 */
region* creer_region( float x, float y, char nom[] );
/*
 * @pre: reg != NULL
 * @post: renvoie la position en x de la region reg 
 */
float get_x(region* reg);
/*
 * @pre: reg != NULL
 * @post: renvoie la position en y de la region reg 
 */
float get_y(region* reg);
/*
 * @pre: reg != NULL
 * @post: renvoie un pointeur vers le nom de la region.
 */
char* get_nom_region (region* reg);
/*
 * @pre: r1 != NULL && r2 !=NULL 
 * @post: renvoie le distance entre la region r1 et la region r2
 */
float calcul_distance(region* r1, region* r2);
/*
 * @pre: reg != NULL && nb_habitants >=0 
 * @post: le nb_habitants de la region reg vaut nb_hab
 */
void set_nb_habitants(region* reg, int nb_hab);
/*
 * @pre: reg != NULL
 * @post: renvoie un pointeur vers le chef_lieu
 */
char* get_chef_lieu(region* reg);
/*
 * @pre: reg != NULL
 * @post: renvoie le nombre d'habitants de la region.
 */
int get_nb_habitants (region* reg);

#endif
