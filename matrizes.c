/* Trabalho de Matrizes
Bianca Dias Barbosa e Henrique Marciano da Silva BSI - 2018*/
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
void subtraiMatrizes();
void multiplicaMatrizes();
void verificaSimetria();
void verificaQuadradoMagico();
void verificaQuadradoLatino();
void verificaMatrizPermutacao();
void resolverSistemaLinearInferior();
void resolverSistemaLinearSuperior();
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

//Funções

void menu(){
	system("cls");
	int tecla;
	int cont = 0;
	int matriz[N][i][j];

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
	int a, b, c;

	for(c = 0; c < num; c++){
        gotoxy(10,2);printf("Insira os elementos da matriz (%dx%d) %d: ",linha,coluna, c + 1);
         if(m == 1 && c == 1)
        {
            if(linha > coluna)
            {
                linha--;
                coluna++;
            }
            else if(linha < coluna)
            {
                linha++;
                coluna--;
            }
        }
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
    int a, b, c;
    printf("\n\n\n");
    for(c = 0; c < num; c++){
         if(m == 1 && c == 1)
        {
            if(linha > coluna)
            {
                linha--;
                coluna++;
            }
            else if (linha < coluna)
            {
                linha++;
                coluna--;
            }
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
					multiplicaMatrizes();
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
    hideCursor();
    int a, b, aux;
    gotoxy(0,15); printf("Matriz resultante: \n");
    if(t == 1){
       aux = linha;
       linha = coluna;
       coluna = aux;
    }
    for(a = 0; a < linha; a++){
        for(b = 0; b < coluna; b++){
            printf("%3d ",matrizResultante[a][b]);
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

void multiplicaMatrizes(){
    gotoxy(50,2);printf("Funcao para multiplicar matrizes.");
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
					verificaQuadradoMagico();
					break;
				case 4:
					verificaQuadradoLatino();
					break;
				case 6:
					verificaMatrizPermutacao();
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

void verificaQuadradoMagico(){
    gotoxy(50,2);printf("Funcao que verifica se a matriz eh um quadrado magico.");
}

void verificaQuadradoLatino(){
    gotoxy(50,2);printf("Funcao que verifica se a matriz eh um quadrado latino.");
}

void verificaMatrizPermutacao(){
    gotoxy(50,2);printf("Funcao que verifica se a matriz eh uma matriz de permutacao.");
}

void matrizTransposta(int matriz[][i][j]){ //Bianca vai arrumar;
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
					resolverSistemaLinearInferior();
					break;
				case 2:
					resolverSistemaLinearSuperior();
					break;
				case 4:
					menu();
					break;
			}
        }
   	}

	sair();

}

void resolverSistemaLinearInferior(){
    gotoxy(50,2);printf("Funcao que resolve um sistema linear triangular inferior.");
}

void resolverSistemaLinearSuperior(){
    gotoxy(50,2);printf("Funcao que resolve um sistema linear triangular superior.");
}

void sair(){
	system("cls");
	gotoxy(40,2);printf("Obrigada por utilizar nosso sistema!\n");
	exit(0); //coloquei system("exit") para fechar o programa com o esc;
	//parece que o system("exit") não resolveu, e dependendo, precisa apertar de 2 a mais vezes o ESC.
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
