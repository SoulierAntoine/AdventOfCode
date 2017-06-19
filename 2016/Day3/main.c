//
// Created by Soulier Antoine on 09/12/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strtoint(char* str);
int isTrianglePossible(int s1, int s2, int s3);

int main(int argc, char *argv[]) {

    int cur, j = 0, s1 = 0, s2 = 0, s3 = 0, possibleTriangles = 0;
    char n[5] = "";

    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);


    if (argv[1] != NULL) {
        FILE* f = fopen(argv[1], "r");
        if (f != NULL) {
            do {
                cur = fgetc(f);

                if (cur == ' ' || cur == EOF || cur == 10) {
                    if (n[0] != '\0') {
                        if (cur == 10 || cur == EOF) {
                            s3 = strtoint(n);

                            if (isTrianglePossible(s1, s2, s3)) {
                                possibleTriangles++;
                            }

                            s1 = s2 = s3 = 0;
                        } else {
                            if (s1 == 0) {
                                s1 = strtoint(n);
                            } else {
                                s2 = strtoint(n);
                            }
                        }

                        strcpy(n, "");
                    }
                }

                // cur is a number
                else {
                    while (n[j] != '\0')
                        j++;

                    n[j] = cur;
                    n[j+1] = '\0';
                    j = 0;
                }
            } while (cur != EOF);

            printf("There are %d possible triangles.\n", possibleTriangles);
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

int isTrianglePossible(int s1, int s2, int s3) {
    int longestSide = s1;

    if (s2 > longestSide) {
        longestSide = s2;
    }

    if (s3 > longestSide) {
        longestSide = s3;
    }

    return (s1 + s2 + s3 - longestSide) > longestSide;

}

// convert string to int
int strtoint(char* str) {
    return (int) strtol(str, NULL, 10);
}
