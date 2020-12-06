/*
Ismat - Engenheria Informática 1º Ano
Fundamentos de Programação - Prof. Francisco Pereira
Leandro Fonseca
04/12/2020 - 13:27
Resumo: Programa com menus e opções com arrays
Inputs:
Outputs:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


#define ARRAY_DIMENSION 10

void resetArrays(int intArray2[ARRAY_DIMENSION], int intArray3[ARRAY_DIMENSION])
{
    int intContador;

    //Percorre array em toda a sua dimensao
    for (intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Igual todos os elementos do array a 0
        intArray2[intContador] = 0;
        intArray3[intContador] = 0;
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

int checkExit(int intArrayLocal[ARRAY_DIMENSION], int intArrayLocal2[ARRAY_DIMENSION])
{
    int intResult = 1;
    char chrOptionConfirm;

    printf("\nDeseja continuar na Opçao? (s ou n): ");
    scanf(" %c",&chrOptionConfirm);
    chrOptionConfirm = tolower(chrOptionConfirm);

    //Verificar a opçao escolhida
    if(chrOptionConfirm == 's')
    {
        //Caso seja 's', da reset arrayse continua
        printf("Continuar na opçao\n");
        resetArrays(intArrayLocal,intArrayLocal2);
    }else if (chrOptionConfirm == 'n')
    {
        //Caso seja 'n' da print do menu e passa a flag a 0
        printf("Obrigado pela sua escolha, volte sempre\n");
        //system("clear");
        printMenu();
        intResult = 0;
    }
    return intResult;
}

float getArrayMedia(int intArray[ARRAY_DIMENSION])
{
    float fltValueReturn = 0;
    int intCounter = 0;
    //Percorre o array em toda a sua dimensao
    for (intCounter = 0; intCounter < 10; intCounter++)
    {
        //Somatorio dos elementos
        fltValueReturn += intArray[intCounter];
    }
    return fltValueReturn /= 10;
}

void get2ArrayMedia(int intArray1[ARRAY_DIMENSION], int intArray2[ARRAY_DIMENSION])
{
    int intCounter = 0;
    //Percorre o array em toda sua dimensao
    for (intCounter = 0; intCounter < 10; intCounter++)
    {
        //Somatorio dos elementos
        printf("%g; ",(float)(intArray1[intCounter] + intArray2[intCounter])/2.0);
    }
}

float optionCase1(int intArrayUser2[ARRAY_DIMENSION])
{
    float fltSomaMedia;
    //Usar funçao para calcular média
    fltSomaMedia = getArrayMedia(intArrayUser2);

    return fltSomaMedia;
}

void *optionCase2(int intArrayUser2[ARRAY_DIMENSION])
{
    int intLinhas = 0, intColunas = ARRAY_DIMENSION;
    static int intArraySwitch[ARRAY_DIMENSION];

    //Percorre o array em linhas e colunas
    for (intLinhas, intColunas; intLinhas < ARRAY_DIMENSION; --intColunas, intLinhas++)
    {
        //Passar os elementos em ordem inversa
        intArraySwitch[intLinhas] = intArrayUser2[intColunas - 1];
    }
    //Retornar pointer do array
    return intArraySwitch;
}

int *optionCase3(int intArrayData[ARRAY_DIMENSION])
{
    static int intArrayMerged[ARRAY_DIMENSION] = {0};
    int intContador = 0, intArrayTemp[ARRAY_DIMENSION] = {0},intOrder = 0;

    //Percorrer o array original em toda a sua dimensao
    for (intContador; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Identificar se o valor do array é par ou impar
        if(intArrayData[intContador] % 2 != 0)
        {
            //Impar guarda em array final
            intArrayMerged[intOrder] = intArrayData[intContador];
            intOrder++;
        }else
        {
            //Par guarda em array temporario
            intArrayTemp[intContador] = intArrayData[intContador];
        }

    }

    //Percorrer o array temporario em toda a sua dimensao
    for(intContador=0; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Validar valor de array temporario
        if(intArrayTemp[intContador] != 0)
        {
            //Passar elementos do array temporario para o final
            intArrayMerged[intOrder] = intArrayTemp[intContador];
            intOrder++;
        }
    }
    //Retornar pointer do array
    return intArrayMerged;
}

int *optionCase4(int intArrayData[ARRAY_DIMENSION])
{
    static int intArrayMerged[ARRAY_DIMENSION] = {0};
    int intContador = 0, intArrayTemp[ARRAY_DIMENSION] = {50,50,50,50,50,50,50,50,50,50};

    //Percorrer o array original em toda a sua dimensao
    for (intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Passar diferença ao quadrado para array final
        intArrayMerged[intContador]=(intArrayTemp[intContador] - intArrayData[intContador])*(intArrayTemp[intContador] - intArrayData[intContador]);
    }
    //Retornar pointer do array
    return intArrayMerged;
}

void optionCase5()
{
    int intArrayVetor2[ARRAY_DIMENSION] = {0}, intArrayVetor3[ARRAY_DIMENSION] = {0};
    srand(time(NULL));

    //Percorrer os arrays nas suas dimensoes
    for(int i = 0; i < ARRAY_DIMENSION; i++){
        //Atribuir valores random de 1 a 100 aos elementos do array
        intArrayVetor2[i] = rand() % 100 + 1;
        intArrayVetor3[i] = rand() % 100 + 1;
    }
    //Usar funçao para calcular media de cada elemento do array
    get2ArrayMedia(intArrayVetor2, intArrayVetor3);
}

void main(){
    int intArrayUser[ARRAY_DIMENSION],intArray2[ARRAY_DIMENSION],intCounter,intExit, intOptionResult;
    int intArray3[ARRAY_DIMENSION];
    char chrMenuOption;
    intExit = 1;

    printf("Preencha os valores para um array (vetor1). Apenas valores inteiros compreendidos entre 1 e 100\n");
    while(intExit != 0)
    {
        //Percorre o array em toda a sua dimensao
        for (intCounter = 0; intCounter < 10; intCounter++)
        {
            printf("Elemento do array de index %d: ",intCounter);
            scanf("%d",&intArrayUser[intCounter]);
            //Verificar o valor dos elementos
            if((intArrayUser[intCounter] < 1) || (intArrayUser[intCounter] > 100))
            {
                printf("Valor incorreto! \nValor nao compreendido entre 1 e 100!\n");
                //system("cls");
                break;
            }else if (intCounter == 9)
            {
                //Mudar flag para sair do loop
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
                printf("Opçao 1 selecionada - Media do Vetor1\n\n");
                float fltMediaArrayCase1;
                fltMediaArrayCase1 = optionCase1(intArrayUser);

                printf("O valor da média da soma dos valores do vetor1 é %g", fltMediaArrayCase1);
                intOptionResult = checkExit(intArray2,intArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '2':
                printf("Opçao 2 selecionada - Imprimir Vetor1 pela ordem inversa\n\n");
                int *pArrayInverso;
                pArrayInverso = optionCase2(intArrayUser);

                for (int i = 0; i < 10; i++) {
                    printf("%d; ", pArrayInverso[i]);
                }

                intOptionResult = checkExit(intArray2,intArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '3':
                printf("Opçao 3 selecionada - Imprimir o Vetor1, mas primeiro impreme os numeros impares e so depois os pares \n");
                int *pArrayOddEven;
                pArrayOddEven = optionCase3(intArrayUser);

                for (int i = 0; i < 10; i++) {
                    printf("%d; ", pArrayOddEven[i]);
                }
                intOptionResult = checkExit(intArray2,intArray3);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            case '4':
                printf("Opçao 4 selecionada - Media da diferença\n");
                int *pArrayMediaDiferenca;

                pArrayMediaDiferenca = optionCase4(intArrayUser);

                for (int i = 0; i < 10; i++) {
                    printf("%d; ", pArrayMediaDiferenca[i]);
                }

                float fltSomaMedia = 0;
                fltSomaMedia = getArrayMedia(pArrayMediaDiferenca);
                printf("\nMedia de elementos do vetor3: %g", fltSomaMedia);

                intOptionResult = checkExit(intArray2,intArray3);

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
                optionCase5();

                intOptionResult = checkExit(intArray2,intArray3);

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