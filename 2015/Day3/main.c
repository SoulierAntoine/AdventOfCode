//
// Created by Soulier Antoine on 07/12/2016.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int cur;
    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);

    if (argv[1] != NULL) {
        FILE* f = fopen(argv[1], "r");

        if (f != NULL) {
            do {
                cur = fgetc(f);

            } while (cur != EOF);
        } else {
            printf("Could not open file.\n");
            return 1;
        }
    } else {
        printf("No file was provided.\n");
        return 1;
    }


    return 0;
}
