#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int cont = 0, menu, i, j, linha, coluna, clean = 0;
	char tabuleiro[4][5] = {{' ',' ','2','3','4'},
							{'1','|','#','#','#'},
							{'2','|','#','#','#'},
							{'3','|','#','#','#'}};
	printf("Jogo da velha em C!\n");
	printf("----------------------------------\n\n");
	while(cont != -1){
		menu = 1;
		if (clean == 1){
			printf("1 para jogar novamente!\n2 para sair do jogo!\n");
		    scanf("%d", &menu);
		    for (i = 1; i < 4; i++){
		    	for(j = 2; j < 5; j++){
		    		tabuleiro[i][j] = '#';	
				}
			}
			clean = 0;
		}
		if(menu == 1){
			for(i = 0; i < 5; i++){
				printf("\n");
				for(j = 0; j < 5; j++){
					printf("\t%c", tabuleiro[i][j]);
				}
				printf("\n");
			}
			cont = cont + 1;
			if(cont % 2 == 1){
				printf("Jogador [1]:\n");	
			}else{
				printf("Jogador [2]:\n");
			}
			printf("Escolha a linha para jogar:\n");
			scanf("%d", &linha);
			printf("Escolha uma coluna para jogar\n");
			scanf("%d", &coluna);
			if(tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){
				printf("Informe um campo que nao esteja preenchido!\n");
				continue;
			}
			if(linha > 0 && coluna > 1){
				if(cont % 2 == 1){
					tabuleiro[linha][coluna] = 'X';	
				}else{
					tabuleiro[linha][coluna] = 'O';
				}
			}
			if(cont == 9){
				printf("O jogo terminou em empate!\n");
			}
			if(linha > 0 && linha < 4 && coluna > 1 && coluna < 5){
					if(
    					(tabuleiro[1][2] == tabuleiro[1][3] && tabuleiro[1][3] == tabuleiro[1][4] && tabuleiro[1][2] != '#') ||
    					(tabuleiro[2][2] == tabuleiro[2][3] && tabuleiro[2][3] == tabuleiro[2][4] && tabuleiro[2][2] != '#') ||
    					(tabuleiro[3][2] == tabuleiro[3][3] && tabuleiro[3][3] == tabuleiro[3][4] && tabuleiro[3][2] != '#') ||
   						(tabuleiro[1][2] == tabuleiro[2][2] && tabuleiro[2][2] == tabuleiro[3][2] && tabuleiro[1][2] != '#') ||
    					(tabuleiro[1][3] == tabuleiro[2][3] && tabuleiro[2][3] == tabuleiro[3][3] && tabuleiro[1][3] != '#') ||
    					(tabuleiro[1][4] == tabuleiro[2][4] && tabuleiro[2][4] == tabuleiro[3][4] && tabuleiro[1][4] != '#') ||
   						(tabuleiro[1][2] == tabuleiro[2][3] && tabuleiro[2][3] == tabuleiro[3][4] && tabuleiro[1][2] != '#') ||
   						(tabuleiro[1][4] == tabuleiro[2][3] && tabuleiro[2][3] == tabuleiro[3][2] && tabuleiro[1][4] != '#') ){
    		if (cont % 2 == 1) {
        		printf("O jogador [1] venceu!\n");
    			clean = 1;
			} else {
        		clean = 1;
        		printf("O jogador [2] venceu!\n");
    				}
				}
			}else{
				while(linha < 1 || linha > 4 || coluna < 2 || coluna > 5){
					printf("Linhas ou colinas invalidas, preste atencao no tabuleiro!\n");
					printf("Escolha a linha para jogar:\n");
					scanf("%d", &linha);
					printf("Escolha uma coluna para jogar\n");
					scanf("%d", &coluna);
				if(cont % 2 == 1){
					tabuleiro[linha][coluna] = 'X';	
				}else{
					tabuleiro[linha][coluna] = 'O';
					}
				}	
			}
			printf("\n");
		}else{
			break;
		}
	}
	return 0;
}
