/*
Alisson Martins Orsini

O objetivo do progama é pegar do usuario uma expressao infixa e transforma-la em posfixa:

A entrada de dados devera ser feita por um usuario perfeito. por exemplo. sem espaços e somente com sinais de +,-,* e /
o progama aceita expressoes com numeros de '0' a '9' e letras de 'a' a 'z' e letras de 'A' a 'Z'

como resultado o progama tem a transformacao da expressao infixa em posfixa

*/


//Bibliotecas necessárias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>
using namespace std;

int prioridade_sinal(char expressao) // essa funcao mostra a prioridade dos sinais
{
    if(expressao == '(')
        return 1;
    else if (expressao == '+' || expressao == '-')
        return 2;
    else if (expressao == '/' || expressao == '*')
        return 3;

    else
        return -1;
}
//Função principal para demonstrar o uso da Pilha
int main()
{
    Pilha_Construtor();  //para iniciar a Pilha

    printf("Progama que transforma expressao infixa em posfixa");
    char expressao[100]; // variavel que o pega do usuario a expressao que alimenta a pilha e o vetor de saida

    string posfixa;// vetor para saida de dados

    char topo; // variavel que retorna o topo da pilha

    printf("\n\nDigite a expressao para empilhar: \n\n ");

    gets(expressao) ; // pega a expressao do informada pelo usuario

    for (int i = 0; i < strlen(expressao); i++ ) // for roda do tamanho da expressao para varrer e saber onde
    {                                             //esta o indice que sera comparado nas condicoes
        if ((expressao[i] >= '0' && expressao[i] <='9') || // compara se o caracter que esta no indice esta entre 0 e 9
            (expressao[i] >= 'a' && expressao[i] <='z') || // compara se o caracter que esta no indice esta entre a e z
            (expressao[i] >= 'A' && expressao[i] <='Z')){  // compara se o caracter que esta no indice esta entre A e Z
                posfixa = posfixa + expressao[i];          // se estiver o caracter vai direto para a string posfixa

            cout << "vetor de saida ->  "<< posfixa << "\n";
        }
                                                            //se nao for um caracter dentro dos testes acima
                                                            // vai ser algum sinal binario
        else if(expressao[i] ==  '(' )                      // testa o caractere do indice comparando com um '('
            Pilha_Empilhar(expressao[i]);                   // se for ele empilha
                                                            //============
        else if(expressao[i] == ')'){                       //testa se é um ')'
            Pilha_Topo(topo);                               // se for, chama a pilha topo passando o topo, na volta da funcao
            while ( topo != '(' ){                          // o topo é usado para rodar o while
                posfixa = posfixa + topo;                   // e fazer o vetor de saida ser incrementado com o sinal da
                Pilha_Desempilhar(topo);                    // pilha
                Pilha_Topo(topo);                           // a ordem tem que ser essa se nao o progama bulga em alguma
            }                                               // vezes
            Pilha_Desempilhar(topo);                        //depois de rodar o while o topo da pilha precisa ser desempilhado
        }                                                   //


        else{

            Pilha_Topo(topo);
            while( !Pilha_Vazia() &&
                prioridade_sinal(expressao[i]) <= prioridade_sinal(topo))// pega oque esta no topo da pilha e compara com o valor que foi inserido pelo usuario
            {                                                            //se o primeiro valor for maior ele é empilhado fora do while
                Pilha_Desempilhar(topo);                                 //se ele for menor ele entra no while e o topo vai pra expressao de saida
                posfixa = posfixa + topo;                                // porque é feita uma chamada de pilha_desempilhar e passa o topo
            }                                                            // apos desempilhar e ser adiconado no vetor de saida
                                                                        // o indice que esta na expressao[i] é empilhado
            Pilha_Empilhar(expressao[i]);

        }


    }
    while (!Pilha_Vazia()) {            // while roda enquando a pilha nao tiver vazia
        Pilha_Topo(topo);               // é chamada a funcao topo passando topo para saber qual é o topo
        posfixa = posfixa + topo;       //  o topo é adicionado no vetor de saida
        Pilha_Desempilhar(topo);        // é desempilhado o topo
    }                                   // a funcao roda ate a pilha estiver vazia

    cout  << "\nExpressao digitada pelo usuario->  " << expressao;
    cout << "\nExpressao posfixa ->  " << posfixa;
    cout << "\n\n\n" ;

    return 0;

}
