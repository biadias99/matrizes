/* Trabalho de Matrizes
Bianca Dias Barbosa e Henrique Marciano da Silva
BSI - 2018*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define i 20
#define j 20
#define N 2

int pegaLinha();
int pegaColuna();
void pegaMatriz(int matriz[][i][j], int linha, int coluna, int num, int m);
void somaMatrizes(int matriz[][i][j], int num, int m);
void imprimeMatriz(int matrizResultante[][j], int linha, int coluna, int t);
void subtraiMatrizes(int matriz[][i][j], int num, int m);
void multiplicaMatrizes(int matriz[][i][j], int num, int m);
void verificaSimetria(int matriz[][i][j], int num, int m);
void verificaQuadradoMagico(int matriz[][i][j], int num, int m);
int verificaLinha(int matrizResultante[][j], int linha, int coluna);
int verificaColuna(int matrizResultante[][j], int linha, int coluna);
void verificaQuadradoLatino(int matriz[][i][j], int num, int m);
int verificaPermutacao(int matrizResultante[][j], int linha, int coluna);
void verificaMatrizPermutacao(int matriz[][i][j], int num, int m);
void resolverSistemaLinearInferior(int matriz[][i][j], int num, int m);
int verificaInferior(float matrizResultante[][j], int linha, int coluna);
int verificaSuperior(float matrizResultante[][j], int linha, int coluna);
void resolverSistemaLinearSuperior(int matriz[][i][j], int num, int m);
void ajuda();
void sobre();
void menuOperacoes(int matriz[][i][j]);
void menuVerificacao(int matriz[][i][j]);
void matrizTransposta(int matriz[][i][j]);
void menuSistemaLinear(int matriz[][i][j]);
void menu ();
void sair ();
void hideCursor();
void showCursor();
void gotoxy (int x, int y);

int main(){
	system("mode con:cols=120 lines=30");
	menu();
}

//Fun��es

void menu(){
	system("cls");
	int tecla;
	int cont = 0;
	int matriz[N][i][j];

	system("color 07");

	hideCursor();

	gotoxy(50,1);printf("MENU PRINCIPAL");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Operacoes entre matrizes");
	gotoxy(10,6);printf("Verificacao");
	gotoxy(10,8);printf("Determinar matriz transposta");
	gotoxy(10,10);printf("Resolva um sistema linear triangular");
	gotoxy(10,12);printf("Sobre");
	gotoxy(10,15);printf("<ESC> Sair");
	gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();

   		if(tecla == 80 && cont<=6){ // para baixo
   			gotoxy(8,4+cont);printf("  ");
   			cont+=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 72 && cont>0){ // para cima
   			gotoxy(8,4+cont);printf("  ");
   			cont-=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 13){
			switch(cont){
				case 0:
					menuOperacoes(matriz);
					break;
				case 2:
					menuVerificacao(matriz);
					break;
				case 4:
					matrizTransposta(matriz);
					break;
				case 6:
					menuSistemaLinear(matriz);
					break;
				case 8:
					sobre();
					break;
			}
		}

		if(tecla==32){
			ajuda();
		}
	}

	sair();

}

void ajuda(){
	gotoxy(52,17);printf("AJUDA");
	gotoxy(10,19);printf("Utilize as setas do seu teclado para mover o quadradinho para cima ou para baixo.");
	gotoxy(10,20);printf("Para escolher uma opcao, aperte ENTER.");
	gotoxy(10,21);printf("Para finalizar o programa, aperte ESC");
	gotoxy(10,22);printf("Divirta-se e aprenda muita matematica!");
}

void sobre(){
	int tecla = 32;
	system("cls");
	system("color 1F");
	gotoxy(50,1);printf("SOBRE - MATRIZES");
	printf("\n\n\tTrabalho de matrizes desenvolvido por Bianca Dias e Henrique Marciano\n\t");
	printf("\n\tDisciplina: Algoritmos I\n\t");
	printf("\n\tProfessora: Andrea");
	printf("\n\n\t\t\t\tBSI - 2018");
	printf("\n\n\n\t<ESC> Voltar ao menu principal.");

	tecla = getch();

	while(tecla!=27){
		tecla = getch();
	}

	if(tecla == 27)
		menu();
}

int pegaColuna(){
    showCursor();
    int coluna;
    do{
        system("cls");
        gotoxy(50,1);printf("COLUNA");
        gotoxy(10,3);printf("Digite um valor para a coluna da matriz (maximo: 20): ");
        scanf("%d",&coluna);
    } while(coluna <= 0 || coluna > 20);
    return coluna;
}

int pegaLinha(){
    showCursor();
    int linha;
    do{
        system("cls");
        gotoxy(50,1);printf("LINHA");
        gotoxy(10,3);printf("Digite um valor para a linha da matriz (maximo: 20): ");
        scanf("%d",&linha);
    } while(linha <= 0 || linha > 20);
    return linha;
}

void pegaMatriz(int matriz[][i][j], int linha, int coluna, int num, int m){
	system("cls");
	int a, b, c, aux;
	for(c = 0; c < num; c++){
        if(m == 1 && c == 1)
        {
           aux = linha;
           linha = coluna;
           coluna = aux;
        }
        gotoxy(10,2);printf("Insira os elementos da matriz (%dx%d) %d: ",linha,coluna, c + 1);

        for(a=0;a<linha;a++){
            for(b=0;b<coluna;b++){
                scanf("%d",&matriz[c][a][b]);
            }
        }
        system("cls");
	}
}

void exibeMatriz(int matriz[][i][j], int linha, int coluna, int num, int m)
{
    hideCursor();
    int a, b, c, aux;
    printf("\n\n\n");
    for(c = 0; c < num; c++){
         if(m == 1 && c == 1)
        {
           aux = linha;
           linha = coluna;
           coluna = aux;
        }
        printf("Matriz %d: ", c + 1);
        putchar('\n');
        for(a=0;a<linha;a++){
            for(b=0;b<coluna;b++){
                printf("%3d ",matriz[c][a][b]);
            }
            printf("\n");
        }
        printf("\n\n\n");
	}
}

void menuOperacoes(int matriz[][i][j]){// definir valor MAXIMO da matriz, mas o usuario informa o tamanho dela.
    system("cls");
	int tecla;
	int cont = 0;
	system("cls");
	gotoxy(50,1);printf("OPERACOES");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Soma de duas matrizes");
	gotoxy(10,6);printf("Subtracao de duas matrizes");
	gotoxy(10,8);printf("Multiplicacao de duas matrizes");
	gotoxy(10,10);printf("Voltar");
	gotoxy(10,15);printf("<ESC> Sair");
	//gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();

   		if(tecla == 80 && cont<=4){ // para baixo
   			gotoxy(8,4+cont);printf("  ");
   			cont+=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 72 && cont>0){ // para cima
   			gotoxy(8,4+cont);printf("  ");
   			cont-=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 13){
			switch(cont){
				case 0:
					somaMatrizes(matriz, 2, 0);
					break;
				case 2:
					subtraiMatrizes(matriz, 2, 0);
					break;
				case 4:
					multiplicaMatrizes(matriz, 2, 1);
					break;
				case 6:
					menu();
					break;
			}
		}
	}

	sair();

}

void somaMatrizes(int matriz[][i][j], int num, int m){
    int a, b;
    char tecla;
    int linha, coluna;
    linha = pegaLinha();
    coluna = pegaColuna();
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    hideCursor();
    exibeMatriz(matriz, linha, coluna, num, m);
    gotoxy(50,1);printf("SOMA DE MATRIZES");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b] + matriz[1][a][b];
        }
    }
    imprimeMatriz(matrizResultante, linha, coluna, 0);

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuOperacoes(matriz);
    else if(tecla == 27)
        sair();
}

void imprimeMatriz(int matrizResultante[][j], int linha, int coluna, int t){
    gotoxy(30,1);printf("Pressione alguma tecla para ver a matriz resultante: "); //ideia para n sobrescrever a matriz 2.
    getch();
    system("cls");
    hideCursor();
    int a, b, aux;
    printf("\n\n\n");
    printf("Matriz resultante: \n\n"); //matriz resultante ta sobrescrevendo a matriz 2 quando passa de 4x4.
    if(t == 1){
       aux = linha;
       linha = coluna;
       coluna = aux;
    }
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
        	if(t == 1){
        		printf("%3d ",matrizResultante[b][a]);
			}else{
				printf("%3d ",matrizResultante[a][b]);
			}
        }
        printf("\n");
    }
}

void subtraiMatrizes(int matriz[][i][j], int num, int m){
    int a, b;
    char tecla;
    int linha, coluna;
    linha = pegaLinha();
    coluna = pegaColuna();
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    exibeMatriz(matriz, linha, coluna, num, m);
    gotoxy(50,1);printf("SUBTRACAO DE MATRIZES");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b] - matriz[1][a][b];
        }
    }
    imprimeMatriz(matrizResultante, linha, coluna, 0);

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuOperacoes(matriz);
    else if(tecla == 27)
        sair();
}

void multiplicaMatrizes(int matriz[][i][j], int num, int m){
    int a, b, c, aux = 0, coluna1;
    char tecla;
    int linha, coluna;
    linha = pegaLinha();
    coluna = pegaColuna();
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    exibeMatriz(matriz, linha, coluna, num, m);
    coluna1 = coluna;
    coluna = linha;
    gotoxy(50,1);printf("MULTIPLICACAO DE MATRIZES");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = 0;
            for(c = 0; c < coluna1; c++){
                aux += matriz[0][a][c] * matriz[1][c][b];
            }
            matrizResultante[a][b] = aux;
            aux = 0;
        }
    }
    imprimeMatriz(matrizResultante, linha, coluna, 0);

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuOperacoes(matriz);
    else if(tecla == 27)
        sair();
}

void menuVerificacao(int matriz[][i][j]){
    system("cls");
	int tecla;
	int cont = 0;

	gotoxy(50,1);printf("VERIFICACOES");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Verificar se a matriz eh simetrica");
	gotoxy(10,6);printf("Verificar se a matriz eh um quadrado magico");
	gotoxy(10,8);printf("Verificar se a matriz eh um quadrado latino");
	gotoxy(10,10);printf("Verificar se a matriz eh uma matriz de permutacao");
	gotoxy(10,12);printf("Voltar");
	gotoxy(10,15);printf("<ESC> Sair");
	//gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();

   		if(tecla == 80 && cont<=6){ // para baixo
   			gotoxy(8,4+cont);printf("  ");
   			cont+=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 72 && cont>0){ // para cima
   			gotoxy(8,4+cont);printf("  ");
   			cont-=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 13){
			switch(cont){
				case 0:
					verificaSimetria(matriz, 1, 0);
					break;
				case 2:
					verificaQuadradoMagico(matriz,1,0);
					break;
				case 4:
					verificaQuadradoLatino(matriz,1,0);
					break;
				case 6:
					verificaMatrizPermutacao(matriz, 1, 0);
					break;
				case 8:
					menu();
					break;
			}
        }
   	}

    if(tecla == 27)
        sair();

}

void verificaSimetria(int matriz[][i][j], int num, int m){
    gotoxy(50,1);printf("VERIFICAR SIMETRIA");
    int a, b, cont = 0;
    char tecla;
    int linha, coluna;
    linha = pegaLinha();
    coluna = pegaColuna();
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    exibeMatriz(matriz, linha, coluna, num, m);
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
        }
    }
    for(a = 0; a < linha; a++){ //verifica simetria;
        for(b = 0; b < coluna; b++){
            if(matrizResultante[a][b] == matrizResultante[b][a])
                cont++;
        }
    }
    if(cont == linha * coluna) //verifica simetria e imprime;
        printf("Sua Matriz eh simetrica.");
    else
        printf("Sua matriz nao eh simetrica.\n\n");
            if(linha != coluna)
                printf("Observacao: nao existe matriz simetrica que nao seja quadrada, ex: 3x3.");

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuVerificacao(matriz);
    else if(tecla == 27)
        sair();
}

void verificaQuadradoMagico(int matriz[][i][j], int num, int m){
    gotoxy(50,1);printf("VERIFICAR QUADRADO MAGICO");
    int a, b, somaL[20], somaC[20], somaD[2] = {0, 0}, cont = 0;
    char tecla;
    int linha, coluna;
    linha = pegaLinha();
    coluna = pegaColuna();
    while(linha != coluna){
        system("cls");
        gotoxy(20,1);printf("A matriz deve ser quadrada para verificar se eh um quadrado magico(ex: 3x3).");
        gotoxy(20,2);printf("Pressione alguma tecla para digitar novamente..");
        getch();
        linha = pegaLinha();
        coluna = pegaColuna();
    }
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    exibeMatriz(matriz, linha, coluna, num, m);
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
        }
    }
    /*--------------------------ZERA SOMAS---------------------------------*/
    for(a = 0; a < linha; a++){
        somaL[a] = 0;
        somaC[a] = 0;
    }
    /*--------------------SOMA LINHA, COLUNA E DIAGONAIS-------------------*/
    int x = 0, y = 1;
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            somaL[a] += matrizResultante[a][b];
            somaC[a] += matrizResultante[b][a];
            if(a == b)
                somaD[0] += matrizResultante[a][b];
            if(a == x && b == coluna - y){
                somaD[1] += matrizResultante[a][b];
                x++;
                y++;
            }
        }
    }
    /*----------------------VERIFICA QUADRADO MAGICO-----------------------*/
    y = 1;
    for(a = 0; a < 1; a++)
        for(b = 0; b < coluna; b++){
            if(y != coluna)
                if(somaL[a] == somaL[y])
                    cont++;
            if(somaL[a] == somaC[b])
                cont++;
            y++;
        }
        if(somaL[0] == somaD[0])
                cont++;
        if(somaL[0] == somaD[1])
                cont++;

    if(cont == linha + coluna + 1)
        printf("Sua matriz eh um quadrado magico!");
    else
        printf("Sua matriz nao eh um quadrado magico!");

    /*---------------------------------------------------------------------*/

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuVerificacao(matriz);
    else if(tecla == 27)
        sair();
}

