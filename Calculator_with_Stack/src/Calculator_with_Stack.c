/*
 ============================================================================
 Name        : Calculator_with_Stack.c
 Author      : Bear
 Copyright   : This work belongs to the student Alexandra Savchenko
 Description : Использованием стека для реализации калькулятора с обратной польской нотацией.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float factorial(float n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


typedef struct element {
    float value;
    struct element *next;
} element;


void push(element **head, float value) {     //кладёт элемент на вершину стека
    element *tmp = malloc(sizeof(element));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


float pop(element **head) {     //снимает элемент с вершины стека, перемещая вершину к следующему элементу
    element *out;
    float value;
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    FILE *fin , *fout ;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt" , "w");
    element *head = NULL;
    char oper; //операция для вычислений
    float A,B,x,y; //А,В- численные значения, x,y-переменные для реализации вычислений
    while (!feof(fin)) //пока не конец файла
        {
			fscanf(fin,"%f %f %c", &A ,&B ,&oper);
			push(&head, A);
			push(&head, B);
			if (oper == '+')
			{
				x = pop(&head);
				y = pop(&head);
				fprintf(fout,"A+B=%.2f\n", x+y);
			}
			if (oper == '-'){
					x = pop(&head);
					y = pop(&head);
					fprintf(fout,"A-B=%.2f\n", x-y);
				}
			if (oper == '*'){
					x = pop(&head);
					y = pop(&head);
					fprintf(fout,"A*B=%.2f\n", x*y);
				}
			if (oper == '/'){
					x = pop(&head);
					y = pop(&head);
					fprintf(fout,"A/B=%.2f\n", x/y);
				}
			if (oper == '^'){
					x = pop(&head);
					y = pop(&head);
					fprintf(fout,"A^B=%.2f\n", pow(x,y));
				}
			if (oper == '!'){
					x = pop(&head);
					y = pop(&head);
					fprintf(fout,"A!=%f\n", factorial(x));
				}
        }
}
