#include <stdio.h>
#include <stdio.h>
#include <time.h>
FILE *fileLog;
time_t t;
char * currentTime;

void exibirMensagem(){
	printf("|-______________________________________________________________________________-|\n");
	printf("|                                                                                |\n");
	printf("|                      BEM VINDO AO JOGO DE TABUADA                              |\n");
	printf("|                         PRONTO PARA CALCULAR ?                                 |\n");
	printf("|                                                                                |\n");
	printf("|-______________________________________________________________________________-|\n\n\n\n");
	
	printf("Academicos: Jonas & Noel\n");
	printf("PROBLEMA \n");
	printf("Ajudar alunos com dificuldade de aprendizado nos calculos, principalmente para decorar a tabuada.\n");
	printf("SOLUÇÃO \n");
	printf("Apresentar a tabuada ao aluno, e ajuda-lo a resolver as questões de multiplicação\n");
	printf("OBJECTIVO \n");
	printf("Melhorar o aprendizado do aluno ao que se refere a cálculos\n\n\n\n");
}

void initLogFile() {
	fileLog = fopen("log.txt", "a");
	if(!fileLog) {
		printf("Falha ao abrir o arquivo\n");
	} else {
		printf("Arquivo de log aberto com sucesso!\n");
	}
}


void logIt(char * msg) {
	t = time(NULL);
	currentTime = ctime(&t);

	fprintf(fileLog, "%s -> %s ", currentTime, msg);
}

void closeFile(){
	fclose(fileLog);
}
