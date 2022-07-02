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

    char map1[10][10]; //시작부터 k까지를 위한 map
    char map2[10][10]; //k부터 e까지를 위한 map
    int cnt = 1; //탐색 횟수를 담는 변수. 1로 스타트 하는 이유는 시작점 [0][0]때문.
    int x[100], y[100], l[100]; //탐색하는 배열 위치의 행, 열, 거리 값을 담을 1차원 배열
    int kx, ky, ex, ey; //k, e의 x, y 값
    int stok = 0; //시작점부터 k까지 거리
    int ktoe = 0; // k부터 e까지 거리

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(infile, "%c ", &map1[i][j]);
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map2[i][j] = map1[i][j];

            if (map1[i][j] == 'k') {
                kx = j;
                ky = i;
           }
            if (map1[i][j] == 'e') {
                ex = j;
                ey = i;
                    
            }
        }
    }
    int pos = 0;
    x[0] = 0;
    y[0] = 0;
    l[0] = 0;

    while (pos < cnt) {
        if (map1[y[pos]][x[pos]] == 'k') break;

        map1[y[pos]][x[pos]] = '1'; //최단거리이므로, 지나간 곳을 다시 지나면 안됨

        if ((y[pos] > 0) && (map1[y[pos] - 1][x[pos]] == '0')) { //윗칸 탐색
            x[cnt] = x[pos];
            y[cnt] = y[pos] - 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map1[y[pos] + 1][x[pos]] == '0')) { //아랫칸 탐색
            x[cnt] = x[pos];
            y[cnt] = y[pos] + 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((x[pos] > 0) && (map1[y[pos]][x[pos]-1] == '0')) { //왼쪽칸 탐색
            x[cnt] = x[pos] - 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map1[y[pos]][x[pos]+1] == '0')) { //오른칸 탐색
            x[cnt] = x[pos] + 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        pos++;
    }
    stok = l[pos-1];


    pos = 0;
    cnt = 1;
    for (int k = 0; k < 100; k++) {
        x[k] = 0;
        y[k] = 0;
        l[k] = 0;
    }
    x[0] = kx;
    y[0] = ky; //탐색을 위한 변수, 배열들 초기화 후 시작점 k로 잡기 

    while (pos < cnt) {
        if (map2[y[pos]][x[pos]] == 'e') break;

        map2[y[pos]][x[pos]] = '1'; //최단거리이므로, 지나간 곳을 다시 지나면 안됨

        if ((y[pos] > 0) && (map2[y[pos] - 1][x[pos]] == '0')) { //윗칸 탐색
            x[cnt] = x[pos];
            y[cnt] = y[pos] - 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map2[y[pos] + 1][x[pos]] == '0')) { //아랫칸 탐색
            x[cnt] = x[pos];
            y[cnt] = y[pos] + 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((x[pos] > 0) && (map2[y[pos]][x[pos] - 1] == '0')) { //왼쪽칸 탐색
            x[cnt] = x[pos] - 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map2[y[pos]][x[pos] + 1] == '0')) { //오른칸 탐색
            x[cnt] = x[pos] + 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        pos++;
    }
    ktoe = l[pos - 1];

    fprintf(outfile, "%d", stok+ktoe);
    fclose(infile);
    fclose(outfile);
    return 0;

}