#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funcionesGet.h"


// ---------------- GETS ----------------
int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}


char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}


float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);

  //  gets(input);
}


