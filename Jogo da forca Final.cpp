#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
#include<C:\Users\BOTenigma\Desktop\Códigos fonte\regrasDeJogo.cpp>
using namespace std;

main(){
	setlocale(LC_ALL,"portuguese");

	regrasDeJogo objeto;

	//declarando as variáveis necessárias
	char loop = 's';
	int vitorias = 0, derrotas = 0;

	//loop para repetir o jogo
	//loop já entra como verdadeiro, caso a resposta seja N o escopo indentificará a mesma resposta e sairá do laço
	while(loop == 's' || loop == 'Sim' || loop == 'SIM'){

		//Cada vez que o usuário perde ou vence, no final do programa é incrementado um valor
		if(vitorias != 0){
			cout<<"Quantidade de Vitórias........:  "<<vitorias<<endl;
		}if(derrotas != 0){
			cout<<"Quantidade de Derrotas........:  "<<derrotas<<"\n\n";
		}

		//declarando as variáveis necessárias
		string validando;
		char secreta[500], entrada[100], secretaM[100], secretaMi[100], palavra[100], maiusculas[100], minusculas[100], letra[1];
		char dica[500]="";
		int i=0, acerto=0, erros=0, j=0;
		bool acertos=false, teste=true;

		objeto.boasvindas();

		//introduzindo a palavra secreta

		cout<<"digite a palavra secreta: ";
		cin.get(entrada,500).ignore();
		objeto.remove_espacos(palavra,entrada);

		cout<<"Deseja escrever alguma dica da palavra secreta ? S/N: ";
		cin>>validando;

		fflush(stdin);

		if(validando == "s" || validando == "Sim" || validando == "SIM" || validando == "sim"){
			cout<<"Escreva a dica sem espaços: ";
			cin.get(dica,500);
		}

		//após introduzir a palavra secreta, o cls limpa o prompt para o jogador não Vê-la
		system("cls");

		//atribuindo os traços ao array secreta
		for(i = 0; i < strlen(palavra); i++){
			secreta[i] = '-';
			secretaM[i] = '-';
			secretaMi[i] = '-';
		}

		//enquanto chances for verdadeiro e acerto melhor que o range de palavra faça
		while(acerto < strlen(palavra) && erros < 5){
			//laço para executar todo o esquema do jogo para depois validar no final se foi repetido alguma letra
			do{
				objeto.forca(erros);

				if(strlen(dica) > 1){
					cout<<"A dica é: "<<dica<<endl;
				}
				//caso o while retorne falso, a condição irá imprimir o texto
				if(!teste ){
					cout<<"Não vale repetir a letra!";
				}

				//atribuindo verdadeiro ao booleano para caso não repita uma palavra, sair do laço
				teste = true;

				//ao reiniciar o laço os dados são atualizados com N de chances, palavra anterior e quantidade de acertos
				cout<<"\nErros: "<<erros<<endl;
				setlocale(LC_ALL,"C");
				cout<<"Palavra anterior: "<<letra[0]<<"         acertos: "<<acerto;
				cout<<"\n\n";
				
				//Caso a letra digitada for verdadeira, o laço irá atualizar o array secreta e imprimir com a letra referente
				for(i = 0; i < strlen(palavra); i++){
					setlocale(LC_ALL,"C");
					cout<<secreta[i];
				}
				setlocale(LC_ALL,"portuguese");
				//fica fixo na tela o range do array palavra e o usuário digita a letra para ser validada
				cout<<"\nA palavra secreta contém: "<<strlen(palavra)<<" letras";
				cout<<"\n\n";
				cout<<"Digite a letra: "<<endl;
				cin>>letra[0];

				//após digitados os dados, a tela é limpa e o laço reinicia com os dados autalizados
				system("cls");

				//analisa se a palavra anterior já foi digitada, caso fora, retorna um false e reinicia o do...while
				for(i = 0; i < strlen(palavra); i++){
					if(letra[0]==secreta[i] or letra[0]==secretaM[i] or letra[0]==secretaMi[i])
						teste = false;
				}
			}
			while(!teste);

			/*o laço realiza a checagem se a letra digitada é maiúscula ou minúscila, caso seja diferente do array palavra
		 	a condição irá colocar todas as letras maiúsculas ou minúsculas */
			objeto.ignoreCase(letra,palavra,maiusculas,minusculas);

			/*Caso o dado do usuário seja verdadeiro, a letra digitada será atribuida ao array secreta e sendo revelada na tela
			se toda palavra for verdadeira, o usuário incrementa acerto até o range da palavra secreta, assim saindo do while principal */
			for(i = 0; i < strlen(palavra); i++){
				if(palavra[i]==letra[0] || maiusculas[i]==letra[0] || minusculas[i]==letra[0]){
					secreta[i] = palavra[i];
					secretaM[i] = maiusculas[i];
					secretaMi[i] = minusculas[i];
					acertos=true;
					acerto++;
				}
			}

			//caso o usuário erre a letra, o laço anterior atribuirá falso e decrementará chances
			if(acertos == false){
				erros++;
			}

			/* caso o usuário acerte, se o laço reiniciar como verdadeiro, caso ele erre a próxima palavra
			não decrementará as "chances", ou seja, ele nunca errará. */
			acertos = false;
		}

		/*Saindo do laço princpial do jogo, é analizado os dois arrays de String
		caso ñao sejam iguais, irá fazer a impressão dos acertos e a palavra secreta
		caso sejam iguals ignoram e vão para o último laço */
		setlocale(LC_ALL,"C");
		objeto.revelaAsDuasPalavras(palavra,secreta);
		setlocale(LC_ALL,"portuguese");
		//laço que imprime estrelas na tela
		objeto.estrelas();

		/*se as duas strings forem iguais você ganha, se não perde
		strcmp() analisa duas strings e retorna inteiro 0 para true e 1 para false */
		if(strcmp(palavra,secreta) != 1){
			objeto.vitoria();
			vitorias++;
		}else{
			objeto.derrota();
			derrotas++;
			}

		cout<<"Deseja jogar novamente ? S/N: ";
		cin>>loop;
		fflush(stdin);

		system("cls");
	}
	cout<<"Fim do jogo."<<endl;

	if(vitorias != 0)
		cout<<"Suas vitorias foram.......: "<<vitorias<<endl;
	if(derrotas == 0){
		cout<<"Parabéns, você permaneceu invicto! :D"<<endl;
		objeto.vitoria();
	}
	if(derrotas != 0 )
		cout<<"Suas derrotas foram.......: "<<derrotas<<"\n\n";

	system("pause");
}
