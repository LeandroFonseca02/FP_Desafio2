/*
Ismat - Engenheiria Informática 1º Ano
Fundamentos de Programação - Prof. Fracisco Pereira
Leandro Fonseca
30/11/2020 - 18:38
Resumo: Programa com menus e opções com arrays
Inputs:
Outputs:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void resetArrays(int intCounter, int intArray2[], float fltArray3[])
{
    for (intCounter = 0; intCounter < 10; intCounter++)
    {
        intArray2[intCounter] = 0;
        fltArray3[intCounter] = 0;
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

void main(){
    int intArrayUser[10],intArray2[10],intCounter,intExit,intCounter2;
    float fltArray3[10], fltSomaMedia;
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
                printf("Opçao 1 selecionada - Media do Vetor1\n\n");
                fltSomaMedia = 0;

                for (intCounter = 0; intCounter < 10; intCounter++)
                {
                    fltSomaMedia += intArrayUser[intCounter];
                }
                fltSomaMedia /= 2;
                printf("O valor da média da soma dos valores do vetor1 é %g\n", fltSomaMedia);

                printf("Deseja continuar na Opçao 1? (s ou n): ");
                scanf(" %c",&chrOptionConfirm);
                chrOptionConfirm = tolower(chrOptionConfirm);
                if(chrOptionConfirm == 's')
                {
                    printf("Opçao 1 selecionada - Media do Vetor1\n");
                    resetArrays(intCounter,intArray2,fltArray3);
                    continue;
                }else if (chrOptionConfirm == 'n')
                {
                    printf("Obrigado pela sua escolha, volte sempre\n");
                    printMenu();
                    scanf(" %c",&chrMenuOption);
                    break;
                }
            case '2':
                printf("Opçao 2 selecionada - Imprimir Vetor1 pela ordem inversa\n\n");

                for (intCounter2 = 0, intCounter = 10; intCounter2 < 10; --intCounter, intCounter2++)
                {
                    intArray2[intCounter2] = intArrayUser[intCounter - 1];
                    printf("%d; ", intArray2[intCounter2]);
                }

                printf("\nDeseja continuar na Opçao 2? (s ou n): ");
                scanf(" %c",&chrOptionConfirm);
                chrOptionConfirm = tolower(chrOptionConfirm);
                if(chrOptionConfirm == 's')
                {
                    printf("Opçao 2 selecionada - Imprimir Vetor1 pela ordem inversa\n");
                    resetArrays(intCounter,intArray2,fltArray3);
                    continue;
                }else if (chrOptionConfirm == 'n')
                {
                    printf("Obrigado pela sua escolha, volte sempre\n");
                    printMenu();
                    scanf(" %c",&chrMenuOption);
                    break;
                }
            case '3':
                printf("Opçao 3 selecionada - Imprimir o Vetor1, mas primeiro impreme os numeros impares e so depois os pare");

                intCounter2 = 0;
                for(intCounter = 0; intCounter < 10; intCounter++)
                {
                    if(intArrayUser[intCounter] % 2 != 0)
                    {
                        intArray2[intCounter2] = intArrayUser[intCounter];
                        intCounter2++;
                    }else
                    {
                        intArray2[intCounter2] = intArrayUser[intCounter];
                        intCounter2++;
                    }
                    printf("%d; ",intArray2[intCounter]);
                }

                printf("Deseja continuar na Opçao 3? (s ou n): ");
                scanf(" %c",&chrOptionConfirm);
                chrOptionConfirm = tolower(chrOptionConfirm);
                if(chrOptionConfirm == 's')
                {
                    printf("Opçao 3 selecionada - Imprimir o Vetor1, mas primeiro impreme os numeros impares e so depois os pare");
                    resetArrays(intCounter,intArray2,fltArray3);
                    break;
                }else if (chrOptionConfirm == 'n')
                {
                    printf("Obrigado pela sua escolha, volte sempre");
                    printMenu();
                    scanf(" %c",&chrMenuOption);
                    break;
                }
            case '4':
                printf("Opçao 4 selecionada - Media da diferença");


                printf("Deseja continuar na Opçao 4? (s ou n): ");
                scanf(" %c",&chrOptionConfirm);
                chrOptionConfirm = tolower(chrOptionConfirm);
                if(chrOptionConfirm == 's')
                {
                    printf("Opçao 4 selecionada - Media da diferença");
                    resetArrays(intCounter,intArray2,fltArray3);
                    break;
                }else if (chrOptionConfirm == 'n')
                {
                    printf("Obrigado pela sua escolha, volte sempre");
                    printMenu();
                    scanf(" %c",&chrMenuOption);
                    break;
                }
            case '5':
                printf("Opçao 5 selecionada - ");


                printf("Deseja continuar para a Opçao 5? (s ou n): ");
                scanf(" %c",&chrOptionConfirm);
                chrOptionConfirm = tolower(chrOptionConfirm);
                if(chrOptionConfirm == 's')
                {
                    printf("Opçao 5 selecionada - ");
                    resetArrays(intCounter,intArray2,fltArray3);
                    break;
                }else if (chrOptionConfirm == 'n')
                {
                    printf("Obrigado pela sua escolha, volte sempre");
                    printMenu();
                    scanf(" %c",&chrMenuOption);
                    break;
                }
            default:
                printf("Opçao invalida!\n");
                printMenu();
                scanf(" %c",&chrMenuOption);
                break;
        }
    }

}