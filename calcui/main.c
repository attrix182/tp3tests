#include <stdio.h>
#include <stdlib.h>
#include "op.h"

int main()
{
    float numero1;
    float numero2;
    char continuar='c';
    float suma;
    float resta;
    float division;
    float multiplicacion;
    double factorialA;
    double factorialB;
    char opcion;

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||             CALCULADORA               ||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    fflush(stdin);
    printf("presione c para continuar:  ");
    scanf("%c", &continuar);

    while(continuar == 'c')
    {
        printf("\nIngresar primer numero: ");
        scanf("%f",&numero1);
        printf("\nIngresar segundo numero: ");
        scanf("%f",&numero2);
        printf("si desea hacer una suma presione:(a)\n");
        printf("si desea hacer una resta presione:(b)\n");
        printf("si desea hacer una division presione:(c)\n");
        printf("si desea hacer una multiplicacion presione:(d)\n");
        printf("si desea hacer un factorial presione:(e)\n");
        printf("si desea salir presione:(s)\n");

        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
        case 'a':
            suma=sumar(numero1,numero2);
            printf("la suma de %f + %f da un resultado de: %f", numero1,numero2,suma);
            break;

        case 'b':
            resta=restar(numero1,numero2);
            printf("la resta de %f - %f da un resultado de: %f", numero1,numero2,resta);
            break;

        case 'c':
            multiplicacion=multiplicar(numero1,numero2);
            printf("la multiplicacion de %f * %f da un resultado de: %f", numero1,numero2,multiplicacion);
            break;

        case 'd':
            division=dividir(numero1,numero2);
            printf("la division de %f / %f da como resultado de: %f", numero1,numero2,division);
            if(numero2==0)
            {
                printf("ERROR\n");
            }

            break;

        case 'e':
            if (numero1 >=0)
            {
                factorialA = factorial(numero1);
                printf("el factorial de: %f es: %.2f \n",numero1,factorialA);
            }

            else
            {
                printf("no se puede sacar factorial de: %f porque es un numero negativo\n",numero1);
            }

            if (numero2 >=0)
            {
                factorialB = factorial(numero2);
                printf("el factorial de: %f es: %.2f \n",numero2,factorialB);
            }
            else
            {
                printf("no se puede sacar factorial de: %f porque es un numero negativo\n",numero2);
            }
            break;
        case 's':
            printf("usted salio!\n");
            break;
        default:
            printf("Opcion incorrecta!\n");

        }
    }

    return 0;
}
