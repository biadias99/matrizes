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
	
}

int pegaLinha(){
	
}

void pegaMatriz(int matriz[][j], int linha, int coluna){
	system("cls");
	int a, b;
	gotoxy(50,1);printf("Insira os elementos da matriz 1:");
	for(a=0;a<i;a++){
		for(b=0;b<j;b++){
			scanf("%d",&matriz[a][b]);
		}
	}
}

void menuOperacoes(int matriz[][j]){
	int linha, int coluna;
	linha = pegaLinha();
	coluna = pegaColuna(); // verificar com Andrea 
	pegaMatriz(matriz);
	printf("\nOPERACOES");
}

void menuVerificacao(int matriz[][j]){
	printf("\nVERIFICACOES");
}

void matrizTransposta(int matriz[][j]){
	printf("\nTRANSPOSTA");	
}

void menuSistemaLinear(int matriz[][j]){
	printf("\nSISTEMA LINEAR TRIANGULAR");
}

void sair(){
	system("cls");
	gotoxy(40,2);printf("Obrigada por utilizar nosso sistema!\n\n");
}

void hideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x,int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); //posiciona cursor na tela
}
