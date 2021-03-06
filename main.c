/*
Ismat - Engenheria Informática 1º Ano
Fundamentos de Programação - Prof. Francisco Pereira
Leandro Fonseca
07/12/2020 - 17:47
Resumo: Programa com menus e opções com arrays
Inputs:
Outputs:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

//Define do tamanho dos arrays
#define ARRAY_DIMENSION 10

//Define dos Textos do printMenu()
#define TEXT_MENU_LINE1 "|--------------------------------------------------|\n"
#define TEXT_MENU_LINE2 "|                       Menu                       |\n"
#define TEXT_MENU_LINE3 "|__________________________________________________|\n"
#define TEXT_MENU_LINE4 "1. Escreve a média da soma do elementos do vetor1\n"
#define TEXT_MENU_LINE5 "2. Escreve os elementos do vetor1 pela ordem inversa\n"
#define TEXT_MENU_LINE6 "3. Escreve os elementos do vetor1, primeiro os numeros ímpares e depois os pares\n"
#define TEXT_MENU_LINE7 "4. Preenche o vetor2 com o numero 50 , coloca  no  vetor3  a  diferença  ao  quadrado  dos seus  elementos com  os  elementos  do  vetor  1. Em  seguida imprime-o vetor3.Some os valores encontrados, calcule a sua média e imprima\n"
#define TEXT_MENU_LINE8 "5. Preenche os vetor2 e vetor3 com um random  e  calcule  a  média  da  soma  dos  elementos  de cada indice e va imprimindo por ordem de calculo\n"
#define TEXT_MENU_LINE9 "0. Sair do programa\n\n"
#define TEXT_MENU_LINE10 "Escolha a opção do menu: "

//Define dos Textos para proceguir options
#define TEXT_CONTINUE_MENU_OPTION "\nDeseja continuar na Opção? (s ou n): "
#define TEXT_CONTINUE_OPTION "Continuar na opção\n"
#define TEXT_EXIT_OPTION "Obrigado pela sua escolha, volte sempre\n"
#define TEXT_INVALID_OPTION "Opção invalida!\n"

//Define dos Textos da entrada de valores do array
#define TEXT_FIRSTARRAY_INPUT "Preencha os valores para um array (vetor1). Apenas valores inteiros compreendidos entre 1 e 100\n"
#define TEXT_ARRAY_INDEX_VALUE "Elemento do array de index %d: "
#define TEXT_INVALID_VALUE "Valor incorreto! \nValor nao compreendido entre 1 e 100!\n"

//Define dos Textos das Opçoes Selecionadas e Resultados
#define TEXT_OPTION0 "Opção 0 selecionada - Sair\n"
#define TEXT_OPTION1 "Opção 1 selecionada - Média do Vetor1\n\n"
#define TEXT_OPTION1_RESULT "O valor da média da soma dos valores do vetor1 é %g"
#define TEXT_OPTION2 "Opção 2 selecionada - Imprimir Vetor1 pela ordem inversa\n\n"
#define TEXT_OPTION3 "Opção 3 selecionada - Imprimir o Vetor1, mas primeiro imprime os números impares e so depois os pares \n"
#define TEXT_PRINT_INT_RESULT "%d; "
#define TEXT_OPTION4 "Opção 4 selecionada - Média da diferença\n"
#define TEXT_OPTION4_RESULT "\nMédia de elementos do vetor3: %g"
#define TEXT_OPTION5 "Opção 5 selecionada - Média de elementos de valor randomico\n"

int checkArrayValueZero(int intArray[ARRAY_DIMENSION])
{
    int intContador, intFlag = 0;
    for(intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        if(intArray[intContador] != 0){
            intFlag = 1;
        }
    }
    return intFlag;
}

int resetArrays(int intArray2[ARRAY_DIMENSION], int intArray3[ARRAY_DIMENSION])
{
    int intContador, intResultOK, intResultCheck;

    //Percorre array em toda a sua dimensao
    for (intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Igual todos os elementos do array a 0
        intArray2[intContador] = 0;
        intArray3[intContador] = 0;
    }

    intResultCheck = checkArrayValueZero(intArray2);

    //Verificar se o array2  foi resetado
    if(intResultCheck != 1){
        intResultOK = 0;
    }else{
        //Primeiro array OK; Verificar segundo
        intResultCheck = checkArrayValueZero(intArray3);
        if(intResultCheck != 1){
            intResultOK = 0;
        }else{
            //Ambos OK; Resultado OK
            intResultOK = 1;
        }
    }

    return intResultOK;
}

void printMenu()
{
    //system("cls");
    printf(TEXT_MENU_LINE1);
    printf(TEXT_MENU_LINE2);
    printf(TEXT_MENU_LINE3);
    printf(TEXT_MENU_LINE4);
    printf(TEXT_MENU_LINE5);
    printf(TEXT_MENU_LINE6);
    printf(TEXT_MENU_LINE7);
    printf(TEXT_MENU_LINE8);
    printf(TEXT_MENU_LINE9);
    printf(TEXT_MENU_LINE10);
}

int checkExit(int intArrayLocal[ARRAY_DIMENSION], int intArrayLocal2[ARRAY_DIMENSION])
{
    int intResult = 1;
    char chrOptionConfirm;

    printf(TEXT_CONTINUE_MENU_OPTION);
    scanf(" %c",&chrOptionConfirm);
    chrOptionConfirm = tolower(chrOptionConfirm);

    //Verificar a opçao escolhida

    if((chrOptionConfirm == 110) || (chrOptionConfirm == 115))
    {
        if(chrOptionConfirm == 's')
        {
            //Caso seja 's', da reset arrays e continua
            printf(TEXT_CONTINUE_OPTION);
            resetArrays(intArrayLocal,intArrayLocal2);
        }else if (chrOptionConfirm == 'n')
        {
            //Caso seja 'n' da print do menu e passa a flag a 0
            printf(TEXT_EXIT_OPTION);
            printMenu();
            intResult = 0;
        }
    }else
    {
        //Caso nao seja s/n Erro e segue para menu
        printf(TEXT_INVALID_OPTION);
        printMenu();
        intResult = 0;
    }

    return intResult;
}

float getArrayMedia(int intArray[ARRAY_DIMENSION])
{
    float fltValueReturn = 0;
    int intCounter;
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
    int intCounter;
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
    int intContador, intArrayTemp[ARRAY_DIMENSION] = {50,50,50,50,50,50,50,50,50,50};

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
    setlocale(LC_ALL, "Portuguese");
    int *arrayPointerAdress;
    int intArrayUser[ARRAY_DIMENSION],intArray2[ARRAY_DIMENSION],intCounter,intExit, intOptionResult;
    int intArray3[ARRAY_DIMENSION];
    char chrMenuOption;
    intExit = 1;

    printf(TEXT_FIRSTARRAY_INPUT);
    while(intExit != 0)
    {
        //Percorre o array em toda a sua dimensao
        for (intCounter = 0; intCounter < 10; intCounter++)
        {
            printf(TEXT_ARRAY_INDEX_VALUE,intCounter);
            scanf("%d",&intArrayUser[intCounter]);
            //Verificar o valor dos elementos
            if((intArrayUser[intCounter] < 1) || (intArrayUser[intCounter] > 100))
            {
                printf(TEXT_INVALID_VALUE);
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
                printf(TEXT_OPTION0);
                printf(TEXT_EXIT_OPTION);
                intExit = 0;
                break;
            case '1':
                printf(TEXT_OPTION1);
                float fltMediaArrayCase1;
                fltMediaArrayCase1 = optionCase1(intArrayUser);

                printf(TEXT_OPTION1_RESULT, fltMediaArrayCase1);
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
                printf(TEXT_OPTION2);
                arrayPointerAdress = optionCase2(intArrayUser);

                for (intCounter = 0; intCounter < 10; intCounter++) {
                    printf(TEXT_PRINT_INT_RESULT, arrayPointerAdress[intCounter]);
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
                printf(TEXT_OPTION3);
                arrayPointerAdress = optionCase3(intArrayUser);

                for (intCounter = 0; intCounter < 10; intCounter++) {
                    printf(TEXT_PRINT_INT_RESULT, arrayPointerAdress[intCounter]);
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
                printf(TEXT_OPTION4);

                arrayPointerAdress = optionCase4(intArrayUser);

                for (intCounter = 0; intCounter < 10; intCounter++) {
                    printf(TEXT_PRINT_INT_RESULT, arrayPointerAdress[intCounter]);
                }

                float fltSomaMedia;
                fltSomaMedia = getArrayMedia(arrayPointerAdress);
                printf(TEXT_OPTION4_RESULT, fltSomaMedia);

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
                printf(TEXT_OPTION5);
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
                printf(TEXT_INVALID_OPTION);
                printMenu();
                scanf(" %c",&chrMenuOption);
                break;
        }
    }

}