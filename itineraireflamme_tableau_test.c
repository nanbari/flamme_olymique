#include "seatest.h"
#include "region.h"
#include "itineraireflamme.h"
#include <stdlib.h>

static void test_nb_regions(){
        region* r1 = creer_region(15,15.5,"region1");
        region* r2 = creer_region(10,14,"region2");
        itineraire_tableau* i_tab = creer_itineraire_tableau(r1,r2);
        assert_int_equal(2, nb_regions_tableau(i_tab));

        free(r1);
        free(r2);
        free(i_tab);


}

static void test_ajout_region(){
        region* r1 = creer_region(15,15.5,"region1");
        region* r2 = creer_region(10,14,"region2");
        region* r3 = creer_region(5,15.3,"region3");
        itineraire_tableau* i_tab = creer_itineraire_tableau(r1,r2);
        ajout_region_tableau(i_tab,r3);
        assert_int_equal(3, nb_regions_tableau(i_tab));

        free(r1);
        free(r2);
        free(r3);
        free(i_tab);


}

static void test_fixture(){
    test_fixture_start();
    run_test(test_nb_regions);
    run_test(test_ajout_region);
    test_fixture_end();
}
static void all_tests(){
    test_fixture();
}
int main( ) {
    return run_tests(all_tests);
}