int verificaLinha(int matrizResultante[][j], int linha, int coluna){
	int a, b, c, aux, cont = 0;
	int d, e, f;
	int somaLinha = 0;
	int soma = 0;
	int v[linha*coluna];
	int igual = 0;

	for(a=1;a<=linha;a++){
		soma+=a;
		v[a-1]=a;
	}

	aux = linha;

	if(linha == coluna){
		//verificar se todos os elementos da linha realmente s�o iguais ao n�mero
		for(a = 0; a < linha; a++){
			somaLinha = 0;
	        for(b = 0; b < coluna; b++){
	        	cont = 0;
	        	somaLinha+=matrizResultante[a][b];
	        	for(c = 1; c <= aux; c++){
	        		if(matrizResultante[a][b] != c){
	        			cont++;
					}
				}
				if(cont == aux){ // se o numero for maior que o numero de linha
					return 0; // � diferente de todos os elementos
				}
				igual = 0;
				for(f=0;f<linha;f++){
					if(matrizResultante[a][b] == v[f]){
						igual++;
					}
				}
				if(igual>1){ // se tiver elemento repetido
					return 0;
				}
	        }
	        if(somaLinha != soma){ // se a soma n for igual a soma padr�o da linha
	        	return 0;
			}
    	}

				if(cont == aux){
					return 0; // � diferente de todos os elementos
				}

    	return 1;
	}else{
		return 0;
	}
}

