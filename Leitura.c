#include "Leitura.h"

void* getNumValido(const char *formato) {
	int ret;
	void* num;
	do {
		fflush(stdin);
		ret = scanf(formato, &num);
		fflush(stdin);
		if(ret != 1) {
			system("cls");
			printf("Numero invalido\nInforme novamente: ");
		} 
	} while(ret != 1);
	return num;
}

void* lerNumero(char *titulo, const char *tipoNum) {
	void* num;
	system("cls");
	printf("%s", titulo);
	num = getNumValido(tipoNum);
	return &num;	
}

void lerString(char *str, char *titulo, char*msgErro) {
	do {
		system("cls");
		printf(titulo);
		if(fgets(str, 100, stdin) == NULL) {
			printf("Erro ao ler string");
			break;
		}
		if (strlen(str) == 0 ){
			system("cls");
			printf(msgErro);
			system("pause");
		}
	}while(strlen(str) == 0);
}

