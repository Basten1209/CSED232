#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <math.h>

int main() {

	FILE* infile = fopen("input.txt", "r");
	FILE* outfile = fopen("output.txt", "w");

	if(infile == NULL) {
		printf("ERROR!");
		exit(0);
	}

	char op;
	float num1, num2;
	float result;

	while (!feof(infile)) {
		fscanf(infile, "%c %f %f\n", &op, &num1, &num2);

		if (op == '+') {
			result = num1 + num2;
			fprintf(outfile, "%0.3lf\n", round(result*1000)/1000);
		}
		if (op == '-') {
			result = num1 - num2;
			fprintf(outfile, "%0.3lf\n", round(result*1000)/1000);
		}
		if (op == '*') {
			result = num1 * num2;
			fprintf(outfile, "%0.3lf\n", round(result*1000)/1000);
		}
		if (op == '/') {
			result = num1 / num2;
			fprintf(outfile, "%0.3lf\n", round(result*1000)/1000);
		}

	}
	fclose(infile);
	fclose(outfile);
	return 0;
}

