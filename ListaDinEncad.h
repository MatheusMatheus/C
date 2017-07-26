#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING "%s"
#define INTEIRO "%d"
#define FLOAT "%f"

typedef struct AlunoStruct {
	int matricula;
	char nome[100];
	float n1, n2, n3;
} Aluno;

// Isso vai representar o início da lista
// Observar que é um ponteiro para ponteiro
typedef struct elemento* Lista;

// Protótipos
Lista * criaLista();
void liberaLista(Lista *li);
void insereInicioLista(Lista *li, Aluno al);
