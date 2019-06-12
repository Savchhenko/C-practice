/*
 ============================================================================
 Name        : File_i_o_calculator.c
 Author      : Bear
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *fin, *fout;
	char c, one, two, v;
	int size;
	int *A, *B;

	fin = fopen("content.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%c", &c);
	one = c;
	fscanf(fin, "%c %c", &c);
	two = c;

	if (two == v) {
		fscanf(fin, "%c %c %c", &c);
		size = c;
		if (size != 0) {
			A = calloc(size, sizeof(A)); //выделение памяти под вектор
			B = calloc(size, sizeof(B));
		}

	}


	fclose(fin);
	fclose(fout);

	return EXIT_SUCCESS;
}
