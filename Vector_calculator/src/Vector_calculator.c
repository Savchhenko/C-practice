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

	int Ax, Ay, Bx, By, sum_x, sum_y, dif_x, dif_y, mult;
	printf("Enter Ax: ");
	scanf("%i", &Ax);
	printf("Enter Ay: ");
	scanf("%i", &Ay);
	printf("Enter Bx: ");
	scanf("%i", &Bx);
	printf("Enter By: ");
	scanf("%i", &By);
	sum_x = Ax + Bx;
	sum_y = Ay + By;
	printf("Vector addition:\n");
	printf("vector AB = ( %i; %i)\n", sum_x, sum_y);

	dif_x = Ax -Bx;
	dif_y = Ay - By;
	printf("\nVector difference:\n");
	printf("vector AB = ( %i; %i)\n", dif_x, dif_y);

	mult = Ax * Bx + Ay * By;
	printf("\nScalar multiplication of vectors:\n");
	printf("result <AB>= %i", mult);





	return EXIT_SUCCESS;
}