int verificaColuna(int matrizResultante[][j], int linha, int coluna){
	int a, b, c, d, e, f, aux, cont = 0;
	int soma = 0;
	int somaColuna = 0;
	int v[linha*coluna];
	int igual = 0;
	aux = linha;

	for(a=1;a<=linha;a++){
		soma+=a;
		v[a-1]=a;
	}

	if(linha == coluna){
		//verificar se todos os elementos da coluna realmente s�o iguais ao n�mero
		for(a = 0; a < coluna; a++){
			somaColuna = 0;
	        for(b = 0; b < linha; b++){
	        	cont = 0;
	        	somaColuna+=matrizResultante[b][a];
	        	for(c = 1; c <= aux; c++){
	        		if(matrizResultante[b][a] != c){
	        			cont++;
					}
				}
				if(cont == aux){
					return 0; // � diferente de todos os elementos
				}
				igual = 0;
				for(f=0;f<linha;f++){
					if(matrizResultante[a][b] == v[f]){
						igual++;
					}
				}
				if(igual>1){
					return 0;
				}
	        }
	        if(somaColuna != soma){
	        	return 0;
			}
    	}
    	return 1;
	}else{
		return 0;
	}
}

void verificaQuadradoLatino(int matriz[][i][j], int num, int m){
    int a, b;
    char tecla;
    int linha, coluna;
    int latino = 1;
    linha = pegaLinha();
    coluna = pegaColuna();
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    hideCursor();
    gotoxy(50,1);printf("QUADRADO LATINO");
    printf("\n");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
            printf("%d ",matrizResultante[a][b]);
        }
        printf("\n");
    }

  	latino = verificaLinha(matrizResultante,linha,coluna);


  	if(latino != 0)
  		latino = verificaColuna(matrizResultante,linha,coluna);


  	latino = verificaColuna(matrizResultante,linha,coluna);


    if(latino)
        printf("\n\nSua matriz eh um quadrado latino");
    else
        printf("\n\nSua matriz nao eh um quadrado latino\n\n");
            if(linha != coluna)
                printf("Observacao: nao existe uma matriz que seja um quadrado latino que nao seja quadrada, ex: 3x3.");


    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuVerificacao(matriz);
    else if(tecla == 27)
        sair();
}

