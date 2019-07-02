#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct element { //очередь с данными из файла
    char ch[15];
    struct element *next;
} element;
element *last = NULL;
element *head = NULL;
int rear = 1;

typedef struct node {     //очередь с результатами
    float value;
    struct node *next_node;
} node;
node *tail = NULL;
node *start = NULL;


void insert ( FILE* fin) {
    element *tmp = (element*)calloc(1,sizeof(element));
    tmp->next = NULL;
    fscanf(fin, "%c", &tmp->ch[0]);
    int size = 0;
    if (tmp->ch[0] == '$') //знак="прекращение"
    {
        free(tmp);
        rear =0;
    }
    else {
		while (tmp->ch[size] != ' ')
		{
			size++;
			fscanf(fin, "%c", &tmp->ch[size]);
		}
		if  (last != NULL)
		{
			last->next = tmp;
			tmp->next = NULL;
		}
		else {
				head = tmp;
		     }
    }
    last = tmp;
}


int main(void) {
FILE *fin;
fin = fopen("input.txt","r");
while (rear)
{
    insert( fin);
}
fclose(fin);
FILE  *fout;
fout = fopen("output.txt","w");
while( head != NULL)
{
    if (head->ch[0] != 'f')
    {
             if (head->ch[0] == '+'|| head->ch[0] == '*'|| head->ch[0] == '/'|| (head->ch[0] == '-'
                       && head->ch[1] == ' ')) {

                   switch (head->ch[0])
                   {
                   case '+':
                       start->next_node->value = start->next_node->value + start->value;
                       break;
                   case '-':
                       start->next_node->value = start->next_node->value - start->value;
                       break;
                   case '*':
                       start->next_node->value = start->next_node->value * start->value;
                       break;
                   case '/':
                       start->next_node->value = start->next_node->value / start->value;
                       break;
                   }
				   tail = start;
				   start = start->next_node;
				   free(tail);
				                              }
           else {
                   node *tmp = (node*)malloc(sizeof(node));
                   tmp->value = atof(head->ch);   //Функция atof преобразует строку в значение типа double
                   tmp->next_node = start;
                   start = tmp;
                 }
    }
    else
           {
               fprintf(fout, "%.2f\n", start->value);
               free(start);
           }
    head = head->next;
}
fclose(fout);
return 0;
}
