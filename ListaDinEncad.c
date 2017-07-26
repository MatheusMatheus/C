#include "ListaDinEncad.h"
#include "Leitura.c"

struct elemento {
	struct AlunoStruct *dados;
	struct elemento *prox;	
};

// Isso vai representar um único nó da lista
typedef struct elemento Elem;

int main(void) {
	Lista *li; // Início da lista
	li = criaLista();
	
	Aluno al;
	al.matricula = *(int*)lerNumero("Matricula do aluno: ", INTEIRO);
	lerString(al.nome, "Nome do aluno: ", "Nome invalido\n");
	al.n1 = *(float*)lerNumero("Nota 1: ", FLOAT);
	al.n2 = *(float*)lerNumero("Nota 2: ", FLOAT);
	al.n3 = *(float*)lerNumero("Nota 3: ", FLOAT);
	
}

Lista * criaLista() {
	Lista *li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

void insereInicioLista(Lista *li, Aluno al) {
	if (li == NULL) return;
	
	// Aloca um novo espaço de memória
	Elem *no = (Elem*) malloc(sizeof(Elem));
	
	// Verifica se a alocação ocorreu bem
	if(no == NULL) return;
	
	// Copia os dados
	no->dados = &al;
	
	// O nó recem criado vai apontar para o nó que o início da lista estava apontando (que era o primeiro)
	no->prox = (*li);
	
	// O início da lista aponta para o nó recém criado, que será o primeiro
	*li = no;
}

void mostraLista(Lista *li) {
	Elem *no = *li;
	while(no->prox != NULL) {
		printf("%-10d%-10.10s%-2.f%-2.f%-2.f", no->dados->matricula, no->dados->nome, no->dados->n1, no->dados->n2, no->dados->n3);
	}
}

void liberaLista(Lista *li) {
	if (li != NULL) {
		Elem *no;
		while((*li) != NULL) {
			no = *li;
			*li = (*li) -> prox;
			free(no);
		}
		free(li);
	}
}
