#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "resources.h"



int main(){
	initLogFile();
	char logEntrada[50];
	sprintf(logEntrada, "###################################");
	logIt(logEntrada);
	system("chcp 1252");
		
	int chutes[9] = {0}; //ARRAY PARA GUARDAR OS CHUTES DA TABUADA ATÉ A DIVISAO DO POR 9
	
	int posicao = 1; //LOCALICASAO DA DIVISAO ONLINE O JOGADOR ESTA FAZENDO O CALCULO
	
	int entrada; //CHUTE QUE O JOGADOR DIGITAR
	
	int completou = 0; //SE O JOGADOR CHUTAR TODOS OS 9 RESULTADOS ELE VIRA 1 E FINALIZA O JOGO
		
	int TABUADA = 0; //TABUADA DEFINIDA
	
	exibirMensagem();

	
	char auxiliar;
	do {
		printf("Escolha uma tabuada maior que 1 e menor que 10\nTabuada: ");
		scanf(" %c", &auxiliar);
	} while(!isdigit(auxiliar));
	TABUADA = auxiliar - '0';

	system("cls");
	//LOOP ATÉ O JOGADOR CHUTAR TODOS OS RESULTADOS
	while(!completou) { 
		//EXIBE TODOS OS DIVISORES
		int i;
		for(i = 1; i < 10; i++){
			if(posicao == i){ //SE ESTIVER NA POSICAO EM QUE O JOGADOR ESTÁ RESOLVENDO IRA MOSTRAR UMA SETA.
				printf("-> ");
			}
			
			if(chutes[i-1] != 0){ //SE O JOGADOR JÁ CHUTOU, ELE VAI EXIBIR O RESULTADO QUE O JOGADOR DIGITOU
				printf("Resultado de %d * %d: %d\n", TABUADA, i, chutes[i-1]);
			} else {
				printf("Resultado de %d * %d: __\n", TABUADA, i);
			}
		}
		
		scanf("%d", &entrada); //RECEBE O RESULTADO DO JOGADOR

		chutes[posicao - 1] = entrada; //GUARDA O RESULTADO DO JOGADOR NO ARRAY DE CHUTES

		posicao++;//MOVE O PONTEIRO DE SETA

		char * log;
		sprintf(log, "%s %d", "Recebido resultado:", entrada);
		logIt(log);
		
		if(posicao > 9){ //SE O PONTEIRO ESTIVER MAIOR QUE 9 FINALIZA O JOGO
			completou = 1;
		}
		system("cls");
	}
	//EXIBE OS RESULTADOS
	printf("Checando resultados...\n\n");
	
	int i;
	for(i = 0; i < 9; i++){
		int resultado = ( TABUADA * (i + 1) );
		int multiplicador = i+1;
		printf("Resultado de %d * %d: %d",TABUADA , multiplicador, chutes[i] );
		int acertou = chutes[i] == resultado;
		if(acertou) {
		 	printf(" <-- Acertou!\n");
		} else {
			printf(" <-- Errou! Resultado: %d\n", resultado);
		}

		char resultadoLog[20];
		sprintf(resultadoLog, "Resultado de %d * %d: %s", TABUADA, (multiplicador), (acertou ? "Incorreto" : "Correto"));
		logIt(resultadoLog);
	}
	char logSaida[50];
	sprintf(logSaida, "###################################");
	logIt(logSaida);
	closeFile();
}



