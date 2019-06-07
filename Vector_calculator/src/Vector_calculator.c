/*
 ============================================================================
 Name        : Vector_calculator.c
 Author      : Bear
 Version     :
 Copyright   : Your copyright notice
 Description : Vector Calculator in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float *A, *B;
	int size;
	printf("Enter the number of coordinates of vectors: ");
	scanf("%i", &size);
	if (size != 0) {
		A = calloc(size, sizeof(A));
		B = calloc(size, sizeof(B));
	}
	printf("Enter coordinates of first vector: ");
	for (int i = 0; i < size; i++) {
		scanf("%f", &A[i]);
	}
	printf("Enter coordinates of second vector: ");
	for (int i = 0; i < size; i++ ) {
		scanf("%f", &B[i]);
	}

	char choice;
	printf("\"+\"-Vector addition\n\"-\"-Vector difference\n\"*\"-Scalar multiplication of vectors\n ");
	printf("Choose the operation:\n");
	scanf(" %c", &choice);

	float t = 0;
	switch (choice) {
	case '+':
		printf("New vector: ");
		for (int i = 0; i < size; i++) {
			printf("%.1f", A[i] + B[i]);
		}
		break;
	case '-':
		printf("New vector: ");
		for (int i = 0; i < size; i++) {
			printf("%.1f", A[i] - B[i]);
		}
		break;
	case '*':
		for (int i = 0; i < size; i++) {
			t = t + A[i] * B[i];
		}
		printf("%.1f", t);
		break;
	}
	free(A);
	free(B);

    return EXIT_SUCCESS;
}
