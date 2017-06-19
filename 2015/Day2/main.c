//
// Created by Soulier Antoine on 07/12/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* min_array(int*, int, int);
int min(int*, int);
int strtoint(char*);


int main(int argc, char *argv[]) {
    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);

    // amount of dimensions
    const int N_DIM = 3;
    // amount of the minimal number we need to retrieve from the array (cf array_min)
    const int N_MIN = 2;

    int cur, i = 0, j = 0, r = 0, total = 0;
    int l, w, h;

    // will receive the string for the current dimension (length, width, and height)
    char d[10] = "";

    // create an array of N_DIM size
    int *s = NULL;
    s = malloc(N_DIM * sizeof(int));
    if (s == NULL)
        exit(0);

    // create an array of N_MIN size
    int *tab_min = NULL;
    tab_min = malloc(N_MIN * sizeof(int));
    if (tab_min == NULL)
        exit(0);


    if (argv[1] != NULL) {
        FILE* f = fopen(argv[1], "r");
        if (f != NULL) {
            do {
                cur = fgetc(f);

                // convert char and store it in s array
                if (cur == 'x') {
                    s[i] = strtoint(d);
                    strcpy(d, "");
                    i++;
                } else if (cur == '\n') {
                    s[i] = strtoint(d);
                    strcpy(d, "");

                    // formula to get surface area
                    l = s[0] * s[1];
                    w = s[1] * s[2];
                    h = s[0] * s[2];
                    total += 2 * l + 2 * w + 2 * h;

                    r += s[0] * s[1] * s[2];
                    // get the 2 minimal value in the s array
                    tab_min = min_array(s, N_DIM, N_MIN);
                    r += 2 * tab_min[0] + 2 * tab_min[1];

                    // get the minimal value in the s array after the value have been multiplicated
                    s[0] = l;
                    s[1] = w;
                    s[2] = h;
                    total += min(s, N_DIM);
                    i = 0;
                } else {
                    while (d[j] != '\0')
                        j++;

                    d[j] = cur;
                    d[j+1] = '\0';
                    j = 0;
                }
            } while (cur != EOF);

            fclose(f);
            free(s);
            free(tab_min);
        } else {
            printf("The file couldn't be opened.\n");
            return 1;
        }

        printf("The elves need %d square feet of wrapping paper.\n", total);
        printf("The elves need %d feet of ribbon.\n", r);
    } else {
        printf("No file was provided.\n");
        return 1;
    }

    return 0;
}


// returns minimal value of array tab
int min(int* tab, int length) {
    int min = tab[0], i;

    for (i = 1; i < length; i++) {
        if (min > tab[i])
            min = tab[i];
    }

    return min;
}


// returns the n lowest value of array tab (change the original tab though)
int* min_array(int* tab, int length, int n) {
    int i, j, pos_of_min = 0, min;

    if (n > length)
        exit(0);
    if (n == length)
        return tab;

    int *tab_min = NULL;
    tab_min = malloc(n * sizeof(int));
    if (tab_min == NULL)
        exit(0);

    for (j = 0; j < n; j++) {
        // redefine min at each iteration
        min = tab[0];

        // "-j" : loop the array one time less at each iteration
        for (i = 1; i < length-j; i++) {
            if (min >= tab[i]) {
                min = tab[i];
                pos_of_min = i;
            }
        }

        // "delete" element of array tab at position pos_of_min
        for (i = pos_of_min; i < length-1; i++)
            tab[i] = tab[i+1];

        tab_min[j] = min;
    }

    return tab_min;
}


// convert string to int
int strtoint(char* str) {
    long nb = strtol(str, NULL, 10);
    return (int) nb;
}
