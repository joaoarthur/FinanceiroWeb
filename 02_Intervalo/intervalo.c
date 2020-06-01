/*
####################################################################################
#
#	Nome Programa: intervalo.c
#	Autor: João Arthur
#	Solicitante: Globo.com
#	Objetivo: Coletar um conjunto de valores inteiros e imprimir ordenadamente separado por intervalos.
#	Ex: 
#		Entrada: 10,22,9,5,7,21,6,23,8,1,19,17,100,20	
#		Saida: [1],[5-10],[17],[19-23],[100]
#	Versionamento:
#	1.0: Criação. Resp.: João Arthur
#	
#	Parâmetros de execução
#	./intervalo
#
####################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLISTA 100

//funcao de ordenacao com algoritmo quick sort
//param1 = vetor a ser ordenado, param2 = posicao inicial do vetor, param 3 = posicao final do vetor
void quick_sort(unsigned long *a, int left, int right);
//funcao para imprimir o vetor.
//Param1 = vetor a ser impersso, param2 = tamanho do vetor
void imprime (unsigned long vet[], int tam);
//funcao que gera invervalos continuos dado uma sequencia numerica
//Param1 = vetor com um conjunto numerico ordenado, param2= indice do ultimo elemento do vetor
void gera_Intervalos(unsigned long *vet, int tam);
 
//Funcao principal
int main(int argc, char **argv) {
	
	//declaracao das variaveis necessarias para a leitura dos valores do STDIN
	char buffer[4096];
	char *valor;
	unsigned long valores[MAXLISTA];
	unsigned long elementos;

	//incializando variaveis.
	elementos = 0;	
	buffer[0]='\0';
	printf("Passar conjunto de valores numericos separados por \",\" em qualquer ordem.\n");
	printf("Ex: 10,22,9,5,7,21,6,23,8,1,19,17,100,20\n\n\n");
	// Pegando valores de STDIN
	fgets(buffer,4095,stdin);

	// Separando valores por vírgulas e adicionando ao vetor de elementos
	valor = strtok(buffer,",");

	while (valor != NULL) {
		unsigned long num = atol(valor);
		valores[elementos] = num;
		++elementos;
		valor = strtok(NULL,",");
	}


	// Ordena os valores do vetor em ordem crescente O(n logn)
	quick_sort(valores, 0, elementos - 1);

	printf("\n\nValores ordenados\n");
	imprime(valores, elementos);
	//Imprime os valores do vetor separados por intervalos
	gera_Intervalos (valores,elementos -1);
 
}

void gera_Intervalos(unsigned long *vet, int tam){
	int i;
	int menor, maior;
	
	//inicializa variaveis do intervao com primeiro elemento.
	menor = vet[0];
	maior = vet[0];
	printf("\nIntervalo final\n");
	
	for(i = 0; i < tam; i++){
		//Se o numero atual+1 é igual ao proximo numero, a sequencia ainda eh valida;
		if (vet[i] + 1 == vet[i+1]){
			maior = vet[i+1];
		}
		else{
			//Terminou a sequencia atual, montando saida
			if (menor == maior){
				//Intervalo com apenas 1 numero
				printf("[%lu],",vet[i]);
			} else {
				//Intervalo com 2 ou mais numeros
				printf("[%d-%d],",menor,maior);
			}
			//nova sequencia comeca com proximo elemento do vetor.
			menor = vet[i+1];
			maior = vet[i+1];
		}
	}
	//ao final verificar que o ultimo numero faz parte como maior de um intervalo ou eh um intervalo de apenas 1 numero.
	if (menor == vet[tam]){
		printf("[%lu]",vet[i]);
	}else{
		printf("[%d-%d]",menor,maior);
	}
	printf("\n");
} 

//algoritmo padrao de ordenacao para vetores com O(nlogn). Podendo ser usada a funcao qsort tambem.
void quick_sort(unsigned long *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void imprime (unsigned long vet[], int tam){
 int i;
 printf("[");
 for(i = 0; i < tam -1 ; i++)
 {
  printf("%lu,", vet[i]);
 }	
 printf("%lu]\n",vet[tam -1]);
}
