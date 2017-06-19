//
// Created by Soulier Antoine on 08/12/2016.
//

#include <stdio.h>
int goesUp(int pos);
int goesRight(int pos);
int goesDown(int pos);
int goesLeft(int pos);


int main(int argc, char *argv[]) {

    int cur, i = 0;
    char pos = 5;
    int code[5] = {0};

    printf("argv 0 : %s.\n", argv[0]);
    printf("argv 1 : %s.\n", argv[1]);


    if (argv[1] != NULL) {
        FILE* f = fopen(argv[1], "r");
        if (f != NULL) {
            do {
                cur = fgetc(f);

                switch(cur) {
                    case 'U':
                        pos = goesUp(pos);
                        break;
                    case 'R':
                        pos = goesRight(pos);
                        break;
                    case 'D':
                        pos = goesDown(pos);
                        break;
                    case 'L':
                        pos = goesLeft(pos);
                        break;
                    case 10:
                    case EOF:
                        code[i++] = pos;
                        break;
                }

            } while (cur != EOF);
        } else {
            printf("Could not open file.\n");
            return 1;
        }
    } else {
        printf("No file was provided.\n");
        return 1;
    }

    printf("The bathroom code is : ");
    int j;
    for (j = 0; j < 5; ++j) {
        printf("%d", code[j]);
    }
    return 0;
}

int goesUp(int pos) {
    switch(pos) {
        case 3:
            pos = 1;
            break;
        case 6:
            pos = 2;
            break;
        case 7:
            pos = 3;
            break;
        case 8:
            pos = 4;
            break;
        case 10: // A
            pos = 6;
            break;
        case 11: // B
            pos = 7;
            break;
        case 12: // C
            pos = 8;
            break;
        case 13: // D
            pos = 11;
            break;
    }

    return pos;
}

int goesRight(int pos) {
    switch(pos) {
        case 2:
            pos = 3;
            break;
        case 3:
            pos = 4;
            break;
        case 5:
            pos = 6;
            break;
        case 6:
            pos = 7;
            break;
        case 7:
            pos = 8;
            break;
        case 8:
            pos = 9;
            break;
        case 10: // A
            pos = 11;
            break;
        case 11: // B
            pos = 12;
            break;
    }

    return pos;
}

int goesDown(int pos) {
    switch(pos) {
        case 1:
            pos = 3;
            break;
        case 2:
            pos = 6;
            break;
        case 3:
            pos = 7;
            break;
        case 4:
            pos = 8;
            break;
        case 6:
            pos = 10;
            break;
        case 7:
            pos = 11;
            break;
        case 8:
            pos = 12;
            break;
        case 11: // B
            pos = 13;
            break;
    }

    return pos;
}

int goesLeft(int pos) {
    switch(pos) {
        case 3:
            pos = 2;
            break;
        case 4:
            pos = 3;
            break;
        case 6:
            pos = 5;
            break;
        case 7:
            pos = 6;
            break;
        case 8:
            pos = 7;
            break;
        case 9:
            pos = 8;
            break;
        case 11: // B
            pos = 10;
            break;
        case 12: // C
            pos = 11;
            break;
    }

    return pos;
}



/* For part 1 : */

/* int goesUp(int pos) {
    switch(pos) {
        case 4:
            pos = 1;
            break;
        case 5:
            pos = 2;
            break;
        case 6:
            pos = 3;
            break;
        case 7:
            pos = 4;
            break;
        case 8:
            pos = 5;
            break;
        case 9:
            pos = 6;
            break;
    }

    return pos;
}

int goesRight(int pos) {
    switch(pos) {
        case 1:
            pos = 2;
            break;
        case 4:
            pos = 5;
            break;
        case 7:
            pos = 8;
            break;
        case 2:
            pos = 3;
            break;
        case 5:
            pos = 6;
            break;
        case 8:
            pos = 9;
            break;
    }

    return pos;
}

int goesDown(int pos) {
    switch(pos) {
        case 1:
            pos = 4;
            break;
        case 2:
            pos = 5;
            break;
        case 3:
            pos = 6;
            break;
        case 4:
            pos = 7;
            break;
        case 5:
            pos = 8;
            break;
        case 6:
            pos = 9;
            break;
    }

    return pos;
}

int goesLeft(int pos) {
    switch(pos) {
        case 3:
            pos = 2;
            break;
        case 6:
            pos = 5;
            break;
        case 9:
            pos = 8;
            break;
        case 2:
            pos = 1;
            break;
        case 5:
            pos = 4;
            break;
        case 8:
            pos = 7;
            break;
    }

    return pos;
} */