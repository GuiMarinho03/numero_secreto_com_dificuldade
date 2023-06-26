#include <stdio.h>
#include <locale.h> //setlocale (colocar acento)
#include <stdlib.h> //system("cls") limpar tela
#include <time.h> 	// Biblioteca para Time(0).


int main() {
	setlocale(LC_ALL, "portuguese");
	
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
	
	int segundos = time(0);
	srand(segundos);
	
 	int num_grande = rand();
	
	int num_sec = num_grande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	
	int i;
	
	int acertou = 0;
	
	int nivel;
	printf ("Qual o nivel de dificuldade?\n");
	printf ("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf ("Escolha: ");
	scanf ("%d", &nivel);
	
	int numero_tentativas;
	/* if	(nivel == 1){
		numero_tentativas = 20;
	}
	else if (nivel == 2){
		numero_tentativas = 15;
	}
	else
	{
 	   	numero_tentativas = 6;
	} */
		
	switch (nivel) {
		case 1:
			numero_tentativas = 20;
			break;
		
		case 2:
			numero_tentativas = 15;
			break;
			
		default: //"Else" do switch
			numero_tentativas = 6;			  		
			break;
		}
	
	for (i = 1; i <= numero_tentativas; i++)
	{
		printf 	("\nTentativa %d\n", tentativas);
		printf  ("Qual o seu chute? ");
		scanf	("%d", &chute);
		printf  ("Seu chute foi: %d\n", chute);
		
		if	(chute < 0){
			printf ("Você não pode chutar números negativos!\n");
			printf ("***************************************\n");
			continue;
		}
				
		
		acertou = (chute == num_sec);
		int maior = (chute > num_sec);
		
	   	if (acertou){
			break;
		}
		else
		{
			if (maior){
				printf ("Seu chute foi maior que o número secreto\n");
				printf  ("*****************************************\n");
			} else {
				printf ("Seu chute foi menor que o número secreto\n");   	
				printf  ("*****************************************\n");
			}
			
			tentativas++;	
			
			double pontosperdidos = abs(chute - num_sec) / (double)2; // convertendo para DOUBLE.
			pontos = pontos - pontosperdidos;
		}
	
	}
		printf 	("Fim de Jogo!\n");
		
		if (acertou) {
		   	printf("             OOOOOOOOOOO               \n");
			printf("         OOOOOOOOOOOOOOOOOOO           \n");
        	printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        	printf("    OOOOOO      OOOOO      OOOOOO      \n");
	        printf("  OOOOOOOO      OOOOO      OOOOOOOO    \n");
	        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
	        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
	        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
	        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
	        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
	        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
	        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
	        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
	        printf("         OOOOOO         OOOOOO         \n");
	        printf("             OOOOOOOOOOOO              \n");
	        printf("\n\n");
	
	        printf("Parabéns! Você ganhou!\n");
	        printf("Você acertou em %d tentativas!\n", tentativas);
	        printf("Total de pontos: %.1f\n", pontos);
		} else
		{
			printf ("Você perdeu! Tente de novo!\n");
			printf ("O número secreto era %d!\n", num_sec);
	    	printf("       \\|/ ____ \\|/    \n");
        	printf("        @~/ ,. \\~@      \n");
        	printf("       /_( \\__/ )_\\    \n");
        	printf("          \\__U_/        \n");
		}
			
	
}
