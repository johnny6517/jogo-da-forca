#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
using namespace std;

class regrasDeJogo{
	public:char * remove_espacos( char * out, const char * in ){
	    const char * p = in;
	    int i = 0;

		while(*p){

	        if(!isspace(*p))
	            out[i++] = *p;
	        p++;
	    }

	    out[i] = 0;
	    return out;
	}

	char ignoreCase(char letra[], char palavra[], char maiusculas[], char minusculas[]){
		int i = 0;
		for(i = 0; i < strlen(palavra); i++){
			if(isupper(letra[0]) != palavra[i]){
				maiusculas[i] = toupper(palavra[i]);
			}
			if(islower(letra[0]) != palavra[i]){
				minusculas[i] = tolower(palavra[i]);
			}
		}
		return maiusculas[i];
		return minusculas[i];
	}

	void estrelas(){
		char estrelinha = '*';
		int estrelas[12] = {100,90,80,70,60,50,40,30,20,10,5,1};
		for(int i = 0; i < 12; i++){
			for(int e = 0; e < estrelas[i]; e++){
			cout<<estrelinha;
			}
			cout<<"\n";
		}
		cout<<"\n\n";
	}

	void revelaAsDuasPalavras(char palavra[], char secreta[]){
		int i=0, j=0;
		if(strcmp(palavra,secreta) != 0 || strcmp(palavra,secreta) != 1){
			cout<<"\n......Seus acertos\n";
			for(i = 0; i < strlen(palavra); i++)
				cout<<secreta[i];
				cout<<"\n\n...Palavra Secreta\n";
			for(j = 0; j < strlen(palavra); j++)
				cout<<palavra[j];

			cout<<"\n\n";
		}
	}

	void boasvindas(){
		cout<<"======================================================\n";
		cout<<"==============Bem vindo ao jogo da Forca==============\n";
		cout<<"======================================================\n";
		cout<<"==============E aí, está preparado para jogar ?=======\n";
		cout<<"======================================================\n";
		cout<<"======================================================\n";
		cout<<"==============By João Victor - JÃO====================\n";
		cout<<"======================================================\n";
		cout<<"======================================================\n\n";
	}

	void forca(int erros){
		printf("  _______       \n");
		printf(" |/      |      \n");
		printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
		printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
		printf(" |       %c     \n", (erros>=2?'|':' '));
		printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
		printf(" |  %s          \n", (erros>=3?"EITA!": ""));
		printf("_|___           \n");
		printf("\n\n");
	}

	void vitoria(){
		cout<<"\n====================================================";
		cout<<"\n...Parabéns, você acertou todas as palavras! :D...=";
		cout<<"\n====================================================\n\n";

		cout<<"       ___________      \n";
		cout<<"      '._==_==_=_.'     \n";
		cout<<"      .-\\:      /-.    \n";
		cout<<"     | (|:.     |) |    \n";
		cout<<"      '-|:.     |-'     \n";
		cout<<"        \\::.    /      \n";
		cout<<"         '::. .'        \n";
		cout<<"           ) (          \n";
		cout<<"         _.' '._        \n";
		cout<<"        '-------'       \n\n";
	}

	void derrota(){
		cout<<"=================================================================";
		cout<<"\n...Infelizmente não foi dessa vez, melhor sorte na próxima :)...=";
		cout<<"\n=================================================================\n\n";

		cout<<"         _______________         \n";
		cout<<"        /               \\       \n";
		cout<<"       /                 \\      \n";
		cout<<"    /\\/                   \\/\\  \n";
		cout<<"    \\ \|   XXXX     XXXX   | /   \n";
		cout<<"     \\|   XXX       XXX   |/     \n";
		cout<<"      |   X           X   |      \n";
		cout<<"      |                   |      \n";
		cout<<"      \\__       X      __/     \n";
		cout<<"        |\\     XXX     /|       \n";
		cout<<"        | |           | |        \n";
		cout<<"        | I I I I I I I |        \n";
		cout<<"        |  I I I I I I  |        \n";
		cout<<"        \\_             _/       \n";
		cout<<"          \\_ ------  _/         \n";
		cout<<"            \\_______/           \n\n";
	}
};
