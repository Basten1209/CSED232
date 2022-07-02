#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE* infile = fopen("input.txt", "r");
    FILE* outfile = fopen("output.txt", "w");

    if (infile == NULL) {
        printf("ERROR!");
        exit(0);
    }

    char* arr[10000];
    char line[100];
    char temp[100];
    int num = 0;

    while (fscanf(infile, "%[^\n] ", line) != EOF) {
        char* newstpt = (char*)malloc(sizeof(char) * sizeof(line));
        arr[num] = newstpt;
        strcpy(arr[num], line);
        num++;
    }


    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(arr[i], arr[j]) == 1) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    for (int k = 0; k < num; k++) {
        fprintf(outfile, "%s\n", arr[k]);
    }

    fclose(infile);
    fclose(outfile);
    return 0;

}