// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include<stdio.h>
#include<string.h>

//renomeie o arquivo do include abaixo para aluno-<MATRICULA>.c
#include "aluno1.c"

void quebrar_data (data, *dia, *mes, *ano);
void converte_data (ChDia, &dia, ChMes, &mes, ChAno, &ano);
int bissexto (ano);
int teste_data (dia, mes, ano);

void testQ1();
//void testQ2();
//void testQ3();
//void testQ4();
//void testQ5();
//void testQ6();

int main(){
    
    testQ1();
    //testQ2();
    //testQ3();
    //testQ4();
    //testQ5();
    //testQ6();
}

void testQ1(){
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
}

void quebrar_data (data, *dia, *mes, *ano){
    int i, j;

    for (i = 0; data[i] != '/'; i++)
        dia[i] = data[i];
        if (data[i + 2] == '/')
            dia[i + 2] = '\0';

    for (i++; data[i] != '/'; i++)
        mes[i] = data[i];
        if (data[i + 2] == '/')
            mes[i + 2] = '\0';

    for (i++; data[i] != '\0'; i++)
        dia[i] = data[i];
}

void converte_data (ChDia, &dia, ChMes, &mes, ChAno, &ano){
    dia = atoi (ChDia);
    ano = atoi (ChMes);
    ano = atoi (ChAno);
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
    int ab;

    ab = bissexto (ano);

    if (dia > 31 || dia < 1)
        valido = 0;

    else if (mes > 12 || mes < 1)
        valido = 0;

    else if (ab == 0 && mes == 2 && dia > 28)
        valido = 0;

    else if (ab == 0 && mes == 2 && dia > 29)
        valido = 0;

    return valido;
}


/*
void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/06/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 1);
    printf("%d\n",qtdDias == 0);
    printf("%d\n",qtdMeses == 0);
    printf("%d\n",qtdAnos == 1);
    
    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 2);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 3);
    
    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 4);
    
    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 1);
    printf("%d\n",qtdDias == 1);
    printf("%d\n",qtdMeses == 1);
    printf("%d\n",qtdAnos == 0);
    
}

void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0) == 3);
    printf("%d\n",q3(str, 'b', 0) == 0);
    printf("%d\n",q3(str, 'l', 1) == 0);
    printf("%d\n",q3(str, 'l', 0) == 1);
    printf("%d\n",q3(str, 'L', 0) == 1);
}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);
    
    
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);
    
}


void testQ5(){
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    
}
