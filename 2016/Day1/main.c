//
// Created by Soulier Antoine on 07/12/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int x;
    int y;
} Position;

int determineFace(int cur, int next);
int strtoint(char* str);
int checkIfAlreadyVisited(Position *p, Position *everyPosition, int numberOfPositions);



int main(int argc, char *argv[]) {

    int cur, i = 0, j = 0, x = 0, y = 0, blocks = 0, numberOfPositions = 1, alreadyVisited = 0;

    // 1 = north, 2 = east, 3 = south, 4 = east
    unsigned short face = 1;
    char n[5] = "";

    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);


    if (argv[1] != NULL) {
        Position *everyPosition = malloc(sizeof(Position));
        // equivalent of (*everyPosition).x = 0;
        everyPosition->x = x;
        everyPosition->y = y;


        FILE* f = fopen(argv[1], "r");
        if (f != NULL) {
            do {
                cur = fgetc(f);

                if (cur == ',' || cur == EOF) {
                    int dir = strtoint(n);

                    numberOfPositions += dir;
                    everyPosition = realloc(everyPosition, dir * sizeof(Position));

                    for (i = 0; i < dir; ++i) {
                        switch (face) {
                            case 1:
                                y++;
                                break;
                            case 2:
                                x++;
                                break;
                            case 3:
                                y--;
                                break;
                            case 4:
                                x--;
                                break;
                        }

                        Position currentPosition = {x, y};
                        if (!alreadyVisited && checkIfAlreadyVisited(&currentPosition, everyPosition, numberOfPositions)) {
                            alreadyVisited = 1;
                            printf("You've already visited the position [%d;%d] which is %d blocks away.\n", x, y, abs(x) + abs(y));
                        }

                        (everyPosition + i)->x = x;
                        (everyPosition + i)->y = y;
                    }
                }

                else if (cur == ' ') {
                    continue;
                }

                else if (cur == 'R' || cur == 'L') {
                    face = determineFace(face, cur);

                    if (n[0] != '\0') {
                        strcpy(n, "");
                    }
                }

                // else cur is a number
                else {
                    while (n[j] != '\0')
                        j++;

                    n[j] = cur;
                    n[j+1] = '\0';
                    j = 0;
                }
            } while (cur != EOF);

            blocks = abs(x) + abs(y);
        } else {
            printf("Could not open file.\n");
            return 1;
        }

        free(everyPosition);
        printf("You went to the position [%d;%d] which is %d blocks away.\n", x, y, blocks);
    } else {
        printf("No file was provided.\n");
        return 1;
    }


    return 0;
}

int checkIfAlreadyVisited(Position *p, Position *everyPosition, int numberOfPositions) {
    int i;
    for (i = 0; i < numberOfPositions; ++i) {
        if (p->x == (everyPosition + i)->x && p->y == (everyPosition + i)->y) {
            return 1;
        }
    }

    return 0;
}

int determineFace(int cur, int next) {
    switch(cur) {
        case 1:
            if (next == 'R') {
                cur = 2;
            } else {
                cur = 4;
            }
            break;
        case 2:
            if (next == 'R') {
                cur = 3;
            } else {
                cur = 1;
            }
            break;
        case 3:
            if (next == 'R') {
                cur = 4;
            } else {
                cur = 2;
            }
            break;
        case 4:
            if (next == 'R') {
                cur = 1;
            } else {
                cur = 3;
            }
            break;
    }

    return cur;
}

// convert string to int
int strtoint(char* str) {
    return (int) strtol(str, NULL, 10);
}