int verificaPermutacao(int matrizResultante[][j], int linha, int coluna){
    int a, b, cont = 0;
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            if(matrizResultante[a][b] != 1 && matrizResultante[a][b] != 0)
                return 0;
            if(matrizResultante[a][b] == 1)
                cont++;
        }
    }
    return cont;
}

void verificaMatrizPermutacao(int matriz[][i][j], int num, int m){
     gotoxy(50,1);printf("VERIFICAR MATRIZ PERMUTACAO");
    int a, b;
    char tecla;
    int linha, coluna, cont = 0;
    linha = pegaLinha();
    coluna = pegaColuna();
     while(linha != coluna){
        system("cls");
        gotoxy(20,1);printf("A matriz deve ser quadrada para verificar se eh uma matriz de permutacao(ex: 3x3).");
        gotoxy(20,2);printf("Pressione alguma tecla para digitar novamente..");
        getch();
        linha = pegaLinha();
        coluna = pegaColuna();
    }
    int matrizResultante[i][j];
    pegaMatriz(matriz, linha, coluna, num, m);
    exibeMatriz(matriz, linha, coluna, num, m);
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
        }
    }
    cont = verificaPermutacao(matrizResultante, linha, coluna);
    /*----------------------VERIFICA MATRIZ PERMUTACAO-----------------------*/

    if(cont == linha)
        printf("Sua matriz eh uma matriz de permutacao!");
    else
        printf("Sua matriz nao eh uma matriz de permutacao!");

    /*-----------------------------------------------------------------------*/


    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuVerificacao(matriz);
    else if(tecla == 27)
        sair();
}

