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

    char map1[10][10]; //���ۺ��� k������ ���� map
    char map2[10][10]; //k���� e������ ���� map
    int cnt = 1; //Ž�� Ƚ���� ��� ����. 1�� ��ŸƮ �ϴ� ������ ������ [0][0]����.
    int x[100], y[100], l[100]; //Ž���ϴ� �迭 ��ġ�� ��, ��, �Ÿ� ���� ���� 1���� �迭
    int kx, ky, ex, ey; //k, e�� x, y ��
    int stok = 0; //���������� k���� �Ÿ�
    int ktoe = 0; // k���� e���� �Ÿ�

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

        map1[y[pos]][x[pos]] = '1'; //�ִܰŸ��̹Ƿ�, ������ ���� �ٽ� ������ �ȵ�

        if ((y[pos] > 0) && (map1[y[pos] - 1][x[pos]] == '0')) { //��ĭ Ž��
            x[cnt] = x[pos];
            y[cnt] = y[pos] - 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map1[y[pos] + 1][x[pos]] == '0')) { //�Ʒ�ĭ Ž��
            x[cnt] = x[pos];
            y[cnt] = y[pos] + 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((x[pos] > 0) && (map1[y[pos]][x[pos]-1] == '0')) { //����ĭ Ž��
            x[cnt] = x[pos] - 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map1[y[pos]][x[pos]+1] == '0')) { //����ĭ Ž��
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
    y[0] = ky; //Ž���� ���� ����, �迭�� �ʱ�ȭ �� ������ k�� ��� 

    while (pos < cnt) {
        if (map2[y[pos]][x[pos]] == 'e') break;

        map2[y[pos]][x[pos]] = '1'; //�ִܰŸ��̹Ƿ�, ������ ���� �ٽ� ������ �ȵ�

        if ((y[pos] > 0) && (map2[y[pos] - 1][x[pos]] == '0')) { //��ĭ Ž��
            x[cnt] = x[pos];
            y[cnt] = y[pos] - 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map2[y[pos] + 1][x[pos]] == '0')) { //�Ʒ�ĭ Ž��
            x[cnt] = x[pos];
            y[cnt] = y[pos] + 1;
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((x[pos] > 0) && (map2[y[pos]][x[pos] - 1] == '0')) { //����ĭ Ž��
            x[cnt] = x[pos] - 1;
            y[cnt] = y[pos];
            l[cnt] = l[pos] + 1;
            cnt++;
        }
        if ((y[pos] < 9) && (map2[y[pos]][x[pos] + 1] == '0')) { //����ĭ Ž��
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