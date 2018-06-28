/* Trabalho de Matrizes
Bianca Dias Barbosa e Henrique Marciano da Silva BSI - 2018*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define i 10
#define j 10

int pegaLinha();
int pegaColuna();
void pegaMatriz(int matriz[][j], int linha, int coluna);
void somaMatrizes(); //soma, subtrai, multiplica, verificacoes e sistemas devem ser int né?
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
void menuOperacoes(int matriz[][j]);
void menuVerificacao(int matriz[][j]);
void matrizTransposta(int matriz[][j]);
void menuSistemaLinear(int matriz[][j]);
void menu ();
void sair ();
void hideCursor();
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
	int matriz[i][j];

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
    system("cls");
    int coluna;
    gotoxy(30,1);printf("Digite um valor para a coluna da matriz: (linha x coluna) (MAX 10)");
    scanf("%d",&coluna);
    return coluna;
}

int pegaLinha(){
    system("cls");
    int linha;
    gotoxy(30,1);printf("Digite um valor para a linha da matriz: (linha x coluna) (MAX 10) ");
    scanf("%d",&linha);
    return linha;
}

void pegaMatriz(int matriz[][j], int linha, int coluna){
	system("cls");
	int a, b;
	gotoxy(50,1);printf("Insira os elementos da matriz 1: ");
	for(a=0;a<linha;a++){
		for(b=0;b<coluna;b++){
			scanf("%d",&matriz[a][b]);
		}
	}
}

void exibeMatriz(int matriz[][j], int linha, int coluna){
    system("cls");
    int a,b;
    for(a=0;a<linha;a++){
        for(b=0;b<coluna;b++)
            printf("%3d",matriz[a][b]);
        putchar('\n');
    }
}

void menuOperacoes(int matriz[][j]){// definir valor MAXIMO da matriz, mas o usuario informa o tamanho dela.
    int linha, coluna, tecla,
    cont = 0;
	linha = pegaLinha();
	coluna = pegaColuna();
	pegaMatriz(matriz, linha, coluna); //Pega a matriz digitada; hideCursor ta escondendo o cursor quando digita os valores.
	exibeMatriz(matriz, linha, coluna); //Exibe a matriz digitada;
	gotoxy(50,1);printf("Aperte qualquer tecla para ir ao menu operacoes");
	getch();
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
					somaMatrizes();
					break;
				case 2:
					subtraiMatrizes();
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

void somaMatrizes(){
    gotoxy(50,2);printf("Funcao para somar matrizes.");
}

void subtraiMatrizes(){
    gotoxy(50,2);printf("Funcao para subtrair matrizes.");
}

void multiplicaMatrizes(){
    gotoxy(50,2);printf("Funcao para multiplicar matrizes.");
}

void menuVerificacao(int matriz[][j]){
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
					verificaSimetria();
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

	sair();

}

void verificaSimetria(){
    gotoxy(50,2);printf("Funcao que verifica simetria da matriz.");
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

void matrizTransposta(int matriz[][j]){
    int linha, coluna, tecla,
    a, b;
	linha = pegaLinha();
	coluna = pegaColuna();
	pegaMatriz(matriz, linha, coluna); //Pega a matriz digitada; hideCursor ta escondendo o cursor quando digita os valores.
	//como continuar a partir daqui? pq n pode imprimir valor na matriz...
}

void menuSistemaLinear(int matriz[][j]){
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
	gotoxy(40,2);printf("Obrigada por utilizar nosso sistema!");
	gotoxy(40,3);printf("Aperte ESC novamente para finalizar o programa.\n\n");
	system("exit"); //coloquei system("exit") para fechar o programa com o esc;
	//parece que o system("exit") não resolveu, e dependendo, precisa apertar de 2 a mais vezes o ESC.
}

void hideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x,int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); //posiciona cursor na tela
}
