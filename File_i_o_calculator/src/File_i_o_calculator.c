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
	FILE *fin, *fout; //указатели для обоих файлов
	fin = fonpen("content.txt","r");
	if (fin == NULL)
	    {
	         puts("Input file cannot be opened");
	    }
	fout = fopen("output.txt", "w");
	if (fout == NULL)
	    {
	       puts("Output file cannot be opened");
	    }







	return EXIT_SUCCESS;
}