void matrizTransposta(int matriz[][i][j]){
    int a, b;
    char tecla;
    int linha, coluna,
    matrizResultante[i][j];
    linha = pegaLinha();
    coluna = pegaColuna();

    pegaMatriz(matriz, linha, coluna, 1, 0);
    hideCursor();
    exibeMatriz(matriz, linha, coluna, 1, 0);
    gotoxy(50,1);printf("MATRIZ TRANSPOSTA");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
        }
    }
    imprimeMatriz(matrizResultante, linha, coluna, 1);

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menu(matriz);
    else if(tecla == 27)
        sair();
}

void menuSistemaLinear(int matriz[][i][j]){
    system("cls");
	int tecla;
	int cont = 0;

	gotoxy(50,1);printf("SISTEMA LINEAR TRIANGULAR");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Resolver um sistema linear triangular inferior");
	gotoxy(10,6);printf("Resolver um sistema linear triangular superior");
	gotoxy(10,8);printf("Voltar");
	gotoxy(10,15);printf("<ESC> Sair");
	//gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();

   		if(tecla == 80 && cont<=2){ // para baixo
   			gotoxy(8,4+cont);printf("  ");
   			cont+=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 72 && cont>0){ // para cima
   			gotoxy(8,4+cont);printf("  ");
   			cont-=2;
			gotoxy(8,4+cont);printf("%c",254);
		}

		if(tecla == 13){
			switch(cont){
				case 0:
					resolverSistemaLinearInferior(matriz, 1, 0);
					break;
				case 2:
					resolverSistemaLinearSuperior(matriz, 1, 0);
					break;
				case 4:
					menu();
					break;
			}
        }
   	}

	sair();

}

int verificaInferior(float matrizResultante[][j], int linha, int coluna){
	int a, b;

	if(linha == coluna){
		for(a = 0; a < linha; a++){ // verifica se � inferior
	        for(b = 0; b < coluna; b++){
	            if(a < b && matrizResultante[a][b] != 0)
					return 0;
	        }
    	}
    	return 1;
	}else
		return 0;

}

