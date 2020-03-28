#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
#include<C:\Users\BOTenigma\Desktop\C�digos fonte\regrasDeJogo.cpp>
using namespace std;

main(){
	setlocale(LC_ALL,"portuguese");

	regrasDeJogo objeto;

	//declarando as vari�veis necess�rias
	char loop = 's';
	int vitorias = 0, derrotas = 0;

	//loop para repetir o jogo
	//loop j� entra como verdadeiro, caso a resposta seja N o escopo indentificar� a mesma resposta e sair� do la�o
	while(loop == 's' || loop == 'Sim' || loop == 'SIM'){

		//Cada vez que o usu�rio perde ou vence, no final do programa � incrementado um valor
		if(vitorias != 0){
			cout<<"Quantidade de Vit�rias........:  "<<vitorias<<endl;
		}if(derrotas != 0){
			cout<<"Quantidade de Derrotas........:  "<<derrotas<<"\n\n";
		}

		//declarando as vari�veis necess�rias
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
			cout<<"Escreva a dica sem espa�os: ";
			cin.get(dica,500);
		}

		//ap�s introduzir a palavra secreta, o cls limpa o prompt para o jogador n�o V�-la
		system("cls");

		//atribuindo os tra�os ao array secreta
		for(i = 0; i < strlen(palavra); i++){
			secreta[i] = '-';
			secretaM[i] = '-';
			secretaMi[i] = '-';
		}

		//enquanto chances for verdadeiro e acerto melhor que o range de palavra fa�a
		while(acerto < strlen(palavra) && erros < 5){
			//la�o para executar todo o esquema do jogo para depois validar no final se foi repetido alguma letra
			do{
				objeto.forca(erros);

				if(strlen(dica) > 1){
					cout<<"A dica �: "<<dica<<endl;
				}
				//caso o while retorne falso, a condi��o ir� imprimir o texto
				if(!teste ){
					cout<<"N�o vale repetir a letra!";
				}

				//atribuindo verdadeiro ao booleano para caso n�o repita uma palavra, sair do la�o
				teste = true;

				//ao reiniciar o la�o os dados s�o atualizados com N de chances, palavra anterior e quantidade de acertos
				cout<<"\nErros: "<<erros<<endl;
				setlocale(LC_ALL,"C");
				cout<<"Palavra anterior: "<<letra[0]<<"         acertos: "<<acerto;
				cout<<"\n\n";
				
				//Caso a letra digitada for verdadeira, o la�o ir� atualizar o array secreta e imprimir com a letra referente
				for(i = 0; i < strlen(palavra); i++){
					setlocale(LC_ALL,"C");
					cout<<secreta[i];
				}
				setlocale(LC_ALL,"portuguese");
				//fica fixo na tela o range do array palavra e o usu�rio digita a letra para ser validada
				cout<<"\nA palavra secreta cont�m: "<<strlen(palavra)<<" letras";
				cout<<"\n\n";
				cout<<"Digite a letra: "<<endl;
				cin>>letra[0];

				//ap�s digitados os dados, a tela � limpa e o la�o reinicia com os dados autalizados
				system("cls");

				//analisa se a palavra anterior j� foi digitada, caso fora, retorna um false e reinicia o do...while
				for(i = 0; i < strlen(palavra); i++){
					if(letra[0]==secreta[i] or letra[0]==secretaM[i] or letra[0]==secretaMi[i])
						teste = false;
				}
			}
			while(!teste);

			/*o la�o realiza a checagem se a letra digitada � mai�scula ou min�scila, caso seja diferente do array palavra
		 	a condi��o ir� colocar todas as letras mai�sculas ou min�sculas */
			objeto.ignoreCase(letra,palavra,maiusculas,minusculas);

			/*Caso o dado do usu�rio seja verdadeiro, a letra digitada ser� atribuida ao array secreta e sendo revelada na tela
			se toda palavra for verdadeira, o usu�rio incrementa acerto at� o range da palavra secreta, assim saindo do while principal */
			for(i = 0; i < strlen(palavra); i++){
				if(palavra[i]==letra[0] || maiusculas[i]==letra[0] || minusculas[i]==letra[0]){
					secreta[i] = palavra[i];
					secretaM[i] = maiusculas[i];
					secretaMi[i] = minusculas[i];
					acertos=true;
					acerto++;
				}
			}

			//caso o usu�rio erre a letra, o la�o anterior atribuir� falso e decrementar� chances
			if(acertos == false){
				erros++;
			}

			/* caso o usu�rio acerte, se o la�o reiniciar como verdadeiro, caso ele erre a pr�xima palavra
			n�o decrementar� as "chances", ou seja, ele nunca errar�. */
			acertos = false;
		}

		/*Saindo do la�o princpial do jogo, � analizado os dois arrays de String
		caso �ao sejam iguais, ir� fazer a impress�o dos acertos e a palavra secreta
		caso sejam iguals ignoram e v�o para o �ltimo la�o */
		setlocale(LC_ALL,"C");
		objeto.revelaAsDuasPalavras(palavra,secreta);
		setlocale(LC_ALL,"portuguese");
		//la�o que imprime estrelas na tela
		objeto.estrelas();

		/*se as duas strings forem iguais voc� ganha, se n�o perde
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
		cout<<"Parab�ns, voc� permaneceu invicto! :D"<<endl;
		objeto.vitoria();
	}
	if(derrotas != 0 )
		cout<<"Suas derrotas foram.......: "<<derrotas<<"\n\n";

	system("pause");
}
