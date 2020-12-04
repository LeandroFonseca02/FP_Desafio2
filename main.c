/*
Ismat - Engenheiria Informática 1º Ano
Fundamentos de Programação - Prof. Fracisco Pereira
Leandro Fonseca
04/12/2020 - 13:27
Resumo: Programa com menus e opções com arrays
Inputs:
Outputs:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARRAY_DIMENSION 10

void resetArrays(int intArray2[ARRAY_DIMENSION], float fltArray3[ARRAY_DIMENSION])
{
    int intContador = 0;

    for (intContador = 0; intContador < 10; intContador++)
    {
        intArray2[intContador] = 0;
        fltArray3[intContador] = 0;
    }
}
void printMenu()
{
    //system("cls");
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║                       Menu                       ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("1. Escreve a media da soma do elementos do vetor1\n");
    printf("2. Escreve os elementos do vetor1 pela ordem inversa\n");
    printf("3. Escreve os elementos do vetor1, primeiro os numeros impares e depois os pares\n");
    printf("4. Preenche o vetor2 com o número 50 , coloca  no  vetor3  a  diferença  ao  quadrado  dos seus  elementos com  os  elementos  do  vetor  1. Em  seguida imprimeo vetor3.Some os valores encontrados, calcule a sua média e imprima\n");
    printf("5. Preenche os vetor2 e vetor3 com um valor qualquer à  sua  escolha  e  calcule  a  média  da  soma  dos  elementos  de cada índice e vá imprimindo por ordem de cálculo\n");
    printf("0. Sair do programa\n\n");
    printf("Escolha a opçao do menu: ");
}

int checkExit(int intArrayLocal[ARRAY_DIMENSION], float fltArrayLocal[ARRAY_DIMENSION])
{
    int intResult = 1;
    char chrOptionConfirm, chrMenuOption;

    printf("\nDeseja continuar na Opçao? (s ou n): ");
    scanf(" %c",&chrOptionConfirm);
    chrOptionConfirm = tolower(chrOptionConfirm);
    if(chrOptionConfirm == 's')
    {
        printf("Continuar na opçao\n");
        resetArrays(intArrayLocal,fltArrayLocal);
    }else if (chrOptionConfirm == 'n')
    {
        printf("Obrigado pela sua escolha, volte sempre\n");
        //system("clear");
        printMenu();
//        scanf(" %c",&chrMenuOption);
        intResult = 0;
    }
    return intResult;
}

void optionCase1(int intArrayUser2[ARRAY_DIMENSION])
{
    float fltSomaMedia = 0;
    int intCounter = 0;

    printf("Opçao 1 selecionada - Media do Vetor1\n\n");

    for (intCounter = 0; intCounter < 10; intCounter++)
    {
        fltSomaMedia += intArrayUser2[intCounter];
    }
    fltSomaMedia /= 2;
    printf("O valor da média da soma dos valores do vetor1 é %g", fltSomaMedia);
}

void optionCase2(int intArrayUser2[ARRAY_DIMENSION], int intArraySwitch[ARRAY_DIMENSION])
{
    int intLinhas = 0, intColunas = ARRAY_DIMENSION;
    printf("Opçao 2 selecionada - Imprimir Vetor1 pela ordem inversa\n\n");

    for (intLinhas, intColunas; intLinhas < ARRAY_DIMENSION; --intColunas, intLinhas++)
    {
        intArraySwitch[intLinhas] = intArrayUser2[intColunas - 1];
        printf("%d; ", intArraySwitch[intLinhas]);
    }
}

void optionCase3(int intArrayUser2[ARRAY_DIMENSION], int intArraySwitch[ARRAY_DIMENSION])
{
    int intLinhas = 0, intColunas = ARRAY_DIMENSION;
    printf("Opçao 2 selecionada - Imprimir Vetor1 pela ordem inversa\n\n");

    for (intLinhas, intColunas; intLinhas < ARRAY_DIMENSION; --intColunas, intLinhas++)
    {
        intArraySwitch[intLinhas] = intArrayUser2[intColunas - 1];
        printf("%d; ", intArraySwitch[intLinhas]);
    }
}

void main(){
    int intArrayUser[ARRAY_DIMENSION],intArray2[ARRAY_DIMENSION],intCounter,intExit,intCounter2, intOptionResult;
    float fltArray3[ARRAY_DIMENSION];
    char chrMenuOption, chrOptionConfirm;
    intExit = 1;

    printf("Preencha os valores para um array (vetor1). Apenas valores inteiros compreendidos entre 1 e 100\n");
    while(intExit != 0)
    {
        for (intCounter = 0; intCounter < 10; intCounter++)
        {
            printf("Elemento do array de index %d: ",intCounter);
            scanf("%d",&intArrayUser[intCounter]);
            if((intArrayUser[intCounter] < 1) || (intArrayUser[intCounter] > 100))
            {
                printf("Valor incorreto! \nValor nao compreendido entre 1 e 100!\n");
                //system("cls");
                break;
            }else if (intCounter == 9)
            {
                intExit = 0;
            }
        }
    }
    intExit = 1;
    printMenu(chrMenuOption);
    scanf(" %c",&chrMenuOption);

    while(intExit != 0)
    {
        switch (chrMenuOption) {
            case '0':
                printf("Opçao 0 selecionada - Sair\n");
                printf("Obrigado pela sua escolha, volte sempre");
                intExit = 0;
                break;
            case '1':
                optionCase1(intArrayUser);

                intOptionResult = checkExit(intArray2,fltArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '2':
                optionCase2(intArrayUser, intArray2);

                intOptionResult = checkExit(intArray2,fltArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '3':
                printf("Opçao 3 selecionada - Imprimir o Vetor1, mas primeiro impreme os numeros impares e so depois os pare");



                intOptionResult = checkExit(intArray2,fltArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            case '4':
                printf("Opçao 4 selecionada - Media da diferença");


                intOptionResult = checkExit(intArray2,fltArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            case '5':
                printf("Opçao 5 selecionada - ");

                intOptionResult = checkExit(intArray2,fltArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            default:
                printf("Opçao invalida!\n");
                printMenu();
                scanf(" %c",&chrMenuOption);
                break;
        }
    }

}