void resolverSistemaLinearInferior(int matriz[][i][j], int num, int m){
    int a, b;
    char tecla;
    int linha, coluna, inferior = 1;
    linha = pegaLinha();
    coluna = pegaColuna();
    float matrizResultante[i][j], x[i], soma = 0;
    int bX[i];
    pegaMatriz(matriz, linha, coluna, num, m);
    system("cls");
	gotoxy(10,2);printf("Insira os valores dos termos independentes:");
    for(a = 0; a < linha; a++){
    	scanf("%d",&bX[a]);
	}
    hideCursor();
    system("cls");
    gotoxy(50,1);printf("SISTEMA LINEAR TRIANGULAR INFERIOR");

    printf("\n");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
            printf("%.f ", matrizResultante[a][b]);
        }
        printf("\n");
    }

    inferior = verificaInferior(matrizResultante, linha, coluna);

    if(inferior){
    	x[0]=(float)bX[0]/matrizResultante[0][0];
    	for(a = 0; a < linha; a++){
    		soma = 0;
    		for(b = 0; b <= (a - 1); b++){
    			soma += matrizResultante[a][b] * x[b];
			}
			x[a]=(float)(bX[a]-soma)/matrizResultante[a][a];
		}

		printf("\nOs valores de x sao: ");
		for(a = 0;a < linha; a++){
			printf("x%d = %.2f ",a+1,x[a]);
		}
	}else{
		 printf("\nSua matriz nao eh triangular inferior. Por isso, nao podemos fazer seu sistema!\n\n");
            if(linha != coluna)
                printf("Observacao: nao existe matriz triangular superior que nao seja quadrada, ex: 3x3.");
	}

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuSistemaLinear(matriz);
    else if(tecla == 27)
        sair();
}

int verificaSuperior(float matrizResultante[][j], int linha, int coluna){
	int a, b;

	if(linha == coluna){
		for(a = 0; a < linha; a++){ // verifica se � superior
	        for(b = 0; b < coluna; b++){
	            if(a > b && matrizResultante[a][b] != 0)
					return 0;
	        }
    	}
    	return 1;
	}else{
		return 0;
	}
}

void resolverSistemaLinearSuperior(int matriz[][i][j], int num, int m){
    int a, b;
    char tecla;
    int linha, coluna, superior = 1;
    linha = pegaLinha();
    coluna = pegaColuna();
    float matrizResultante[i][j], x[i], soma = 0;
    int bX[i];
    pegaMatriz(matriz, linha, coluna, num, m);
    system("cls");
	gotoxy(10,2);printf("Insira os valores dos termos independentes:");
    for(a = 0; a < linha; a++){
    	scanf("%d",&bX[a]);
	}
    hideCursor();
    system("cls");
    gotoxy(50,1);printf("SISTEMA LINEAR TRIANGULAR SUPERIOR");

    printf("\n");
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            matrizResultante[a][b] = matriz[0][a][b];
            printf("%.2f ",matrizResultante[a][b]);
        }
        printf("\n");
    }

    superior = verificaSuperior(matrizResultante, linha, coluna);

    if(superior){
    	x[linha -1]=(float)bX[linha - 1]/matrizResultante[linha - 1][linha - 1];
    	for(a = linha - 2; a >= 0; a--){
    		soma = 0;
    		for(b = a + 1; b < coluna; b++){
    			soma += matrizResultante[a][b] * x[b];
			}
			x[a] = (float)(bX[a] - soma)/matrizResultante[a][a];
		}

		printf("\nOs valores de x sao: ");
		for(a = 0;a < linha;a++){
			printf("x%d = %.2f ",a+1,x[a]);
		}
	}else{
		 printf("\nSua matriz nao eh triangular superior. Por isso, nao podemos fazer seu sistema!\n\n");
            if(linha != coluna)
                printf("Observacao: nao existe matriz triangular superior que nao seja quadrada, ex: 3x3.");
	}

    printf("\n\n\n\n\t\t\t\t<SPACE> Voltar ao menu anterior");
    printf("\n\n\t\t\t\t<ESC> Sair");

    tecla = getch();

    while(tecla != 32 && tecla !=27){
        tecla = getch();
    }
    if(tecla == 32)
        menuSistemaLinear(matriz);
    else if(tecla == 27)
        sair();
}

void sair(){
	system("cls");
	gotoxy(40,2);printf("Obrigada por utilizar nosso sistema!\n");
	exit(0); // for�a o fechamento do programa;
}

void hideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void showCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x,int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); //posiciona cursor na tela
}
