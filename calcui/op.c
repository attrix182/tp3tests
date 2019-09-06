#include "op.h"

float sumar(float a, float b)
{
    float  resultado;
    resultado  = a + b;

    return resultado;
}

float restar (float a,float b)
{
    float resultado;
    resultado= a-b;

    return resultado;
}

float multiplicar (float a,float b)
{
    float resultado;
    resultado= a*b;

    return resultado;
}

float dividir (float a,float b)
{
    float resultado;
    resultado= a/b;

    return resultado;

}
double factorial(double a)
{

    double resultado;

    if (a == 0)
    {
        resultado = 1;
    }

    else
    {
        resultado = a* factorial(a-1);
    }
    return resultado;
}


