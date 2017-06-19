//
// Created by Soulier Antoine on 07/12/2016.
//

#include <stdio.h>

int main(int argc, char *argv[]) {

    int goUp = 0, goDown = 0, pos = 0, basement = 0, cur, goFloor;
    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);

    if (argv[1] != NULL) {
        FILE* f = fopen(argv[1], "r");

        if (f != NULL) {
            do {
                cur = fgetc(f);

                if (cur == '(') {
                    goUp++;

                } else if (cur == ')') {
                    goDown++;
                }

                pos++;
                // !basement otherwise the variable basement would be updated each time (goUp - goDown) == -1
                if ((goUp - goDown) == -1 && !basement)
                    basement = pos;
            } while (cur != EOF);

            fclose(f);
        } else {
            printf("The file couldn't be opened.\n");
            return 1;
        }

        goFloor = goUp - goDown;
    } else {
        printf("No file was provided.\n");
        return 1;
    }

    printf("( count : %d.\n", goUp);
    printf(") count : %d.\n", goDown);

    printf("Santa must go to the floor %d.\n", goFloor);
    printf("Santa went to the basement for the first time at the position %d.\n", basement);

    return 0;
}
