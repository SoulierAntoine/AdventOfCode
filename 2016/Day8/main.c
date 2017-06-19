//
// Created by Soulier Antoine on 13/12/2016.
//

#include "netpbm/pam.h"

int main(int argc, char *argv[]) {

    /* FILE *fp;
    gray **pix;
    pix = pgm_allocarray(1, 1); */
    // pgm_writepgm(fp,pix,largeur_en_pixels, hauteur_en_pixels,255,0);
    // fclose(fp);
    // pgm_freearray(pix,hauteur_en_pixels);

    struct pam inpam, outpam;
    tuple * tuplerow;
    unsigned int row;

    sample grand_total;
    pm_init(argv[0], 0);

    pnm_readpaminit(fopen(argv[1], "r"), &inpam, PAM_STRUCT_SIZE(tuple_type));

    outpam = inpam; outpam.file = stdout;

    pnm_writepaminit(&outpam);

    tuplerow = pnm_allocpamrow(&inpam);

    for (row = 0; row < inpam.height; ++row) {
        unsigned int column;
        pnm_readpamrow(&inpam, tuplerow);
        for (column = 0; column < inpam.width; ++column) {
            unsigned int plane;
            for (plane = 0; plane < inpam.depth; ++plane) {
                grand_total += tuplerow[column][plane];
            }
        }
        pnm_writepamrow(&outpam, tuplerow);
    }
    pnm_freepamrow(tuplerow);

    return 0;
}