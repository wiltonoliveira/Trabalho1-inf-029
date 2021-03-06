// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Wilton Silva Oliveira Júnior
//  email: oliveirajrwilton@gmail.com
//  Matrícula: 2016116055
//  Semestre: 2nd Semestre

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int datavalida = 1;
    
    char Cdia[3], Cmes[3], Cano[11];
    int iDia, iMes, iAno;
    int bissex;

    quebrar_data (data, &Cdia, &Cmes, &Cano);
    converte_data (Cdia, &iDia, Cmes, &iMes, Cano, &iAno);
    bissex = bissexto (iAno);
    datavalida = teste_data (iDia, iMes, iAno, bissex);
    
    
    if (datavalida)
        return 1;
    else
        return 0;
    
}


void quebrar_data (char date[], char *dia[], char *mes[], char *ano[]){
    int i, j;

    for (i = 0; date[i] != '/'; i++)
       *dia[i] = date[i];
        if (date[i + 2] == '/')
            *dia[i + 2] = '\0';

    for (i++; date[i] != '/'; i++)
        *mes[i] = date[i];
        if (date[i + 2] == '/')
            *mes[i + 2] = '\0';

    for (i++; date[i] != '\0'; i++)
        *dia[i] = date[i];
}

void converte_data (char ChDia, int *dia, char ChMes, int *mes, char ChAno, int *ano){
    *dia = atoi (ChDia);
    *mes = atoi (ChMes);
    *ano = atoi (ChAno);
}

int bissexto (ano){
    int resultado;

    if ((ano % 4) == 0)
        resultado = 1;
    
    else if ((ano % 100) == 0)
        resultado = 0;

    else if ((ano % 400) == 0)
        resultado = 1;

    return resultado;
}


int teste_data (dia, mes, ano, bissexto){
    int valido = 1;

    if (dia > 31 || dia < 1)
        valido = 0;

    else if (mes > 12 || mes < 1)
        valido = 0;

    else if (bissexto == 0 && mes == 2 && dia > 28)
        valido = 0;

    else if (bissexto == 1 && mes == 2 && dia > 29)
        valido = 0;

    return valido;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial < datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    *qtdDias = 10;
    *qtdAnos = 20;
    *qtdMeses = 30;
    
    //printf("%s\n", datainicial);
    //printf("%s\n", datafinal);
    
    return 1;
    
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0. 
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;
    
    qtdOcorrencias++;
    int i;

    for (i = 0; texto[i] != '\0'; i++){
    	if (texto[i] == c || texto[i] == (c - 32) || texto[i] == (c + 32)){
    		qtdOcorrencias++;
    	}
    }

    return qtdOcorrencias;
    
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = -1;
    
    return qtdOcorrencias;
    
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

	int N = 4;
	int x = 1;
	int i, j, cont = 0;
	int vet[N];
	int atual, invertido = 0;

	for (i = 0; i < N; i++)
		vet[i] = -1;

	for (i = 0; i < N; i++){
		vet[i] = (num % 10);
		num = num / 10;
		cont++;
	}

	for (j = 1; j < cont; j++){
		if (cont == 1){
			break;
		}

		x = (x * 10);
	}

	for (i = 0; i < N; i++){
		x = (x / 10);
		atual = (vet[i] * x);
		invertido = invertido + atual;
	}



    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    return qtdOcorrencias;
}